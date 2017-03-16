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
typedef long double ld;
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

const int maxn = 1050;
int a[maxn], b[maxn];
int p[maxn];
int w[maxn];

int main()
{
   freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   int i, n, t, v, tt, cur, ans, j, q;
	cin >> tt;
	bool ok;
	forn (t, tt)
	{
		cin >> n;
		forn (i, n)
			cin >> a[i] >> b[i];
		ans = maxn * 100;
		q = 0;
		cur = 0;
		forn (i, n)
			w[i] = 0;
		ok = true;
		while (true)
		{
			v = -1;
			forn (i, n)
				if (cur >= b[i] && w[i] == 0)
				{
					v = i;
					break;
				}
			if (v != -1)
			{
				cur+=2;
				w[v] = 2;
				q++;
				continue;
			}
			forn (i, n)
				if (cur >= b[i] && w[i] == 1)
				{
					v = i;
					break;
				}
			if (v != -1)
			{
				cur++;
				w[v] = 2;
				q++;
				continue;
			}
			
			int mx = -1;
			forn (i, n)
				if (cur >= a[i] && w[i] == 0)
				{
					mx = max(mx, b[i]);
				}
			forn (i, n)
				if (cur >= a[i] && mx == b[i] && w[i] == 0)
				{
					v = i;
					break;
				}
			if (v != -1)
			{
				cur++;
				w[v] = 1;
				q++;
				continue;
			}
			else
				break;
		}

		forn (i, n)
			if (w[i] != 2)
				ok = false;
		
		if (!ok)
			cout << "Case #" << t + 1 << ": " << "Too Bad" << endl;
		else
			cout << "Case #" << t + 1 << ": " << q << endl;
	}
	return 0;
}
