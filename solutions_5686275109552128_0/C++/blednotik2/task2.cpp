// g++ v4.8.3
// Flags: -O2

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

#define forall(i,n) for(int i=0; i<(int)(n); i++)

template<class T, class T1, class T2> inline bool Within(T x, T1 xMin, T2 xMax)
    {return (x >= xMin && x <= xMax);}
template<class T, class T1> inline bool Within(T x, T1 xMax)
    {return (x >= 0 && x < xMax);}

typedef vector<int> IntVec;

int Solve(map<int, int>& hist) {
    int specials = 0, tMin = -1;
    while (true) {
	map<int, int>::iterator it = hist.end();
	it--;
	const int nPan = it->first, nDiners = it->second;
	assert(nPan > 0 && nDiners > 0);
	const int t = specials + nPan;
	if (tMin < 0 || t < tMin)
	    tMin = t;
	if (nPan == 1)
	    break;
	int half = nPan >> 1;
	hist.erase(it);
	hist[half] += nDiners;
	hist[nPan - half] += nDiners;
	specials += nDiners;
    }
    return tMin;
}

int main() {
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	int nDiners;
	cin >> nDiners;
	map<int, int> hist;
	forall (iDiner, nDiners) {
	    int nPan;
	    cin >> nPan;
	    hist[nPan]++;
	}
	cout << "Case #" << iTask << ": " << Solve(hist) << endl;
    }
}
