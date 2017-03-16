#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>


const int dx[] = {1, -1, -1, 1};
const int dy[] = {-1, -1, 1, 1};
const int ndx[] = {0, 1, 0, -1};
const int ndy[] = {1, 0, -1, 0};
const int maxn = 1046;


using namespace std;


vector<pair<int, pair<int, int> > > v1;
bool belongs[maxn][maxn];
bool used[maxn][maxn];
int ptr = 0;


bool valid(int x, int y, int n, int m)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}


queue<pair<int, int> > q;


int sqr(int x)
{
	return x * x;
}


int solve1(int n, int m, int k)
{
	pair<int, int> pos(n / 2, m / 2);
	ptr = 0;
	memset(belongs, false, sizeof(belongs));
	memset(used, false, sizeof(used));
	v1.clear();
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			v1.push_back(make_pair(sqr(i - n / 2) + sqr(j - m / 2), make_pair(i, j)));
		}
	sort(v1.begin(), v1.end());
	for(int i = 0; i < k; i++)
		belongs[v1[i].second.first][v1[i].second.second] = true;
	for(int i = 0; i < n; i++)
	{
		q.push(make_pair(i, 0));
		q.push(make_pair(i, m - 1));
		used[i][0] = used[i][m - 1] = true;
	}
	for(int i = 1; i < m - 1; i++)
	{
		q.push(make_pair(0, i));
		q.push(make_pair(n - 1, i));
		used[0][i] = used[n - 1][i] = true;
	}
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(belongs[x][y])
			continue;
		for(int i = 0; i < 4; i++)
		{
			int nx = x + ndx[i];
			int ny = y + ndy[i];
			if(valid(nx, ny, n, m) && !used[nx][ny])
			{
				used[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(belongs[i][j] && used[i][j])
				ans++;
	return ans;
}
vector<pair<int, int> > v;
pair<int, int> getNext(pair<int, int> pos, int n, int m)
{
	while(true)
	{
		pos.first += v[ptr].first;
		pos.second += v[ptr].second;
		ptr++;
		if(valid(pos.first, pos.second, n, m))
			return pos;
	}
}

int solve2(int n, int m, int k)
{
	pair<int, int> pos(n / 2, m / 2);
	ptr = 0;
	memset(belongs, false, sizeof(belongs));
	memset(used, false, sizeof(used));
	belongs[pos.first][pos.second] = true;
	for(int i = 1; i < k; i++)
	{
		pos = getNext(pos, n, m);
		belongs[pos.first][pos.second] = true;
	}
	for(int i = 0; i < n; i++)
	{
		q.push(make_pair(i, 0));
		q.push(make_pair(i, m - 1));
		used[i][0] = used[i][m - 1] = true;
	}
	for(int i = 1; i < m - 1; i++)
	{
		q.push(make_pair(0, i));
		q.push(make_pair(n - 1, i));
		used[0][i] = used[n - 1][i] = true;
	}
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(belongs[x][y])
			continue;
		for(int i = 0; i < 4; i++)
		{
			int nx = x + ndx[i];
			int ny = y + ndy[i];
			if(valid(nx, ny, n, m) && !used[nx][ny])
			{
				used[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(belongs[i][j] && used[i][j])
				ans++;
	return ans;
}


void solve(int t)
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int ans = min(solve1(n, m, k), solve2(n, m, k));
	printf("Case #%d: %d\n", t, ans);
}





void generateDirections()
{
	v.push_back(make_pair(0, 1));
	for(int i = 1; i < 1000; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			for(int k = 0; k < i; k++)
			{
				if(j == 3 && k == 0)
					v.push_back(make_pair(0, 1));
				v.push_back(make_pair(dx[j], dy[j]));
			}
		}
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	generateDirections();
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		solve(i + 1);
	}
}