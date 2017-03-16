#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef double DB;

const int N = 100010;

DB p[N],pp[N];

int main(void)
{
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		pp[0]=1.0;
		for(int i=1;i<=a;i++)
		{
			scanf("%lf",p+i);
			pp[i]=pp[i-1]*p[i];
		}
		// give up 
		DB res = b + 2;
		// keep typing
		DB tmp = pp[a]*(b-a+1)+(1-pp[a])*(b-a+1+b+1);
		res = min(res, tmp);
		// press backspace i time(s)
		for(int i=1;i<=a;i++)
		{
			tmp = pp[a-i]*(i+b-a+i+1)+(1-pp[a-i])*(i+b-a+i+1+b+1);
			res = min(res, tmp);
		}
		printf("Case #%d: %.6lf\n", cas, res);
	}
	return 0;
}
