#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <memory.h>
#include <ctime>
 
using namespace std;
 
#pragma comment(linker, "/STACK:128000000")
 
typedef pair<int, int> pii;
typedef long long int64;
typedef pair<int64, int64> pii64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<int,pii> piii;
typedef pair<int64,pii> piii64;
typedef pair<pii,pii> piiii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
typedef unsigned int uint;
 
#define y1 dsjfksdj_fks
#define y2 alksaad_sa
#define y0 _sdkfsjfs__
 
#define tm _dskfjskdfjksdf

int nt;
int n, k;
vi a;
set <vi> was;
vi ans;

inline void gen(int n, vi &a)
{
	a.clear();
	a.assign(n, 0);
	a[0] = a[n - 1] = 1;
	for (int i = 1; i + 1 < n; ++i)
		a[i] = (rand() & 1);
}

inline int get_mod(vi &a, int p, int md) 
{
	int n = static_cast<int>(a.size());
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		res *= p;
		res += a[i];
		res %= md;
	}
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
 
	srand(228);
	cin >> nt;
	for (int tn = 1; tn <= nt; ++tn)
	{
		was.clear();
		scanf("%d%d", &n, &k);
		printf("Case #%d:\n", tn);
		while (k)
		{
			gen(n, a);
			ans.clear();
			ans.assign(11, 0);
			int ok = 1;
			for (int d = 2; d < 11; ++d)
			{
				ans[d] = -1;
				for (int md = 2; md < 100; ++md)
				{
					if (!get_mod(a, d, md))
					{
						ans[d] = md;
						break;
					}
				}
				if (ans[d] == -1)
				{
					ok = 0;
					break;
				}
			}
			if (ok && !was.count(a))
			{
				was.insert(a);
				--k;
				cerr << static_cast<int>(was.size()) << endl;
				for (int i = 0; i < n; ++i)
					printf("%d", a[i]);
				for (int d = 2; d < 11; ++d)
					printf(" %d", ans[d]);
				printf("\n");
			}
		}
	}

    return 0;
}