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

int main(void) {
  int iTest, nTests; cin >> nTests;

  for (iTest = 1; iTest <= nTests; ++iTest) {
    cerr << iTest << "/" << nTests << "\n";

    string vowels = "aeiou";
    defVar(name, string);
    defVar(minBlock, int);

    int i, n = name.length();
    
    vector<Integer> closedCounts(n+1, 0);
    vector<Integer> activeCounts(n+1, 0);
    int badStart = 0;
    int consonantRun = 0;
    for (i = 0; i < n; ++i) {
      closedCounts[i+1] = closedCounts[i] + activeCounts[i];
      activeCounts[i+1] = activeCounts[i];
      if (vowels.find(name[i])!=string::npos) // VOWEL
	consonantRun = 0;
      else {
	++consonantRun;
	if (consonantRun==minBlock) {
	  int nNew = (i-minBlock+1) - badStart + 1;
	  closedCounts[i+1] += nNew;
	  activeCounts[i+1] += nNew;
	  badStart = i-minBlock+2;
	} else if (consonantRun > minBlock) {
	  ++closedCounts[i+1];
	  ++activeCounts[i+1];
	  ++badStart;
	}
      }
       
      if (debug)
	cerr << closedCounts[i+1] << " " << activeCounts[i+1] << " " << consonantRun << " " << badStart << "\n";
    }

    cout << "Case #" << iTest << ": ";

    cout << closedCounts[n];

    cout << "\n";
  }

  return 0;
}
