#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

long long p,q;

void cal(long long p,long long q,int &now)
{
    if(p>q || now>40)
    {
        now = -1;
        return;
    }
    if(p==0) return;
    
    for(; p<q; p<<=1, now++) ;
    int tmp = now;
    cal(p-q,q,tmp);
    if(tmp<0)
    {
        now = -1;
        return;
    }
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++)
	{
		scanf("%lld/%lld",&p,&q);
		int ans = 0;
		cal(p,q,ans);
		if(ans>=0)
            printf("Case #%d: %d\n",cnt,ans);
        else
            printf("Case #%d: impossible\n",cnt);
	} 
} 
