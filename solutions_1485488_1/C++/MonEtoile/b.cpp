#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<functional>
#include<cassert>
#include<algorithm>

using namespace std;

//#define _INFILE		"B.in"
//#define _OUTFILE	"B.out"

//#define _INFILE		"B-small-attempt0.in"
//#define _OUTFILE	"B-small.out"

#define _INFILE		"B-large.in"
#define _OUTFILE	"B-large.out"


typedef long long ll;

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

int h, n, m;
int fl[200][200];
int ce[200][200];
int minTime[200][200];

int getTime(int t, int fl1, int fl2, int ce1, int ce2, bool& flag)
{
	flag = true;
	if (ce2 - fl2 < 50) return -1;
	if (ce1 - 50 < fl2) return -1;

	int curWater = h - t;
	int waterDepth = max((curWater - fl1), 0);
	int curH = fl1 + waterDepth;
	
	int result = 0;
	if (curH > ce2 - 50) 
	{
		int tt = curH - ce2 + 50;
		if (tt > waterDepth)
		{
			return -1;
		}
		
		waterDepth -= tt;
		result = tt;
		flag = false;
	}

	if (waterDepth >= 20) result += 10;
	else result += 100;

	return result;
}

void solve()
{
	scanf("%d%d%d",&h,&n,&m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d",&ce[i][j]);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			scanf("%d",&fl[i][j]);
			minTime[i][j] = 987654321;
		}

	int result = 987654321;

	int cur = 0;

	priority_queue<pair<int, int> > q;

	q.push(make_pair(0, 0));

	while(!q.empty())
	{
		pair<int, int> pi = q.top();
		q.pop();
		int w = -pi.first;
		int r = pi.second / m;
		int c = pi.second % m;
		if (w > minTime[r][c]) continue;

		int curWater = h - w;
		if (r == n-1 && c == m-1)
		{
			result = w;
			break;
		}

		for(int i=0; i<4; i++)
		{
			int rr = r + dr[i];
			int cc = c + dc[i];
			if (rr < 0 || cc < 0 || rr >= n || cc >= m)
				continue;

			bool flag = true;
			int canTime = getTime(w, fl[r][c], fl[rr][cc], ce[r][c], ce[rr][cc], flag);
			if (canTime < 0) continue;
			if (flag && w == 0) canTime = 0;
			else canTime += w;

			if (minTime[rr][cc] > canTime) {
				minTime[rr][cc] = canTime;
				q.push(make_pair(-canTime, rr*m + cc));
			}
		}
	}

	printf("%d.%d\n", result / 10, result % 10);
}

int main(void)
{
	int T;
	freopen(_INFILE, "r", stdin);
	freopen(_OUTFILE, "w", stdout);

	scanf("%d",&T);

	for(int i=0; i<T; i++)
	{
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}

