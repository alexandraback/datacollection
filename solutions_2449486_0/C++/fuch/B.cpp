#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <functional>

#define rep(i,n) for(int i=0;i<(n);++i)
#define foreach(i,v) for(__typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define ass(v) (v)||++*(int*)0;

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<double> VD;

int land[100][100];
bool ok[100][100];
int n, m;

bool solve()
{
	memset(ok, 0, sizeof(ok));
	for (int h = 1; h <= 100; ++h)
	{
		for (int i = 0; i < n; ++i)
		{
			bool has = false, valid = true;
			for (int j = 0; j < m; ++j)
			{
				if (!ok[i][j] && land[i][j] != h)
				{
					valid = false;
					break;
				}
				if (land[i][j] == h) has = true;
			}
			if (has && valid)
			{
				for (int j = 0; j < m; ++j) ok[i][j] = true;
			}
		}

		for (int j = 0; j < m; ++j)
		{
			bool has = false, valid = true;
			for (int i = 0; i < n; ++i)
			{
				if (!ok[i][j] && land[i][j] != h)
				{
					valid = false;
					break;
				}
				if (land[i][j] == h) has = true;
			}
			if (has && valid)
			{
				for (int i = 0; i < n; ++i) ok[i][j] = true;
			}
		}

//		for (int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j < m; ++j) printf("%d", ok[i][j]);
//			puts("");
//		}
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!ok[i][j]) return false;
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) scanf("%d", &land[i][j]);
		printf("Case #%d: %s\n", cs, solve() ? "YES" : "NO");
	}
	return 0;
}
