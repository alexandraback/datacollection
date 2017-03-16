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

ull Transform(unsigned num, unsigned base) {
    ull sum = 0, mul = 1;
    while (num > 0) {
	if (num & 1)
	    sum += mul;
	num >>= 1;
	mul *= base;
    }
    return sum;
}

void PrintBin(unsigned x) {
    if (x == 0)
	return;
    PrintBin(x >> 1);
    cout << x % 2;
}

void PrintJamcoins(unsigned length, unsigned nJamcoins) {
    unsigned nBits=0;
    unsigned long temp=1;
    while (temp < nJamcoins) {
	temp <<= 1;
	nBits++;
    }
    const unsigned lenDivisor = nBits + 2;
    assert(length >= 2 * lenDivisor);
    for (unsigned i=0; i<nJamcoins; i++) {
	unsigned divisor = (1 << (lenDivisor - 1)) + (i << 1) + 1;
	unsigned jamcoin = divisor + (divisor << (length - lenDivisor));
	PrintBin(jamcoin);
	for (unsigned base=2; base<=10; base++)
	    cout << ' ' << Transform(divisor, base);
	cout << '\n';
    }
}
    

int main() {
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	int length, nJamcoins;
	cin >> length >> nJamcoins;
	cout << "Case #" << iTask << ":\n";
	PrintJamcoins(length, nJamcoins);
    }
}
