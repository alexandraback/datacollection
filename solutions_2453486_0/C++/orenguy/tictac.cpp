#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<sstream>
#include<string>
#include<string.h>
#include<deque>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
#include<set>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

double PI = acos(-1);
double EPS = 1e-7;
int INF = 1000000000;
int MAXINT = 2147483647;
LL INFLL = 1000000000000000000LL;
LL MAXLL = 9223372036854775807LL;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define SIZE(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define RESET(a,b) memset(a,b,sizeof(a))
#define FOR(a,b,c) for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a,b) for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); (a)++)
#define MIN(a, b) (a) = min((a), (b))
#define MAX(a, b) (a) = max((a), (b))
#define PAUSE system("pause")

#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)

pii M[8] = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1),mp(-1,1),mp(-1,-1),mp(1,-1),mp(1,1)};

/*\   \
\   \*/

char c[1000];
char k[10][10];

int main()
{
	int t;
	scanf("%d",&t);
	gets(c);
	FOR(tc,1,t)
	{
		char dum;
		bool done = 1;
		FOR(a,1,4)
		{
			FOR(b,1,4)
			{
				scanf("%c",&k[a][b]);
				if (k[a][b] == '.') done = 0;
			}
			gets(c);
		}
		if (tc != t) gets(c);
		int win = -1;
		FOR(a,1,4)
		{
			int x=0,o=0,t=0;
			FOR(b,1,4)
			{
				if (k[a][b] == 'X') x++;
				if (k[a][b] == 'O') o++;
				if (k[a][b] == 'T') t++;
			}
			if (x == 4 || x == 3 && t == 1) win = 0;
			if (o == 4 || o == 3 && t == 1) win = 1;
		}
		FOR(a,1,4)
		{
			int x=0,o=0,t=0;
			FOR(b,1,4)
			{
				if (k[b][a] == 'X') x++;
				if (k[b][a] == 'O') o++;
				if (k[b][a] == 'T') t++;
			}
			if (x == 4 || x == 3 && t == 1) win = 0;
			if (o == 4 || o == 3 && t == 1) win = 1;
		}
		int x=0,o=0,t=0;
		FOR(a,1,4)
		{
			if (k[a][a] == 'X') x++;
			if (k[a][a] == 'O') o++;
			if (k[a][a] == 'T') t++;
		}
		if (x == 4 || x == 3 && t == 1) win = 0;
		if (o == 4 || o == 3 && t == 1) win = 1;
		x=0,o=0,t=0;
		FOR(a,1,4)
		{
			if (k[a][5-a] == 'X') x++;
			if (k[a][5-a] == 'O') o++;
			if (k[a][5-a] == 'T') t++;
		}
		if (x == 4 || x == 3 && t == 1) win = 0;
		if (o == 4 || o == 3 && t == 1) win = 1;
		printf("Case #%d: ",tc);
		if (win == 0) puts("X won");
		else if (win == 1) puts("O won");
		else if (done == 1) puts("Draw");
		else puts("Game has not completed");
	}
}
