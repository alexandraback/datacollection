#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>
#define LL long long
#define INF 1000000000

using namespace std;

struct cell
{
	int now; 
	vector<PII> dropped;
};

int T, N, X, Y;
int chance[22][211][111], total[22];
queue<cell> q;

int main()
{
	cell init; init.now = 1; init.dropped.pb(mp(100, 0));
	memset(chance, 0, sizeof(chance));
	memset(total, 0, sizeof(total));
	q.push(init);
	
	while(!q.empty())
	{
		cell node = q.front(); q.pop();
		if(0) { printf("%d:", node.now);
				for(int i = 0; i < node.dropped.size(); i++) 
				printf(" (%d, %d)", node.dropped[i].fi - 100, node.dropped[i].se);
				printf("\n"); }
		
		total[node.now]++;
		bool used[211][111]; memset(used, false, sizeof(used));
		for(int i = 0; i < node.dropped.size(); i++)
		{
			int x = node.dropped[i].fi, y = node.dropped[i].se;
			chance[node.now][x][y]++;
			used[x][y] = true;
		}
		
		if(node.now == 20) continue;
		
		int pos = -1;
		for(int i = 100; i >= 0 && pos == -1; i -= 2) 
			if(used[100][i]) pos = i + 2; 
		
		//stay
		if(used[99][pos-1] && used[101][pos-1])
		{
			vector<PII> temp = node.dropped; temp.pb(mp(100, pos));
			sort(temp.begin(), temp.end());
			cell next = (cell) { node.now + 1, temp };
			q.push(next);
		}
		
		// to the left;
		int x = 100, y = pos;
		while(y - 1 >= 0 && !used[x - 1][y - 1]) { y--; x--;};
		if(mp(x, y) != mp(100, pos))
		{
			vector<PII> temp = node.dropped; temp.pb(mp(x, y));
			sort(temp.begin(), temp.end());
			cell next = (cell) { node.now + 1, temp };
			q.push(next);
		}
		
		// to the right;
		x = 100, y = pos;
		while(y - 1 >= 0 && !used[x + 1][y - 1]) { y--; x++;};
		if(mp(x, y) != mp(100, pos))
		{
			vector<PII> temp = node.dropped; temp.pb(mp(x, y));
			sort(temp.begin(), temp.end());
			cell next = (cell) { node.now + 1, temp };
			q.push(next);
		}
	}
	
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d %d %d", &N, &X, &Y);
		printf("Case #%d: ", t);
		
		if(X + 100 < 0 || X + 100 >= 211 || Y >= 111) printf("0.000000\n"); else
		{
			//cout << X << " " << Y << " " << X + 50 << " " << Y << endl;
			//cout << chance[N][X + 50][Y] << " " << total[N] << endl;
			printf("%.6lf\n", chance[N][X + 100][Y] / (double) total[N]);
		}
	}
	return 0;
}

