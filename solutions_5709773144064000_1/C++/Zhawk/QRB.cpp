#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;
int tt = 1;
void solve(void)
{
	double C,F,X;
	scanf("%lf %lf %lf",&C,&F,&X);
	double sp = 2.0;
	double ans = 0.0;
	while(X>0.0)
	{
		if(C/sp+X/(sp+F)<X/sp)
		{
			ans+=C/sp;
			sp+=F;
		}
		else
		{
			ans+=X/sp;
			X=0.0;
		}

	}
	printf("Case #%d: %lf\n",tt++,ans);
}

int main(void)
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
    int T;
	scanf("%d",&T);
	while(T--)
	{
        solve();
	}
	return 0;
}
