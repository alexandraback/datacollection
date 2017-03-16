#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define forall(i,n) for(int i=0; i<(int)(n); i++)

typedef vector<int> IntVec;
typedef long long ll;
typedef unsigned long long ull;

template<class T, class T1, class T2> inline bool Within(T x, T1 xMin, T2 xMax)
    {return (x >= xMin && x <= xMax);}
template<class T, class T1> inline bool Within(T x, T1 xMax)
    {return (x >= 0 && x < xMax);}

template<class T> void PrintVec(const vector<T>& v, const char* s=NULL) {
    if (s)
	cout << s << ' ';
    forall (i, v.size())
	cout << v[i] << ' ';
    cout << endl;
}

template<class T> void PrintVec(const char* s, const vector<T>& v) {
    PrintVec(v, s);
}

inline ull pow2(int n) {assert(n>=0 && n<64); return (1ULL<<n);}

int main() {
    // cout << setprecision(10);
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	int nVer;
	ull nWays;
	cin >> nVer >> nWays;
	assert(nVer > 1 && nVer <= 50);
	cout << "Case #" << iTask << ": ";
	ull maxWays = pow2(nVer-2);
	if (nWays > maxWays) {
	    cout << "IMPOSSIBLE\n";
	    continue;
	}
	cout << "POSSIBLE\n";
	forall (i, nVer) {
	    forall (j, nVer-1)
		cout << (i<j);
	    if (i == nVer-1)
		cout << 0;
	    else if (nWays == maxWays)
		cout << 1;
	    else
		cout << ((nWays >> (i-1)) & 1);
	    cout << '\n';
	}
    }
}
