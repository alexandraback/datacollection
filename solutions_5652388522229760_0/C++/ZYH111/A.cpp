#include<cstdio>
#include<cstring>
#define LL long long
int main()
{
	bool b[10];
	LL n,m,i;
	int T,_T,j;
	bool flag;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	for (_T=1;_T<=T;_T++)
	{
		scanf("%I64d",&n);
		printf("Case #%d: ",_T);
		if (n==0) printf("INSOMNIA\n");
		else
		{
			memset(b,false,sizeof(b));
			flag=false; i=0;
			do
			{
				i++; m=n*i;
				while (m>0)
				{
					b[m%10]=true; m/=10;
				}
				flag=true;
				for (j=0;j<=9;j++)
					if (!b[j])
					{
						flag=false; break;
					}
			}
			while (!flag);
			printf("%I64d\n",n*i);
		}
	}
	return 0;
}
