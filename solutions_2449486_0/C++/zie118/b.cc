#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

#define inf (1<<29)
#define eps (1e-9)

#define flt(x,y) ((x)<(y)-eps)
#define fgt(x,y) flt(y,x)
#define fle(x,y) !fgt(x,y)
#define fge(x,y) !flt(x,y)
#define feq(x,y) (fabs((x)-(y))<eps)

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int a[105][105];
int N, M;

bool fail(int x, int y)
{
	int mr = -1, mc = -1;
	for (int i = 0; i < M; i++) mr = max(mr, a[x][i]);
	for (int j = 0; j < N; j++) mc = max(mc, a[j][y]);
	if (mr > a[x][y] && mc > a[x][y]) return true;
	return false;
}

int main()
{
	int T; scanf("%d", &T);
	for (int cc=1; cc<=T; cc++)
	{
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &a[i][j]);
		bool ans = true;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (fail(i, j)) ans = false;
		if (ans) printf("Case #%d: YES\n", cc); else printf("Case #%d: NO\n", cc);
	}
	return 0;
}
