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
int n,x,y;
int pos = 0;
int kena = 0;

double move(int lv,int sisa,int l,int r,bool vs,double possi)
{
	if (sisa == 0)
	{
		if (vs) return possi;
		else return 0.0;
	}
	if (l == 2*lv && r == 2*lv)
	{
		bool b = (y == 2*lv && x == 0);
		//if (b == 1) cout << lv << " " << sisa << " " << l << " " << r << " " << vs << endl;
		return move(lv+1,sisa-1,0,0,b|vs,possi);
	}
	else
	{
			double sum = 0.0;
			int masuk = 0;
		if (l < 2*lv) masuk++;
		if (r < 2*lv) masuk++;
		if (l < 2*lv)
		{
			bool b = (y == l && x == l-2*lv);
			//if (b == 1) cout << lv << " " << sisa << " " << l << " " << r << " " << vs << endl;
			sum += move(lv,sisa-1,l+1,r,b|vs,possi/((double)masuk));
		}
		if (r < 2*lv)
		{
			bool b = (y == r && x == 2*lv-r);
			sum += move(lv,sisa-1,l,r+1,b|vs,possi/((double)masuk));
		}
		return sum;
	}
}

double ans()
{
	if (x == 0 && y == 0) return 1;
	if (n == 1) return 0;
	else
	{
		return move(1,n-1,0,0,0,1.0);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	FOR(tc,1,T)
	{
		kena = 0;
		pos = 0;
		scanf("%d%d%d",&n,&x,&y);
		printf("Case #%d: %.7lf\n",tc,ans());
	}
}
