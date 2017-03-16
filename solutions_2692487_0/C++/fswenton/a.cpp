#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cmath>

/*
// !!! Don't forget to canonicalize() Rational's after input!
#include <gmpxx.h>
#include <gmp.h>
#define Integer mpz_class
#define Rational mpq_class
#define Float mpf_class
  // mpf_set_default_prec(1000);
*/

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

  for (iTest = 1; iTest <= nTests; ++iTest) {
    cerr << iTest << "/" << nTests << "\n";

    defVar(A0, int);
    defVector(motes, int);
    sort(motes.begin(), motes.end());

    int i, N = motes.size();
    int maxBits = (1 << N); 
    int bestCost = N;
    for (int bits = 0; bits < maxBits; ++bits) {
      int count = 0;
      int A = A0;
      for (i = 0; i < N; ++i)
	if (A > motes[i])
	  A += motes[i];
	else {
	  if (bits & (1<<i))
	    ++count;
	  else {
	    if (A==1) 
	      count = N;
	    else {
	      while (A <= motes[i]) {
		A += A-1;
		++count;
	      }
	      A += motes[i];
	    }
	  }
	}
      if (count < bestCost) bestCost = count;
    }

    cout << "Case #" << iTest << ": ";

    cout << bestCost;

    cout << "\n";
  }

  return 0;
}
