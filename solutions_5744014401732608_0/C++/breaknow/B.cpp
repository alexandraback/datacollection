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

#define N 50

int t[N + 10], n, b, ans[N+10][N+10], tot;

void process(int testCase)
{
	s(n); s(b);
	fill(t, 0);
	fill(ans, 0);
	tot = 1;
	ans[1][n] = 1;
	t[1] = 1;
	for (int i = 2; i < n; i++)
	{
		bool flag = false;
		for (int j = i - 1; j > 0; j--)
		{
			if (tot + t[j] <= b)
			{
				tot += t[j];
				t[i] += t[j];
				ans[j][i] = 1;
				flag = true;
			}
		}
		if (flag)
			ans[i][n] = 1;
		if (tot >= b)
			break;
	}
	printf("Case #%d: ", testCase);
	if (tot == b)
	{
		printf("POSSIBLE\n");
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				printf("%d", ans[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("IMPOSSIBLE\n");
}

void main()
{
	int t;
	s(t);
	forall(i, 0, t)
		process(i + 1);
}