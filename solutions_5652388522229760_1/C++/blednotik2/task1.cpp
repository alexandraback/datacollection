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

int Digits(int num) {
    assert(num >= 0);
    if (num == 0)
	return 1;
    int flags = 0;
    while (num > 0) {
	flags |= (1 << (num % 10));
	num /= 10;
    }
    return flags;
}

int LoopLen(int num) {
    if (num == 0)
	return -1;
    int len = 0;
    int totflags = 0;
    int sum = num;
    while (totflags != 0x3ff) {
	totflags |= Digits(sum);
	// printf("sum=%d totflags=%03x\n", sum, totflags); fflush(stdout);
	sum += num;
	assert(sum > 0);
	len++;
    }
    return len;
}
	    
int main() {
    // cout << setprecision(10);
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	int num;
	cin >> num;
	cout << "Case #" << iTask << ": ";
	if (num == 0)
	    cout << "INSOMNIA\n";
	else
	    cout << num * LoopLen(num) << '\n';
    }
}
