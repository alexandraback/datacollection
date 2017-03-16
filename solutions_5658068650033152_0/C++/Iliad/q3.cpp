#include <bits/stdc++.h>
using namespace std;


#define Size(s) ((int)s.size())
#define rep(i, n) for(int i=0; i<n; ++i)
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define F first
#define S second
#define X real()
#define Y imag()
#define MP make_pair

template<class P, class Q> inline bool mmin(P &a, Q b) { if (a > b){ a = b; return true;} return false;}
template<class P, class Q> inline bool mmax(P &a, Q b) { if (a < b){ a = b; return true;} return false;}

typedef long long LL;
typedef pair<int, int> pii;

const int MAXn = 25;
int n, m, k;
bool av[MAXn][MAXn];
bool mark[MAXn][MAXn];
int mx[] = {-1, 0, 0, 1};
int my[] = {0, -1, 1, 0};
int gl;

inline bool check(int x, int y){ return x>=0 && x<=n+1 && y>=0 && y<=m+1;}

void DFS(int x, int y)
{
	mark[x][y] = true;
	rep(i, 4) {
		int nx = x+mx[i];
		int ny = y+my[i];
		if(check(nx, ny) && !mark[nx][ny] && !av[nx][ny])
			DFS(nx, ny);
	}
}

inline int solve()
{
	int ret = k;
	memset(av, 0, sizeof(av));
	rep(i, (1<<(n*m))) {
		int num1 = 0;
		rep(x, n) rep(y, m)
			if(i & 1<<(x*m+y))
				av[x+1][y+1] = true, ++num1;
			else
				av[x+1][y+1] = false;
		if(ret <= num1)
			continue;
		memset(mark, 0, sizeof(mark));
		DFS(0, 0);		
		int cnt = 0;
		rep(x, n) rep(y, m) if(!mark[x+1][y+1])
			++cnt;
		if(cnt>=k)
			ret = min(ret, num1);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int nt;
	cin >> nt;

	for(int ii=1; ii<=nt; ++ii) {
		cin >> n >> m >> k;
		cout << "Case #" << ii << ": " << solve() << endl;
	}

	return 0;
}


