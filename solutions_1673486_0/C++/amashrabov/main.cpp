#pragma comment(linker, "/STACK:10000000")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric> 
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> T inline sqr(T x) { return x * x; }
template <class T> string str( T i ) { stringstream ss; ss << i; return ss.str(); }
int toint(string a) {istringstream is(a); int p; is>>p; return p;} 
long long toll(string a){istringstream is(a);long long p;is>>p;return p;} 

#define pb push_back
#define mp make_pair
#define e1 first 
#define e2 second 
#define sz size 

#define forn(i, n) for (i = 0; i < int(n); i++)
const ld pi = 3.1415926535897932384626433832795, eps = 1e-8;

int a, b;
ld r[10];
ld p[10];

ld del(int x)
{
	int i, j;
	ld v, add, res = x;
	forn (i, 1 << a)
	{
		v = 1.0;
		forn (j, a)
			if (i & (1 << j))
				v *= (1 - p[j]);
			else
				v *= p[j];
		bool ok = true;
		forn (j, a)
			if (i & (1 << j) && j <= a - 1 - x)
				ok = false;
		if (ok)
			add = v*(b - a + x + 1.0);
		else
			add = v*(b - a + x + 1.0 + b + 1.0);
		res += add;
	}
	return res;
}

int main()
{
   freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   int i, t, tt;
	cin >> tt;
	cout.precision(20);
	ld ans;
	
	forn (t, tt)
	{
		cin >> a >> b;
		forn (i, a)
			cin >> p[i];
		forn (i, a)
			r[i] = del(i);
		ans = 1.0 + b + 1;
		forn (i, a)
			ans = min(ans, r[i]);
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
	return 0;
}
