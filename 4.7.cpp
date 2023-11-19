#include <iostream>
#include <vector>
using namespace std;
// Forward declarations
class Address;

class Engine {
private:
    int horsepower;

public:
    Engine(int power) : horsepower(power) {}

    int getHorsepower() const {
        return horsepower;
    }
};

class Address {
private:
    string street;
    string city;

public:
    Address(const string& s, const string& c) : street(s), city(c) {}

   string getStreet() const {
        return street;
    }

    string getCity() const {
        return city;
    }
};

class Driver {
private:
    string name;

public:
    Driver(const string& n) : name(n) {}

    string getName() const {
        return name;
    }
};

class Commuter {
private:
    string name;

public:
    Commuter(const std::string& n) : name(n) {}

    string getName() const {
        return name;
    }
};

class Vehicle {
protected:
    Engine engine;

public:
    Vehicle(const Engine& e) : engine(e) {}

    Engine getEngine() const {
        return engine;
    }
};

class Car : public Vehicle {
private:
    Address address;

public:
    Car(const Engine& e, const Address& a) : Vehicle(e), address(a) {}

    Address getAddress() const {
        return address;
    }
};

class Bus : public Vehicle {
private:
    vector<Commuter> commuters;

public:
    Bus(const Engine& e) : Vehicle(e) {}

    void addCommuter(const Commuter& commuter) {
        commuters.push_back(commuter);
    }

    void printCommuters() const {
        cout << "Commuters on the bus:" << endl;
        for (const auto& commuter : commuters) {
            cout << commuter.getName() << endl;
        }
    }
};

class BusStation {
private:
    Address address;

public:
    BusStation(const Address& a) : address(a) {}

    Address getAddress() const {
        return address;
    }
};

int main() {
    // Example usage:
    Engine carEngine(200);
    Address carAddress("123 Main St", "Cityville");
    Car myCar(carEngine, carAddress);

    Engine busEngine(500);
    Bus myBus(busEngine);

    Commuter commuter1("Ale");
    Commuter commuter2("Alina");

    myBus.addCommuter(commuter1);
    myBus.addCommuter(commuter2);

    myBus.printCommuters();

    return 0;
}
