/*************************
* Stanislaw Szczesniak   *
*2013.luty, out_constest *
*************************/

#include <utility>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string.h>
#include <tr1/functional>
#include <stack>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <list>
#include <cassert>
#include <numeric>

#define DEBUG(x) printf ("debug%d\n", x);
#define ST first
#define ND second
#define PB push_back
#define PPB pop_back
#define MP make_pair
#define PF push_front
#define PPF pop_front
#define FOR(x,b,e) for (int x=b; x<=(e);x++)
#define FORD(x,b,e) for (int x=b;x>=(e);x--)
#define REP(x,n) for (int x=0;x<(n);x++)
#define DET(a,b,c) (((LL)(b.x-a.x))*(c.y-a.y) - ((LL)(b.y-a.y))*(c.x-a.x))
#define INARR(arr, i, n) REP(i,n) scanf ("%d",&arr[i]);
#define VAR(v,n) __typeof(n) v = n
#define FOREACH(i,c) for (VAR(i,c.begin()); i != c.end(); i++) 
#define SIZE(x) ((int)(x).size())
#define NL printf ("\n")
#define MAXN 101
#define IY 1000

using namespace std;
using std::tr1::hash;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef long long LL;
typedef priority_queue<PII> PQII;

int arr[101][101];

int miniw[101];
int minik[101];

int main () 
{
	int t,n,m;
	scanf("%d", &t);
	REP(i,t)
	{
		scanf("%d %d", &n, &m);
		REP(j,n) miniw[j] = -1;
		REP(k,m) minik[k] = -1;
		REP(j,n)
		{
			REP(k,m)
			{
				scanf("%d", &arr[j][k]);
				miniw[j] = max(miniw[j], arr[j][k]);
				minik[k] = max(minik[k], arr[j][k]);
			}	
		}
		bool end = false;
		REP(j,n)
		{
			REP(k,m)
			{
				if (!(arr[j][k] == miniw[j] or arr[j][k] == minik[k]))
				{
					printf("Case #%d: NO\n", i+1);
					end = true;
					break;	
				}
			}
			if (end)
				break;
		}
		if (!end)
			printf("Case #%d: YES\n", i+1);

	}
	
	
}
