#include<cstdio>
#include<iostream>
using namespace std;
int a[2000200][7];
int num[2000200],x,y,xx,ans,T,l,r;

int main()
{
	x=10; y=1;
	for (int i=1; i<=2000000; i++)
	{
		if (i==x)
		{
			x*=10; y++;
	    }
	    xx=1;
	    for (int j=1; j<y; j++)
	    {
			xx*=10;
			if (i%xx>=xx/10)
			{
				int nn=(x/xx)*(i%xx)+i/xx;
			    if (nn<=i) continue;
			    bool pd=false;
                for (int k=0; k<num[i]; k++)
                    if (nn==a[i][k]) {pd=true; break;}
		        if (!pd) a[i][num[i]++]=nn;
			}
		}
    }
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d",&T);
    for (int tt=1; tt<=T; tt++)
    {
		scanf("%d%d",&l,&r);
		ans=0;
		for (int i=l; i<=r; i++)
		    for (int j=0; j<num[i]; j++)
		        if (a[i][j]>=l && a[i][j]<=r && a[i][j]>i)
		        {
		            ans++;
				    //printf("%d %d\n",i,a[i][j]);
				}
		printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
