#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>

#define InputVector(v, Type) vector<Type> v; { Type t; int _n; cin >> _n; v.reserve(_n); while (--_n >= 0) { cin >> t; v.push_back(t); } }

using namespace std;

bool debug = false;

int main(void) {
  int iTest, nTests; cin >> nTests;

  for (iTest = 1; iTest <= nTests; ++iTest) {
    cerr << iTest << "/" << nTests << "\n";

    InputVector(J, int);

    int i, j, n = J.size();

    double X = 0;
    for (i = 0; i < n; ++i) X += J[i];
    
    vector<double> alpha(n);
    for (i = 0; i < n; ++i) alpha[i] = J[i]/X;

    cout << "Case #" << iTest << ":";
   
    for (i = 0; i < n; ++i) {
      double P;

#if 1
      double pBad = 0.0, pGood = 1.0;
      
      while (pGood - pBad >= 0.0000001) {
	double pMid = (pBad + pGood)/2.0;
	
	bool good = false;
	double pTarget = alpha[i] + pMid;
	double pRemaining = 1.0 - pMid;
	for (j = 0; !good && j < n; ++j) 
	  if (j != i) {
	    if (alpha[j] + pRemaining < pTarget + 0.00000001)
	      good = true;
	    else if (pTarget >= alpha[j])
	      pRemaining -= pTarget - alpha[j];
	  }

	if (good)
	  pGood = pMid;
	else
	  pBad = pMid;
      }

      P = pBad*100.0;
#else
      P = 100.0*(2.0/n - alpha[i]);
      if (P < 0.0) P = 0.0;
#endif

      cout << " ";
      cout.precision(9);
      cout << P;
      // if (P==floor(P)) cout << ".0";
    }

    cout << "\n";
  }

  return 0;
}
