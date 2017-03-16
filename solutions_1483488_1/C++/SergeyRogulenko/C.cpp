#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int get (int a) {
	int res = 0;
	while (a) {
		res ++;
		a /= 10;
	}
	return res;
}

int A[20];
int h;

int calc () {
	int a, b;
	cin >> a >> b;
	int len = get (a);
	int ans = 0;
	int f = 1;
	forn (i, len-1)
		f *= 10;
	for (int i = a; i <= b; i ++) {
		int v = i;
		h = 1;
		A[0] = v;
		forn (j, len-1) {
			v = f * (v % 10) + v / 10; 
			bool ok = 1;
			forn (k, h)
				if (A[k] == v)
					ok = 0;
			if (!ok)
				break;
			if (v >= a && v < i) {
				ans ++;
				A[h] = v;
				h ++;
			}
		}		
	}	
	return ans;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	for (int ii = 1; ii <= tt; ii ++) {
		printf ("Case #%d: ", ii);
		cout << calc() << endl;
	}
	return 0;
}
