#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <string>

using namespace std;

// Input macros
#define s(n)                        scanf("%d",&n)
#define sl(n)						scanf("%I64d", &n)
#define sc(n)                       scanf("%c",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define INF 2147483647
#define UINF 0xffffffff

#define N 3

int c[N + 10][N + 10][N + 10], q, w, e, r, ans[N*N*N + 10][3], tot, tmp[N*N*N+10][3], t;

void dfs(int i, int j, int k)
{
	if (k > e)
	{
		dfs(i, j + 1, 1);
		return;
	}
	if (j > w)
	{
		dfs(i + 1, 1, k);
		return;
	}
	if (i > q)
	{
		if (tot < t)
		{
			tot = t;
			forall(p, 0, t)
			{
				ans[p][0] = tmp[p][0];
				ans[p][1] = tmp[p][1];
				ans[p][2] = tmp[p][2];
			}
		}
		return;
	}

	if (c[i][j][k] == 0 && c[i][j][0] < r && c[i][0][k] < r && c[0][j][k] < r)
	{
		c[i][j][k] = 1;
		c[i][j][0] ++;
		c[i][0][k] ++;
		c[0][j][k] ++;
		tmp[t][0] = i;
		tmp[t][1] = j;
		tmp[t++][2] = k;
		dfs(i, j, k + 1);
		t--;
		c[i][j][k] = 0;
		c[i][j][0] --;
		c[i][0][k] --;
		c[0][j][k] --;
	}
	dfs(i, j, k + 1);
}

void process(int testCase)
{
	s(q); s(w); s(e); s(r);
	fill(c, 0);
	fill(ans, 0);
	fill(tmp, 0);
	t = tot = 0;
	dfs(1, 1, 1);
	printf("Case #%d: %d\n", testCase, tot);
	forall(i, 0, tot)
		printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
}

void main()
{
	int c;
	s(c);
	forall(i, 0, c)
		process(i + 1);
}