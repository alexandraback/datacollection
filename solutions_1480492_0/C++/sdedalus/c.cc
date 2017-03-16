#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <queue>
#include <cstring>
using namespace std;

#define loop(i,n) for (int i = 0; i < (int)(n); ++i)
#define Bounded(x,a,b) ((a) <= (x) && (x) <= (b))
#define db(x) #x << " = " << x
#define pdb(x) printf("#x = %d\n",x);
#define All(x) x.begin(),x.end()
#define sz(x) x.size()
typedef vector<int> Vi;
typedef pair<int,int> Pii;
typedef vector<Vi> Adj;
typedef vector<bool> Vb;
typedef pair<double, double> Pdd;

#define dprintf false && printf

void solve(int casenum) {
  int N; cin >> N;
  vector<int> C(N);
  vector<double> S(N), P(N);
  char Lane[2] = {'L', 'R'};
  loop(i,N) {
    char c; cin >> c >> S[i] >> P[i];
    C[i] = (c=='R');
  }

  double CollisionTime = 0.0;
  bool Possible = false;
  double time = 0.0;
  int xeno_car = -1;

  const double epsilon = 1.0 / *max_element(All(S));

  dprintf("================================================================================% 3d\n", casenum);

  while (true) {
    // time is the current time
    // Check if possible
    vector< vector< pair<double, int> > > cars(2);
    loop(i,N)
      cars[C[i]].push_back(Pdd(P[i] + time * S[i], i));
    loop(i,2)
      sort(All(cars[i]));
    Possible = true;
    loop(k,2) {
      for (int i = 0; Possible && i < cars[k].size()-1; ++i) {
        Possible = Possible
          && fabs(cars[k][i].first - cars[k][i+1].first) > 5.0 - epsilon
          && S[cars[k][i].second] <= S[cars[k][i+1].second];
        if (!Possible) {
          dprintf("Expecting (lane %c), (cars %d %d)\n", Lane[k], cars[k][i].second, cars[k][i+1].second);
        }
      }
    }
    if (Possible) break;

    // Find the next collision time, the lane and the car index
    // the cars colliding will be cars[cL][cI] and cars[cL][cI+1];
    vector< pair<double, int> > collisions(2, pair<double,int>(1e300, -1));
    loop(k,2) {
      loop(i, cars[k].size()-1) {
        double p1 = cars[k][i].first, p2 = cars[k][i+1].first,
          s1 = S[cars[k][i].second], s2 = S[cars[k][i+1].second];
        double t = (p2-p1-5.)/(s1-s2);
        assert(p2 > p1);
        assert(p2-p1-5. > 0. - epsilon);
        dprintf("(Lane %c) (Cars %d %d) %f, %f, %f, %f, %f\n", Lane[k], cars[k][i].second, cars[k][i+1].second, p1, s1, p2, s2, t);
        if (s1 != s2 && t >= 0)
          collisions[k] = min(collisions[k], pair<double, int>(t, i));
      }
    }
    int cL = collisions[0].first > collisions[1].first;
    int cI = collisions[cL].second;

    if (cI == -1) {
      fprintf(stderr, "Warning: no collisions here.\n");
      //assert(false);
      break;
    }

    dprintf("Next collision on lane %c at dt %f; cars (%d,%d).\n", Lane[cL], collisions[cL].first, cars[cL][cI].second, cars[cL][cI+1].second);

    double dt = collisions[cL].first;
    loop(k,2) loop(i,cars[k].size()) cars[k][i].first += dt * S[cars[k][i].second];
    if (!(fabs(fabs(cars[cL][cI].first - cars[cL][cI+1].first) - 5.0) < epsilon)) {
      fprintf(stderr, "Warning: colliding cars not colliding (%g).\n",
              fabs(fabs(cars[cL][cI].first - cars[cL][cI+1].first) - 5.0));
      //assert(false);
    }

    time += dt;

    if (dt < 1e-13) {
      if (xeno_car == cars[cL][cI].second) {
        fflush(stdout); fflush(stderr);
        //fprintf(stderr, "Warning: Xeno cars (dt %g) (xeno_car %d)\n", dt, xeno_car);
        Possible = false;
        break;
      }
      xeno_car = cars[cL][cI].second;
      // assert(false);
      // Possible = false;
      // break;
    } else {
      xeno_car = -1;
    }

    int cO = 1-cL; // other lane
    bool change = true;
    loop(i,cars[cO].size())
      change = change && fabs(cars[cO][i].first - cars[cL][cI].first) > 5.0-epsilon;

    if (!change) { // collision
      dprintf("Cannot change lanes\n");
      break;
    }

    // change lane
    C[cars[cL][cI].second] = 1 - C[cars[cL][cI].second];
    dprintf("Time %f: car %d changes lane to %c.\n", time+dt, cars[cL][cI].second, Lane[C[cars[cL][cI].second]]);
  }

  if (Possible)
    printf("Case #%d: Possible\n", casenum);
  else
    printf("Case #%d: %.15f\n", casenum, time);
}

int main() {
  int T; cin >> T;
  loop(i,T) solve(i+1);
  return 0;
}

