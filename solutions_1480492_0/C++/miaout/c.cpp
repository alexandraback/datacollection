#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long int int64;
typedef vector<int> VI;
typedef vector<double> VD;
#define REP(i,a,b) for (int i=int(a); i<int(b); ++i)
void unittest();

double now;

struct Car {
  double speed;
  double pos;
  bool right;

  bool nowRight;

  double nowPos() {
    return pos + speed * now;
  }
};

struct Encounter {
  int c1, c2;
  double t;
};

int N, E;
typedef vector<Car> VC;
VC cars;
typedef vector<Encounter> VE;
VE encounters;

double best;
bool possible;

const double EPS = 0.00000001;

bool bySpeed(const Car& c1, const Car& c2) {
  return c1.speed > c2.speed;
}

bool byTime(const Encounter& e1, const Encounter& e2) {
  return e1.t < e2.t;
}

void calcEncounters() {
  REP(i, 0, N-1) {
    const Car& c1 = cars[i]; // fast
    REP(j, 0, N) {
      const Car& c2 = cars[j]; // slow
      if (c1.speed<=c2.speed) continue;
      // p1 + 5 + v1*t = p2 + v2*5

      double t = (c2.pos - c1.pos - 5.0) / (c1.speed - c2.speed);
      // printf("calcEncounters (%d, %d) => %lf\n", i, j, t);
      if (t<0) continue;
      Encounter enc;
      enc.c1 = i;
      enc.c2 = j;
      enc.t = t;
      encounters.push_back(enc);
      // printf("%lf %lf %lf ENC\n", t, c1.pos, c2.pos);
    }
  }
}

bool valid(bool right) {
  REP(i, 0, N-1) {
    Car& c1 = cars[i]; // fast
    if (c1.nowRight!=right) continue;
    double pos1 = c1.nowPos();
    REP(j, i+1, N) {
      Car& c2 = cars[j]; // slow
      if (c2.nowRight!=right) continue;
      double pos2 = c2.nowPos();

      double dist = abs(pos1-pos2);
      bool invalid = false;
      if (dist<5+EPS) invalid = true;
      // else{
      //   if (c2.pos > c1.pos && dist < 5+EPS) {
      //     if (c1.speed>c2.speed) {
      //       invalid = true;
      //     }
      //   }
      // }
      if (invalid) {
        // printf("INVALID %lf %lf t=%lf\n", pos1, pos2, now);
        return false;
      }
    }
  }
  return true;

}

bool valid() {
  return valid(false) && valid(true);
}

void attempt(int mask) {
  REP(i, 0, N) {
    Car& c = cars[i];
    c.nowRight = c.right;
    // printf("****%d\n", c.nowRight);
  }
  // mask&(1<<c) => if true, fast choose right
  REP(i, 0, E) {
    const Encounter& enc = encounters[i];
    now = enc.t; // expose globally
    Car& c1 = cars[enc.c1]; // fast
    Car& c2 = cars[enc.c2]; // slow
    if (mask&(1<<i)) {
      c1.nowRight = true;
    } else {
      c1.nowRight = false;
    }
    c2.nowRight = !c1.nowRight;

    if (!valid()) {
      best = max(best, now);
      // printf("Attempt %d FINISHED => %.5lf\n", mask, now);
      return;
    }
  }
  // printf("MASK %d => Possible\n", mask);
  possible = true;
}

void solve(int caseNum) {
  cars.clear();
  encounters.clear();
  possible = false;
  best = -1;
  cin>>N;
  REP(i, 0, N) {
    Car car;
    string buf;
    cin>>buf>>car.speed>>car.pos;
    car.right = (buf=="R");
    // cout<<buf<<car.speed<<" "<<car.pos<<endl;
    cars.push_back(car);
  }

  sort(cars.begin(), cars.end(), bySpeed);
  // REP(i, 0, N) cout<<cars[i].speed<<" "; cout<<"\n";
  calcEncounters();
  sort(encounters.begin(), encounters.end(), byTime);
  E = encounters.size();
  if (0) {
    cout<<E<<" encounters\n";
    REP(i, 0, E) {
      cout<<encounters[i].t<<" "<<encounters[i].c1<<" "<<encounters[i].c2<<endl;
    }
  }

  REP(i, 0, 1<<E) {
    attempt(i);
    if (possible) break;
  }

  if (possible)
    printf("Case #%d: Possible\n", caseNum);
  else
    printf("Case #%d: %.10lf\n", caseNum, best);
  // exit(0);
}

int main() {
  unittest();

  int caseCount;
  cin>>caseCount;
  REP(i, 1, caseCount+1)
    solve(i);

  return 0;
}

void unittest() {
}

