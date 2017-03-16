#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring> 
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <LL> VL;

const int MAXN = 100010 * 2;

int N, M, K;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int count (int s)
{
	int res = 0;
	while (s > 0)
	{
		++ res;
		s -= s & -s;	
	}	
	return res;
}

void dfs (int x, int y, int &no)
{
//	cout << x << " --  " << y << endl;
	
	if (x < 0 || x >= N || y < 0 || y >= M)	return;
	
	if ((1 << x * M + y) & no)	return;
	
	no |= (1 << x * M + y);
	
	for (int i = 0; i < 4; ++ i)
	{
		dfs (x + dx[i], y + dy[i], no);	
	}	
}

bool check (int s)
{
	int no = s;
	for (int x = 0; x < N; ++ x)
		for (int y = 0; y < M; ++ y)
			if (x == 0 || y == 0 || x == N - 1 || y == M - 1)
				dfs (x, y, no);
//	cout << "no  " << no << endl;
	return count (no ^ s) <= N * M - K;
}

int main()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	
	int T;	cin >> T;
	for (int cas = 1; cas <= T; ++ cas)
	{
		cin >> N >> M >> K;
		if (N > M)	swap (N, M);
		int ans = 100;
		for (int s = 0; s < (1 << N * M); ++ s)
		{
			if (check (s))
			{
				ans = min (ans, count (s));	
//				cout << "s  " << s << endl;
//				break;
			}
		}
		cout << "Case #" << cas << ": " << ans << endl;
	}
	
	
	
	return 0;	
}
