#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <climits>

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

typedef vector<string> StringVec;
typedef set<string> StringSet;

int SmallestExhaustive(
    const StringVec& vs1, const StringVec& vs2,
    StringSet& ss1, StringSet& ss2, 
    int i0, int len
) {
    if (ss1.empty() && ss2.empty())
	return 0;
    bool bFound1 = false, bFound2 = false;
    int imax = len - max(ss1.size(), ss2.size());
    while (true) {
	if (i0 > imax)
	    return 10*len+1;
	const string& w1 = vs1[i0];
	const string& w2 = vs2[i0];
	bFound1 = (ss1.find(w1) != ss1.end());
	bFound2 = (ss2.find(w2) != ss2.end());
	if (!bFound1 && !bFound2)
	    i0++;
	else
	    break;
    }
    const string& w1 = vs1[i0];
    const string& w2 = vs2[i0];
    int valWithout = SmallestExhaustive(vs1, vs2, ss1, ss2, i0+1, len);
    if (bFound1) ss1.erase(w1);
    if (bFound2) ss2.erase(w2);
    int valWith = SmallestExhaustive(vs1, vs2, ss1, ss2, i0+1, len) + 1;
    if (bFound1) ss1.insert(w1);
    if (bFound2) ss2.insert(w2);
    return min(valWithout, valWith);
}

int SmallestExhaustive(const StringVec& vs1, const StringVec& vs2) {
    assert(vs1.size() == vs2.size());
    StringSet ss1, ss2;
    forall (i, vs1.size()) {
	ss1.insert(vs1[i]);
	ss2.insert(vs2[i]);
    }
    return SmallestExhaustive(vs1, vs2, ss1, ss2, 0, vs1.size());
}

int main() {
    // cout << setprecision(10);
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	int n;
	cin >> n;
	StringVec v1(n), v2(n);
	forall (i, n)
	    cin >> v1[i] >> v2[i];
	cout << "Case #" << iTask << ": " << n-SmallestExhaustive(v1, v2) << '\n';
    }
}
