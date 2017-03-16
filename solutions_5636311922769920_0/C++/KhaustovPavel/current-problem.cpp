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
int64 m;
int n, k, s;
int64 prid;

void dfs(int64 x, int d, int sh)
{
	if (d == k) return;

	if (x < m)
		prid = x;
	else
		return;
	
	++sh;
	sh = min(sh, n - 1);
	dfs(x * static_cast<int64>(n) + static_cast<int64>(sh), d + 1, sh);
}

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
 
	cin >> nt;
	for (int tn = 1; tn <= nt; ++tn)
	{
		scanf("%d%d%d", &n, &k, &s);
		m = 1;
		for (int i = 0; i < k; ++i)
			m *= static_cast<int64>(n);
		if (s * k < n)
			printf("Case #%d: IMPOSSIBLE\n", tn);
		else
		{
			printf("Case #%d:", tn);
			for (int i = 0; i < n; i += k)
			{
				prid = static_cast<int64>(i);
				dfs(static_cast<int64>(i), 0, i);
				printf(" %lld", prid + 1);
			}
			printf("\n");
		}
	}

    return 0;
}