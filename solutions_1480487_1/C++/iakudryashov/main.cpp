#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-10;
const int INF = 1000 * 1000 * 1000;

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int testCount;
	cin >> testCount;
	
	forn(test, testCount)
	{
		int n;
		scanf("%d", &n);
		
		vector <int> v(n);
		int sum = 0;
		
		forn(i, n)
			scanf("%d", &v[i]), sum += v[i];
			
		printf("Case #%d:", test + 1);
		
		forn(i, n)
		{
			ld lf = 0.0, rg = 1.0;
			
			forn(iter, 100)
			{
				ld mid = (lf + rg) / 2.0;
				
				ld val1 = ld(v[i]) + ld(sum) * mid;
				ld need = 0.0;
				
				forn(j, n)
					if (j != i)
						need += max(ld(0), (val1 - ld(v[j])) / ld(sum));
						
				if (1.0 - mid > need + EPS)
					lf = mid;
				else
					rg = mid;
			}
		
			printf(" %.7lf", double(rg * 100.0));
		}
			
		puts("");
	}

	return 0;
}
























































