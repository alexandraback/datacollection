//darkstallion's template

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define del erase
#define sz size
#define ins insert
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORS(a,b,c) for(int a = b; a <= c; a++)
#define FORN(a,b) for(int a = 0; a < b; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)
#define RES(a,b) memset(a,b,sizeof(a))
#define LL long long
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PDD pair<double,double>
#define PCC pair<char,char>
#define PSS pair<string,string>
using namespace std;

int t;
double a,b,ans,z,x;

int main()
{
	scanf("%d",&t);
	FORN(i,t)
	{
		scanf("%lf%lf",&a,&b);
		ans = b+2;
		z = 1;
		FORN(j,(int)a)
		{
			scanf("%lf",&x);
			z *= x;
			ans = min(ans,z*(b+a-2*(j+1)+1)+(1-z)*(b+a-2*(j+1)+1+b+1));
		}
		printf("Case #%d: %.6lf\n",i+1,ans);
	}
}
