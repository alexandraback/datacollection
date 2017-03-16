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

#define Float double

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
int x0 = 42;
int space = '1';

struct ProfileSet {
  map< string, Float> probs;
  void addProfile(const string &profile, const Float &prob) {
    map<string, Float>::iterator iFound = probs.find(profile);
    if (iFound==probs.end())
      probs[profile] = prob;
    else
      iFound->second += prob;
  } 
  Float probFor(int x, int y) { 
    Float prob(0);
    map<string, Float>::iterator iProfile;
    for (iProfile = probs.begin(); iProfile != probs.end(); ++iProfile)
      if (iProfile->first[x+x0] > y+space)
	prob += iProfile->second;
    return prob;
  }

  void cascadeFrom(const string &profile0, const Float &prob0) {
    int i, x, n = profile0.length();

    int y = profile0[x0] + 1; // position of center!
    vector<Float> probs[2];
    probs[0].resize(n, Float(0.0));
    probs[1].resize(n, Float(0.0));

    probs[y & 1][x0] = prob0;
    while (y >= space) {
      vector<Float> &oldProbs = probs[y & 1], &newProbs = probs[1^(y & 1)];
      /*
      for (i = x0-3; i <= x0+3; ++i)
	cerr << " " << oldProbs[i];
      cerr << "\n";
      */
      for (i = 0; i < n; ++i) newProbs[i] = Float(0.0);

      for (x = 1; x < n-1; ++x) {
	if (profile0[x+1] >= y && profile0[x-1] >= y)
	  newProbs[x] += oldProbs[x];
	else if (profile0[x+1] >= y)
	  newProbs[x-1] += oldProbs[x];
	else if (profile0[x-1] >= y)
	  newProbs[x+1] += oldProbs[x];
	else {
	  newProbs[x-1] += Float(0.5)*oldProbs[x];
	  newProbs[x+1] += Float(0.5)*oldProbs[x];
	}      
      }
      --y;
    }

    vector<Float> &newProbs = probs[y & 1];
    for (i = 0; i < n; ++i) 
      if (newProbs[i] != Float(0.0)) {
	string profile = profile0; profile[i] += 2;
	addProfile(profile, newProbs[i]);
      }
  }
};

int main(void) {
  int i, N = 20;
  vector<ProfileSet> profiles(N+1);
  string profile0(2*x0+1, ' ');
  for (i = 0; i < profile0.length(); ++i)
    profile0[i] = (((i-x0)&1) ? space : space-1); 
  profiles[0].addProfile(profile0, Float(1.0));

  for (i = 1; i <= N; ++i) {
    ProfileSet &pS0 = profiles[i-1];
    ProfileSet &pSNew = profiles[i];
    for (map<string, Float>::iterator i0 = pS0.probs.begin(); i0 != pS0.probs.end(); ++i0)
      pSNew.cascadeFrom(i0->first, i0->second);

    cerr << "\n\n===" << i << "===\n";
    for (map<string, Float>::iterator iNew = pSNew.probs.begin(); iNew != pSNew.probs.end(); ++iNew)
      cerr << iNew->first.substr(x0-10, 21) << " " << iNew->second << "\n";
  }

  int iTest, nTests; cin >> nTests;

  for (iTest = 1; iTest <= nTests; ++iTest) {
    cerr << iTest << "/" << nTests << "\n";

    defVar(N, int);
    defVar(X, int);
    defVar(Y, int);

    cout << "Case #" << iTest << ": ";

    Float f = profiles[N].probFor(X, Y);
    cout << f;
    // cout << floor(f) << "." << Integer(floor((f-floor(f))*Float(100000000.0)));

    cout << "\n";
  }

  return 0;
}
