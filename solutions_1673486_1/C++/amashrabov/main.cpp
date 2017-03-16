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
ld r[100100];
ld p[100100];

int main()
{
   freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   int i, t, tt;
	cin >> tt;
	cout.precision(20);
	ld ans;
	cin.sync_with_stdio();
	ld x;
	forn (t, tt)
	{
		cin >> a >> b;
		forn (i, a)
			cin >> p[i];
		r[0] = p[0];
		for (i = 1; i < a; i++)
			r[i] = p[i] * r[i - 1]; 
		ans = 1.0 + b + 1;
		forn (i, a)
		{
			x = i;
			x += r[a - 1 - i] * (b - a + i + 1.0) + (1 - r[a - 1 - i]) * (b - a + i + 1.0 + b + 1.0);
			ans = min(ans, x);
		}
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
	return 0;
}
