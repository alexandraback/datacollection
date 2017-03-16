#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,s,p,f[111][111],c[111];
int a[40]={0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10};
int b[40]={0,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,10,10};

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for (int tt=1; tt<=T; tt++)
	{
		scanf("%d%d%d",&n,&s,&p);
		for (int i=1; i<=n; i++)
		    scanf("%d",&c[i]);
		for (int i=1; i<=n; i++)
		{
			f[i][0]=f[i-1][0]+(a[c[i]]>=p);
		    for (int j=1; j<=s; j++)
		    {
				if (j>i)
				    break;
				f[i][j]=max(f[i-1][j]+(a[c[i]]>=p),f[i-1][j-1]+(b[c[i]]>=p));
		    }
	    }
	    printf("Case #%d: %d\n",tt,f[n][s]);
    }
    return 0;
}
