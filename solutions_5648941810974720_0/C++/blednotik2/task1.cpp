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
    // cout << setprecision(10);
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	string s;
	cin >> s;
	IntVec freq(256, 0);
	forall (i, s.size())
	    freq[s[i]]++;
	IntVec digs(10, 0);
	digs[0] = freq['Z']; // ZERO
	digs[2] = freq['W']; // TWO
	digs[4] = freq['U']; // FOUR
	digs[6] = freq['X']; // SIX
	digs[8] = freq['G']; // EIGHT
	digs[1] = freq['O'] - digs[0] - digs[2] - digs[4]; // ONE
	digs[3] = freq['R'] - digs[0] - digs[4]; // THREE
	digs[5] = freq['F'] - digs[4]; // FIVE
	digs[7] = freq['S'] - digs[6]; // SEVEN
	digs[9] = freq['I'] - digs[6] - digs[8] - digs[5]; // NINE
	cout << "Case #" << iTask << ": ";
	forall (i, 10)
	    forall (j, digs[i])
		cout << i;
	cout << '\n';
    }
}
