#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cmath>

#include <gmpxx.h>
#include <gmp.h>
#define Integer mpz_class

using namespace std;

bool debug = false;

#define varIn(__Var, __Type) cin >> __Var; if (debug) cerr << #__Var ":" #__Type " = " << __Var << "\n";
#define defVar(__Var, __Type) __Type __Var; varIn(__Var, __Type)

#define vectorIn(__Var, __Type) { int i, n; cin >> n; __Var.resize(n); for (i = 0; i < n; ++i) cin >> __Var[i]; if (debug) { cerr << #__Var ":vector(" << n << ") ="; for (vector<__Type>::iterator it = __Var.begin(); it != __Var.end(); ++it) cerr << " " << *it; cerr << "\n"; } }
#define defVector(__Var, __Type) vector<__Type> __Var; vectorIn(__Var, __Type)

#define listIn(__Var, __Type) { int i, n; cin >> n; __Var.clear(); __Type obj; for (i = 0; i < n; ++i) { cin >> obj; __Var.push_back(obj); } if (debug) { cerr << #__Var ":list(" << n << ") ="; for (list<__Type>::iterator it = __Var.begin(); it != __Var.end(); ++it) cerr << " " << *it; cerr << "\n"; } }
#define defList(__Var, __Type) list<__Type> __Var; listIn(__Var, __Type)

#define setIn(__Var, __Type) { int i, n; cin >> n; __Var.clear(); __Type obj; for (i = 0; i < n; ++i) { cin >> obj; __Var.insert(obj); } if (debug) { cerr << #__Var ":set(" << n << ") ="; for (set<__Type>::iterator it = __Var.begin(); it != __Var.end(); ++it) cerr << " " << *it; cerr << "\n"; } }
#define defSet(__Var, __Type) set<__Type> __Var; setIn(__Var, __Type)

#define multisetIn(__Var, __Type) { int i, n; cin >> n; __Var.clear(); __Type obj; for (i = 0; i < n; ++i) { cin >> obj; __Var.insert(obj); } if (debug) { cerr << #__Var ":multiset(" << n << ") ="; for (multiset<__Type>::iterator it = __Var.begin(); it != __Var.end(); ++it) cerr << " " << *it; cerr << "\n"; } }
#define defMultiset(__Var, __Type) multiset<__Type> __Var; multisetIn(__Var, __Type)

//==============================================================

int x0 = 1000;

int main(void) {
  int iTest, nTests; cin >> nTests;

  for (iTest = 1; iTest <= nTests; ++iTest) {
    cerr << iTest << "/" << nTests << "\n";

    defVar(N, int);

    vector<int> day0(N), nAttacks(N), A0(N), B0(N), S0(N), delDay(N), delX(N), delS(N);
    vector<bool> dead(N, false);
    int i;
    for (i = 0; i < N; ++i)
      cin >> day0[i] >> nAttacks[i] >> A0[i] >> B0[i] >> S0[i] >> delDay[i] >> delX[i] >> delS[i];

    vector<Integer> heights[2];
    heights[0].resize(2000, 0);
    heights[1].resize(2000, 0);
    int nSuccess = 0;

    int nDead = 0;
    int counter = 0;
    for (int d = 0; d < 676060 && nDead < N; ++d) {
      bool attackedToday = false;
      vector<Integer> &oldHeights(heights[counter&1]), &newHeights(heights[1^(counter&1)]);
      // newHeights = oldHeights;
      for (i = 0; i < N; ++i) if (!dead[i]) {
	if (d < day0[i] || (d-day0[i])%delDay[i]) continue;
	int n = (d-day0[i])/delDay[i];
	if (n >= nAttacks[i]) {
	  if (!dead[i]) {
	    dead[i] = true;
	    ++nDead;
	  }
	  continue;
	}
	if (!attackedToday) {
	  attackedToday = true;
	  newHeights = oldHeights;
	  ++counter;
	}
        int x, A = A0[i] + n*delX[i], B = B0[i] + n*delX[i], S = S0[i] + n*delS[i];
	bool success = false;
	for (x = A; x < B; ++x) {
	  if (x0+x < 0 || x0+x > 2000) cerr << "x0+x = " << x0+x << "\n";
	  if (oldHeights[x0+x] < S) { 
	    if (debug) cerr << "On day " << d << ", tribe " << (i+1) << " succeeds\n";
	    success = true;
	    break;
	  }
	}
	if (success) {
	  ++nSuccess;
	  for (x = A; x < B; ++x)
	    if (newHeights[x0+x] < S)
	      newHeights[x0+x] = S;
	}
      }

    }

    cout << "Case #" << iTest << ": ";

    cout << nSuccess;

    cout << "\n";
  }

  return 0;
}
