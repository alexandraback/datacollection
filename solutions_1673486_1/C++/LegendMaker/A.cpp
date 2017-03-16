#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<string>
#define INF 987654321
#define EPS 1e-10
#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX(a,b) ((a)<(b)?(b):(a))
using namespace std;
/////////////////////////////////////////
#define MAXN 99999+10
double p[MAXN],q[MAXN];
int main()
{
	int ca=1;
	double ans,temp;
	int c,a,b,i,j,len;
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d%d",&a,&b);
		for(i=1;i<=a;i++)
			scanf("%lf",&p[i]);
		q[0]=1;
		for(i=1;i<=a;i++)
			q[i]=q[i-1]*p[i];
		ans=q[a]*(b-a+1);
		ans+=(1-q[a])*(b-a+1+b+1);
		ans=MIN(ans,b+2);
		for(i=1;i<a;i++)
		{
			temp=0;
			len=i+i+b-a+1+b+1;
			for(j=1;j<=a-i;j++)
				temp+=len*q[j-1]*(1-p[j]);
			len=i+i+b-a+1;
			temp+=len*q[a-i];
			ans=MIN(ans,temp);
		}
		printf("Case #%d: %.6lf\n",ca++,ans);
	}
	return 0;
}