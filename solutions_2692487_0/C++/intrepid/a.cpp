#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <iterator>
using namespace std;

struct mote_t {
	int size;
	bool added;
};
typedef vector<mote_t> moteVector_t;

typedef vector<int> moteList_t;

int main(int /*argc*/, char **/*argv[]*/)
{
	int runs;
	cin >> runs;
	for (int run=1; run <= runs; ++run) {
		int me, numOthers;
		cin >> me >> numOthers;
		moteList_t others(numOthers);
		for (int i=0; i<numOthers; ++i) cin >> others[i];
		
		sort(others.begin(), others.end(), greater<int>());
		
		// Grow first
		while ( numOthers > 0 && me > others.back() ) {
			me += others.back();
			--numOthers;
			others.pop_back();
		}
		
		
		if ( me < 2 ) {
			cout << "Case #" << run << ": " << others.size() << "\n";
			continue;
		}
		
		// Add
		int numAdds = 0;
		moteVector_t realMotes;
		for (int i = 0; i<numOthers; ++i) {
			while ( me <= others.back() ) {
				mote_t addMote = { me - 1, true };
				realMotes.push_back(addMote);
				me += me - 1;
				++numAdds;
			}
			mote_t origMote = { others.back(), false };
			realMotes.push_back(origMote);
			me += others.back();
			others.pop_back();
		}
		
		// Subtract
		int bestScore = numAdds;
		int subScore = numAdds;
		for (int i = realMotes.size() - 1; i >= 0; --i) {
			if ( realMotes[i].added ) --subScore;
			else ++subScore;
			if ( subScore < bestScore) --bestScore;
		}
		
		cout << "Case #" << run << ": " << bestScore << "\n";
	}
	return 0;
}
