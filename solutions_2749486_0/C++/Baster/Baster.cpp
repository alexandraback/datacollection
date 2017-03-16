#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int t;
int from[3001][3001];

inline void read()
{
	scanf("%d", &t);
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
char move[] = {'E', 'W', 'S', 'N'};

inline void solve()
{
	for (int test = 1; test <= t; ++test)
	{
		int x, y;
		cin >> x >> y;
		forn (i, 3001)
			forn (j, 3001)
			from[i][j] = -1;
		queue<pair<pair<int, int>, int>> q;
		from[1500][1500] = 0;
		bool done = false;
		//swap(x, y);
		x += 1500, y += 1500;
		q.push(mp(mp(1500, 1500), 1));
		while(!q.empty())
		{
			pair<int, int> v = q.front().first;
			int jump = q.front().second;
			q.pop();
			forn (i, 4)
			{
				int nx = v.first + dx[i] * jump;
				int ny = v.second + dy[i] * jump;
				int tmp = (v.first == x) + (v.second == y);
				int ntmp = (nx == x) + (ny == y);
				if(abs(nx - 1500) > 1500 || abs(ny - 1500) > 1500)
						continue;
		
				if(from[nx][ny] == -1)
				{
					from[nx][ny] = i;
					q.push(mp(mp(nx, ny), jump + 1));
					if(nx == x && ny == y)
					{
						string ans;
						cout << "Case #" << test << ": ";
						while(nx != 1500 || ny != 1500)
						{
							int fr = from[nx][ny];
							ans += move[fr];
							int nnx = nx - dx[fr] * jump;
							int nny = ny - dy[fr] * jump;
							jump--;
							nx = nnx, ny = nny;
						}
						reverse(ans.begin(), ans.end());
						cout << ans;
						done = true;
					}
				}
			}
			if(done)
			{
				cout << endl;
				break;
			}
		}
		if(!done)
		{
			cout << "ALARM" << endl;
		}
	}
}

int main()
{
#ifdef Baster
	freopen("B-small-attempt4.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	read();
	solve();
	return 0;
}