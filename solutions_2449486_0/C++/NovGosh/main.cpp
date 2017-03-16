#include <cstdio>
#include <fstream>
#include <iostream>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <cstring>
#include <algorithm>

#include <ctime>
#include <cstdlib>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(A) (int) (A).size()

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(A) fputs((A), stderr)

#define sqr(A) ((A) * (A))
#define x first
#define y second
  
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;

const int N = (int) 1e2;

int t, n, m, a[N][N], res[N][N];

int main () 
{
    #ifdef DEBUG
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif

    cin >> t;
    for (int test = 0; test < t; test++) {
    	memset(res, 127, sizeof(res));

    	cin >> n >> m;
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < m; j++)
    			cin >> a[i][j];

		for (int i = 0; i < n; i++) {
			int max_val = -1;
			for (int j = 0; j < m; j++)
				max_val = max(max_val, a[i][j]);
			for (int j = 0; j < m; j++)
				res[i][j] = min(res[i][j], max_val);						
		}

		for (int i = 0; i < m; i++) {
			int max_val = -1;
			for (int j = 0; j < n; j++)
				max_val = max(max_val, a[j][i]);
			for (int j = 0; j < n; j++)
				res[j][i] = min(res[j][i], max_val);
		}

		bool flag = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] != res[i][j])
					flag = false;

		printf("Case #%d: ", test + 1);
		if (flag)
			puts("YES");
		else
			puts("NO");
	}
    
    return 0; 
}

