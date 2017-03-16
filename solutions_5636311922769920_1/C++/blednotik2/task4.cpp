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

int main() {
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	unsigned K, C, S;
	cin >> K >> C >> S;
	cout << "Case #" << iTask << ":";
	if (S * C < K) {
	    cout << " IMPOSSIBLE\n";
	    continue;
	}
	/*
	if (S == K) {
	    forall (i, S) cout << ' ' << i+1;
	    cout << '\n';
	    continue;
	}
	*/
	unsigned digit = 0;
	forall (iTile, S) {
	    ull mul = 1, tile = 0;
	    forall (iDigit, C) {
		tile += digit * mul;
		mul *= K;
		digit++;
		if (digit >= K)
		    break;
	    }
	    cout << ' ' << tile + 1;
	    if (digit >= K)
		break;
	}
	cout << '\n';
    }
}
