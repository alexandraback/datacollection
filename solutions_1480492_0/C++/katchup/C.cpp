/*
	GOOGLE CODE JAM
	Contestant 			: Alex "katchup" AUVOLAT
	Contest reference	: Code Jam 2012 round 1A
	Problem				: C. Cruise Control
*/



#include <iostream>
#include <set>
#include <string>

using namespace std;

#define CARSIZE 5.0
#define LEFT 1
#define RIGHT 0
#define OTHER(x) (1-x)

struct Car {
	float Pos, Speed;
	int Lane;

	int move() {
		Lane = OTHER(Lane);
		return Lane;
	}

	bool operator < (const Car &other) {
		return Pos < other.Pos;
	}
};

class CarCompare {
	public:
	CarCompare() {}

	bool operator () (Car *a, Car *b) {
		return a->Pos < b->Pos;
	}
};

struct PbData {
	int N;
	multiset<Car*, CarCompare> Lane[2];

	void dump() {
		for (int i = 0; i <= 1; i++) {
			cerr << endl << "Lane  " << i << ": ";
			for (auto it = Lane[i].begin(); it != Lane[i].end(); it++) {
				cerr<< "  (" << (*it)->Pos << "," << (*it)->Speed << ")  ";
			}
		}
	}

	void moveCars(float dt) {
		for (int i = 0; i <= 1; i++) {
			for (auto it = Lane[i].begin(); it != Lane[i].end(); it++) {
				Car *car = *it;
				car->Pos += car->Speed * dt;
			}
		}
	}

	void solve2() {
		float t = 0;
		auto problem_car = Lane[0].end();

		while (true) {
			float dt = 0;
			// Look for car crashes - if we have none, then that's fine
			for (int i = 0; i <= 1; i++) {
				for (auto it = Lane[i].begin(); it != Lane[i].end(); it++) {
					auto next = it; next++;
					if (next == Lane[i].end()) break;
					Car *car = *it, *nextCar = *next;
					if (car->Speed > nextCar->Speed) {
						float case_dt = (nextCar->Pos - (car->Pos + CARSIZE)) / (car->Speed - nextCar->Speed);
						if (case_dt < 0) cerr << "FAIL1" << endl;
						if (case_dt < dt || dt == 0) {
							dt = case_dt;
							problem_car = it;
						}
					}
				}
			}
			if (dt == 0) break;	// no problem from now on
			float best_f_t = t + dt;
			// Look for cars that are in front of a slower car, on the other lane
			for (int l = 0; l <= 1; l++) {
				for (auto it = Lane[l].begin(); it != Lane[l].end(); it++) {
					Car *car = *it;
					auto firstO = Lane[OTHER(l)].lower_bound(car);
					while (firstO != Lane[OTHER(l)].end() && (*firstO)->Pos + dt*(*firstO)->Speed + CARSIZE <= car->Pos + dt*car->Speed) {
						Car *nextCar = *firstO;
						if (nextCar->Speed <= car->Speed) {
							float n_dt = (nextCar->Pos + CARSIZE - car->Pos) / (car->Speed - nextCar->Speed);
							if (n_dt <= dt) {
								problem_car = it;
								dt = n_dt;
							} else {
								cerr << "FORMULA FAIL" << endl;
							}
							break;
						}
						firstO++;
					}
				}
			}
			if (dt == 0) {
				cerr << t;
				return;
			}
			//cerr << endl << " * Problem at " << t << " + " << dt << " = " << (t + dt) << "\t\t";
			t = t + dt;
			// Move cars
			moveCars(dt);

			//dump();

			// Handle problem
			Car *pbCar = *problem_car;
			int lane = pbCar->Lane;
			int newLane = pbCar->move();
			Lane[lane].erase(problem_car);
			Lane[newLane].insert(pbCar);
			bool newLaneOk = true;
			for (auto it = Lane[newLane].begin(); it != Lane[newLane].end(); it++) {
				auto next = it; next++;
				if (next == Lane[newLane].end()) break;
				Car *car = *it, *nextCar = *next;
				if (car->Pos + CARSIZE > nextCar->Pos || (car->Pos + CARSIZE == nextCar->Pos && car->Speed > nextCar->Speed)) {
					newLaneOk = false;
					break;
				}
			}
			if (!newLaneOk) {
				cout << best_f_t;
				return;
			}
		}
		cout << "Possible";
	}

	void solve1() {
		float t = 0;
		auto problem_car = Lane[0].end();

		while (true) {
			float dt = 0;
			for (int i = 0; i <= 1; i++) {
				for (auto it = Lane[i].begin(); it != Lane[i].end(); it++) {
					auto next = it; next++;
					if (next == Lane[i].end()) break;
					Car *car = *it, *nextCar = *next;
					if (car->Speed > nextCar->Speed) {
						float case_dt = (nextCar->Pos - (car->Pos + CARSIZE)) / (car->Speed - nextCar->Speed);
						if (case_dt < 0) cerr << "FAIL1" << endl;
						if (case_dt < dt || dt == 0) {
							dt = case_dt;
							problem_car = it;
						}
					}
				}
			}
			if (dt == 0) break;	// no problem from now on
			cerr << endl << " * Problem at " << t << " + " << dt << " = " << (t + dt) << "\t\t";
			t = t + dt;
			// Move cars
			moveCars(dt);

			dump();

			// Handle problem
			Car *pbCar = *problem_car;
			int lane = pbCar->Lane;
			int newLane = pbCar->move();
			Lane[lane].erase(problem_car);
			Lane[newLane].insert(pbCar);
			bool newLaneOk = true;
			for (auto it = Lane[newLane].begin(); it != Lane[newLane].end(); it++) {
				auto next = it; next++;
				if (next == Lane[newLane].end()) break;
				Car *car = *it, *nextCar = *next;
				if (car->Pos + CARSIZE > nextCar->Pos || (car->Pos + CARSIZE == nextCar->Pos && car->Speed > nextCar->Speed)) {
					newLaneOk = false;
					break;
				}
			}
			if (!newLaneOk) {
				cout << t;
				return;
			}
		}
		cout << "Possible";
	}
};

void one_case() {
	PbData data;
	cin >> data.N;
	for (int i = 0; i < data.N; i++) {
		string tmp;
		cin >> tmp;
		Car *c = new Car;
		c->Lane = (tmp == "L" ? LEFT : RIGHT);
		cin >> c->Speed;
		cin >> c->Pos;
		data.Lane[c->Lane].insert(c);
	}

	// dump problem data
	//data.dump();

	// solve problem
	data.solve2();
}

int main(int argc, char *argv[]) {

	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cout << "Case #" << (i+1) << ": ";
		one_case();
		cout << endl;
	}

	return 0;
}

