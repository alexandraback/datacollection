#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

//freopen( "input.txt", "r", stdin );
//freopen( "output.txt", "w", stdout );
//fflush( stdin );

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000 //1 Billon
#define EPS 1e-9
#define MOD 1000000007
#define WHITE -1
#define BLACK 1
#define GRAY 2

//int num_length( int n ) { return int( log10( n ) ) + 1; }
int gcd( int a, int b ){ return b == 0 ? a : gcd( b, a % b ); }
int lcm( int a, int b ){ return a * ( b / gcd( a, b ) ); }
//int toi( string a ){ int ans;  sscanf(a.c_str(),"%d",&ans);  return ans;  }
//string tos( int a ){ ostringstream st; st<<a; string ans = st.str(); return ans; }

#define FOR(i,a,b) for(int i=(a), _b=(b);i<=_b;i++)
#define DOW(i,b,a) for(int i=(b), _a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define mem(A,x) memset(A, x, sizeof A)
#define pb push_back
#define all(A) A.begin(),A.end()
#define sci(x) scanf("%d",&x)
#define scs(x) gets(x);

int t, r, c, m;
int ans = 0;
int num = 0;
int flag[ 105 ] = {0};
int vis[ 105 ] = {0};

typedef pair<int, int> P;
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void bfs(int x, int y)
{
    queue<P> que;

    que.push(P(x, y));
    vis[x*c+y] = 1;
    ans = 1;

    while(que.size())
    {
        P p = que.front();
        que.pop();

        int mark = 1;
        for(int i = 0; i < 8; ++i)
        {
            int nx = p.first + dir[i][0], ny = p.second + dir[i][1];
            if(nx >= 0 && nx < r && ny >= 0 && ny < c)
            {
                if(flag[nx*c+ny] == 1) mark = 0;
            }
        }
        if(mark)
        {
            for(int i = 0; i < 8; ++i)
            {
                int nx = p.first + dir[i][0], ny = p.second + dir[i][1];
                if(nx >= 0 && nx < r && ny >= 0 && ny < c && vis[nx*c+ny] == 0)
                {
                    vis[nx*c+ny] = 1;
                    ans++;
                    que.push(P(nx, ny));
                }
            }
        }
    }
}

int dfs()
{
	int comb = (1 << m) - 1;
	memset(flag, 0, sizeof(flag));
	int i = 1;
	int j = 0;
	while(true)
	{
		if(i & comb)
		{
			flag[j] = 1;
		}
		++j;
		i*=2;
		if(j >= r*c) break;
	}

	int res = r * c - m;

	for(int x = 0; x < r; ++x)
	{
		for(int y = 0; y < c; ++y)
		{
			if(flag[x*c+y] == 0)
			{
				ans = 0;
				memset(vis, 0, sizeof(vis));
				bfs(x, y);
				if(ans == res)
				{
					cout << "Case #" << num << ": " << endl;
					for(int l = 0; l < r; ++l)
					{
						for(int g = 0; g < c; ++g)
						{
							if(l == x && g == y) cout << "c";
							else if(flag[l*c+g] == 1) cout << "*";
							else cout << ".";
						}
						cout << endl;
					}
					return 1;
				}
			}
		}
	}

	while(comb < 1 << r*c)
	{
		int p1 = comb & -comb, p2 = comb + p1;
		comb = ((comb & ~p2) / p1 >> 1) | p2;

		memset(flag, 0, sizeof(flag));
		int i = 1;
		int j = 0;
		int ans1 = 0;
		while(true)
		{
			if(i & comb)
			{
				flag[j] = 1;
				++ans1;
			}
			++j;
			i*=2;
			if(j >= r*c) break;
		}

		for(int x = 0; x < r; ++x)
		{
			for(int y = 0; y < c; ++y)
			{
				if(flag[x*c+y] == 0)
				{
					ans = 0;
					memset(vis, 0, sizeof(vis));
					bfs(x, y);
					if(ans == res)
					{
						cout << "Case #" << num << ": " << endl;
						for(int l = 0; l < r; ++l)
						{
							for(int g = 0; g < c; ++g)
							{
								if(l == x && g == y) cout << "c";
								else if(flag[l*c+g] == 1) cout << "*";
								else cout << ".";
							}
							cout << endl;
						}
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

void Solve()
{
    memset(flag, 0, sizeof(flag));
    if(dfs() == 0)
    {
        cout << "Case #" << num << ": " << endl << "Impossible" << endl;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> t;
    int tFirst = t;
    while(t--)
    {
        cin >> r >> c >> m;
        num = tFirst - t;
        Solve();
    }
    return 0;
}


