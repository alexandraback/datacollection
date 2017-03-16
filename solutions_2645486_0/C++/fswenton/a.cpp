#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cmath>

// !!! Don't forget to canonicalize() Rational's after input!
#include <gmpxx.h>
#include <gmp.h>
#define Integer mpz_class
#define Rational mpq_class
#define Float mpf_class

using namespace std;

bool debug = true;

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

int main(void) {
  int iTest, nTests; cin >> nTests;

  vector<Integer> bestWithLeft[2];
  bestWithLeft[0].resize(11);
  bestWithLeft[1].resize(11, 0);

  for (iTest = 1; iTest <= nTests; ++iTest) {
    cerr << iTest << "/" << nTests << "\n";

    cout << "Case #" << iTest << ": ";

    defVar(EMax, int); 
    defVar(ERest, int);
    defVector(activityValues, int);

    Integer negOne(-1), zero(0);
    int iEnergyLeft;
    for (int i = 0; i <= EMax; ++i)
      bestWithLeft[0][i] = negOne;
    bestWithLeft[0][EMax] = 0;

    int minSpend = min(EMax, ERest);
    int iAct, nActs = activityValues.size();
    for (iAct = 0; iAct < nActs; ++iAct) {
      Integer baseValue(activityValues[iAct]);
      vector<Integer> &oldBest(bestWithLeft[iAct & 1]), &newBest(bestWithLeft[(iAct+1)&1]);
      for (iEnergyLeft = 0; iEnergyLeft <= EMax; ++iEnergyLeft) newBest[iEnergyLeft] = 0;
      for (iEnergyLeft = 0; iEnergyLeft <= EMax; ++iEnergyLeft) if (oldBest[iEnergyLeft] >= zero) {
	  Integer value(0);
	for (int iToSpend = 0; iToSpend <= iEnergyLeft; ++iToSpend, value += baseValue) {
	  int newEnergy = iEnergyLeft - iToSpend;
	  if (newEnergy < 0) break;
	  newEnergy += ERest;
	  if (newEnergy > EMax) newEnergy = EMax;
	  Integer newValue = oldBest[iEnergyLeft] + value;
	  if (newValue > newBest[newEnergy]) newBest[newEnergy] = newValue;
	}
      }
      if (debug) {
	for (int i = 0; i <= EMax; ++i)
	  cerr << newBest[i] << " ";
	cerr << "\n";
      }
    }

    Integer best(0);
    vector<Integer> &finalBest = bestWithLeft[iAct & 1];
    for (iEnergyLeft = 0; iEnergyLeft <= EMax; ++iEnergyLeft)
      if (finalBest[iEnergyLeft] > best) best = finalBest[iEnergyLeft];

    cout << best;
    cout << "\n";
  }

  return 0;
}
