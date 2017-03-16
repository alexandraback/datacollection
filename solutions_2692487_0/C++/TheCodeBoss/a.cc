/*
  Google Code Jam 2013
  Round 1B, Problem A
  Coded by Michael Oliver
*/
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;

void solver(int &moteSize, multiset<int> &motes) {
	while (motes.size() > 0) {
		if (*motes.begin() < moteSize) {
			//cout << "Ate " << *motes.begin() << endl;
			moteSize += *motes.begin();
			motes.erase(motes.begin());
		} else break;
	}
}

int repeatAdder(int moteSize, multiset<int> motes) {
	if (moteSize == 1) return -1;
	int numOps = 0;
	while (motes.size() > 0) {
		numOps++;
		motes.insert(moteSize-1);
		solver(moteSize, motes);
	}
	return numOps;
}

void eraseEnd(multiset<int> &motes) {
	multiset<int>::iterator end = motes.end();
	end--;
	motes.erase(end);
}

int main() {
	int num_cases;
	cin >> num_cases;
	for (int i=1; i <= num_cases; i++) {
		int moteSize, numMotes;
		multiset<int> motes;
		cin >> moteSize >> numMotes;
		for (int j=0; j < numMotes; j++) {
			int m;
			cin >> m;
			motes.insert(m);
		}
		
		// At this point all smaller motes have been removed
		int numOperations = 0;
		while (motes.size() >= 1) {
			// Remove all smaller motes
			solver(moteSize, motes);
			if (motes.size() == 0) break;
			else if (motes.size() == 1) {
				// If there's only one left, just remove it
				numOperations++;
				//cout << "Removed only" << endl;
				break;
			} else if (2*moteSize-1 > *motes.begin()) {
				// First mote can be removed by adding a mote
				numOperations++;
				motes.insert(moteSize-1);
				//cout << "Added a mote of size " << moteSize-1 << endl;
			} else {
				int add = repeatAdder(moteSize, motes);
				if (add < motes.size() && add != -1) {
					numOperations++;
					motes.insert(moteSize-1);
					//cout << "Adding was best option, size " << moteSize-1 << endl;
				} else {
					// Erase last element
					numOperations++;
					eraseEnd(motes);
					//cout << "Erased last element" << endl;
				}
			}
		}
		cout << "Case #" << i << ": " << numOperations << endl;
	}
	return 0;
}
