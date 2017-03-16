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

  vector< pair< list<int>, multiset<int> > > states(1 << 20);
  int iState0, iState;

  for (iTest = 1; iTest <= nTests; ++iTest) {
    cerr << iTest << "/" << nTests << "\n";

    int i, j, K, N; cin >> K >> N;

    if (debug) cerr << "Keys:";
    multiset<int> keys;
    for (i = 0; i < K; ++i) {
      int key; cin >> key;
      if (debug) cerr << " " << key;
      keys.insert(key);
    }
    if (debug) cerr << "\n";

    vector<int> chestOpeners(N);
    vector< multiset<int> > chestContents(N);
    for (i = 0; i < N; ++i) {
      cin >> chestOpeners[i];
      if (debug) cerr << "Chest " << (i+1) << " opens with key " << chestOpeners[i] << ", contains";
      int nKeys; cin >> nKeys;
      for (j = 0; j < nKeys; ++j) {
	int key; cin >> key;
	chestContents[i].insert(key);
	if (debug) cerr << " " << key;
      }
      if (debug) cerr << "\n";
    }

    int nStates = (1 << N);
    for (iState = 0; iState < nStates; ++iState) {
      states[iState].first.clear();
      states[iState].second.clear();
    }

    states[0].second = keys;

    for (int bitCount = 0; bitCount < N; ++bitCount) {
      for (iState0 = 0; iState0 < nStates; ++iState0) {
	int test = iState0, count = 0;

	while (test) {
	  if (test & 1) ++count;
	  test >>= 1;
	}
	if (count!=bitCount) continue;

	list<int> &chestList0 = states[iState0].first;
	multiset<int> &keySet0 = states[iState0].second;
	if (iState0!=0 && chestList0.empty()) continue;

	if (false && debug) {
	  cerr << "Chests";
	  for (list<int>::iterator iChest = chestList0.begin(); iChest != chestList0.end(); ++iChest)
	    cerr << " " << *iChest;
	  cerr << " with keys";
	  for (multiset<int>::iterator iKey = keySet0.begin(); iKey != keySet0.end(); ++iKey)
	    cerr << " " << *iKey;
	  cerr << ":\n";
	}

	for (int iChest = 0; iChest < N; ++iChest) 
	  if (!(iState0 & (1 << iChest))) {
	    iState = iState0 | (1 << iChest);
	    
	    list<int> &chestList = states[iState].first;
	    multiset<int> &keySet = states[iState].second;

	    if (!chestList.empty()) {
	      list<int>::iterator iOld, iNew;
	      for (iOld = chestList.begin(), iNew = chestList0.begin(); iNew != chestList0.end(); ++iOld, ++iNew)
		if (*iOld != *iNew) break;
	      if (iNew==chestList0.end()) cerr << "!!!\n" << flush;
	      if (*iOld < *iNew) continue;
	    }
	    if (keySet0.find(chestOpeners[iChest])==keySet0.end()) continue;
	    
	    if (false && debug) cerr << "   got to chest " << iChest << "\n";
	    chestList = chestList0; chestList.push_back(iChest);
	    keySet = keySet0; keySet.erase(keySet.find(chestOpeners[iChest])); keySet.insert(chestContents[iChest].begin(), chestContents[iChest].end());
	  }
      }
    }

    cout << "Case #" << iTest << ":";

    list<int> &chestList = states[nStates-1].first;
    if (!chestList.empty())
      for (list<int>::iterator it = chestList.begin(); it != chestList.end(); ++it)
	cout << " " << (*it)+1;
    else
      cout << " IMPOSSIBLE";

    cout << "\n";
  }


  return 0;
}
