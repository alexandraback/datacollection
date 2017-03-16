#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cmath>
// #include "Rational.h"

/*
// !!! Don't forget to canonicalize() Rational's after input!
#include <gmpxx.h>
#include <gmp.h>
#define Integer mpz_class
#define Rational mpq_class
#define Float mpf_class
*/


using namespace std;

bool debug = false; 

int main(void) {
  int iTest, nTests; cin >> nTests;

  for (iTest = 1; iTest <= nTests; ++iTest) {
    cerr << iTest << "/" << nTests << "\n";

    bool ridiculous = false;
    vector<int> counts(101, 0);
    int N, M, i, j;
    cin >> N >> M;
    if (debug) cerr << N << " " << M << "\n";
    vector< vector<int> > yard(N);
    for (i = 0; i < N; ++i) {
      yard[i].resize(M, 100);
      for (j = 0; j < M; ++j) { 
	cin >> yard[i][j];
	if (debug) cerr << yard[i][j] << " ";
	if (yard[i][j] > 100) ridiculous = true;
	++counts[yard[i][j]];
      }
      if (debug) cerr << "\n";
    }

    if (debug) {
      for (i = 0; i < 5; ++i)
	cerr << counts[i] << " ";
      cerr << "\n";
    }
    
    int h = 1;
    while (h < 100) {
      if (ridiculous) break;
      if (!counts[h]) { ++h; continue; }
      
      if (debug) cerr << "h = " << h << "\n"; 


    if (debug) {
      for (i = 0; i < 5; ++i)
	cerr << counts[i] << " ";
      cerr << "\n";
      for (i = 0; i < N; ++i) {
	for (j = 0; j < M; ++j)
	  cerr << yard[i][j] << " ";
	cerr << "\n";
      }
    }

      int i0, j0;
      bool found = false;
      for (i = 0; !found && i < N; ++i)
	for (j = 0; j < M; ++j) 
	  if (yard[i][j]==h) {
	    i0 = i; j0 = j; found = true;
	    break;
	  }
      if (!found) {
	for (j = 0; !found && j < M; ++j) 
	  for (i = 0; i < N; ++i)
	    if (yard[i][j]==h) {
	      i0 = i; j0 = j; found = true;
	      break;
	    }
      } 
      if (!found) break;
      
      if (debug) cerr << "found at " << i0 << "-" << j0 << "\n";

      int iDel, jDel;
      bool ok = false;
      for (iDel = -1; !ok && iDel <= 1; ++iDel)
	for (jDel = -1; !ok && jDel <= 1; ++jDel)
	  if (iDel==0 ^ jDel==0) {
	    bool bad = false;
	    i = i0; j = j0;
	    while (i >=0 && j >= 0 && i < N && j < M) {
	      if (yard[i][j] > h) {
		bad = true; break;
	      } else
		i += iDel; j += jDel;
	    }

	    i = i0; j = j0;
	    while (i >=0 && j >= 0 && i < N && j < M) {
	      if (yard[i][j] > h) {
		bad = true; break;
	      } else
		i -= iDel; j -= jDel;
	    }

	    if (!bad) {
	      if (debug) cerr << "ok\n";

	      ok = true;
	      i = i0; j = j0;
	      while (i >=0 && j >= 0 && i < N && j < M) {
		if (yard[i][j]==h) { --counts[h]; yard[i][j] = 0; }
		i += iDel; j += jDel;
	      }

	      i = i0; j = j0;
	      i -= iDel; j -= jDel;
	      while (i >=0 && j >= 0 && i < N && j < M) {
		if (yard[i][j]==h) { --counts[h]; yard[i][j] = 0; }
		i -= iDel; j -= jDel;
	      }
	    }
	  }
   
      if (!ok) break;
    }

    cout << "Case #" << iTest << ": ";

    if (h < 100) cout << "NO"; else cout << "YES";

    cout << "\n";
  }

  return 0;
}
