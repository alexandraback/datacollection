#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <deque>
#include <ctime>
#include <list>
#include <set>
#include <map>
//zlb//

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
int MOD    = 1000000007;
int MAXINT = 2147483647;
LL INFLL   = 1000000000000000000LL;
LL MAXLL   = 9223372036854775807LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back
#define SIZE(a)       (int)a.size()
#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))
#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)
#define RESET(a, b)   memset(a,b,sizeof(a))
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ------------ //

char x[55][55];

int main()
{
	int tc;
	scanf("%d",&tc);
	FOR(T,1,tc)
	{
		int r,c,m;
		scanf("%d%d%d",&r,&c,&m);
		printf("Case #%d:\n",T);
		FOR(a,1,r)
		{
			FOR(b,1,c)
			{
				x[a][b] = '*';
			}
		}
		bool fail = 0;
		bool found = 0;
		m = r*c-m;
		//cout << "M " << m << endl;
		if (m == 1)
		{
			found = 1;
			x[1][1] = '.';
		}
		else if (r == 1)
		{
			found = 1;
			FOR(a,1,m)
			{
				x[1][a] = '.';
			}
		}
		else if (c == 1)
		{
			found = 1;
			FOR(a,1,m)
			{
				x[a][1] = '.';
			}
		}
		else
		{
			FOR(a,2,r)
			{
				FOR(b,2,c)
				{
					//cout << a << " " << b << " " << (a-2)*2+(b-2)*2+4 << " " << a*b << " " << m << endl;
					if ((a-2)*2+(b-2)*2+4 <= m && a*b >= m)
					{
						
						int sisa = m-((a-2)*2+(b-2)*2+4);
						FOR(e,1,2)
						{
							FOR(f,1,b)
							{
								x[e][f] = '.';
							}
						}
						FOR(e,1,a)
						{
							FOR(f,1,2)
							{
								x[e][f] = '.';
							}
						}

						FOR(e,3,a)
						{
							FOR(f,3,b)
							{
								if (sisa)
								{
									x[e][f] = '.';
									sisa--;
								}
							}
						}
						found = 1;
						break;
					}
				}
				if (found) break;
			}
		}
		if (!found) puts("Impossible");
		else
		{
			x[1][1] = 'c';
			FOR(a,1,r)
			{
				FOR(b,1,c)
				{
					printf("%c",x[a][b]);
				}
				printf("\n");
			}
		}
	}
}
