// g++ v4.8.3
// Flags: -O2

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define forall(i,n) for(int i=0; i<(int)(n); i++)

template<class T, class T1, class T2> inline bool Within(T x, T1 xMin, T2 xMax)
    {return (x >= xMin && x <= xMax);}
template<class T, class T1> inline bool Within(T x, T1 xMax)
    {return (x >= 0 && x < xMax);}

typedef vector<int> IntVec;

bool GabrielWins(int X, int R, int C) {
    assert(Within(X, 1, 20));
    assert(Within(R, 1, 20));
    assert(Within(C, 1, 20));
    int S = R * C, mindim = min(R, C);
    if (S % X != 0)
	return false;
    if (X <= 2)
	return true;
    else if (X == 3)
	return mindim >= 2;
    else if (X == 4)
	return mindim >= 3;
    else if (X == 5)
	return mindim >= 3 && S != 15;
    else if (X == 6)
	return mindim >= 4;
    else {
	assert(X >= 7);
	return false;
    }
}

int main() {
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	int X, R, C;
	cin >> X >> R >> C;
	cout << "Case #" << iTask << ": "
	    << (GabrielWins(X, R, C) ? "GABRIEL" : "RICHARD") << endl;
    }
}
