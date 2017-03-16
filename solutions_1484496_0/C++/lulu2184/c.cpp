#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[20000000],tmp,T,a[100],n;
bool fi;

bool dfs(int x,int mask,int sum)
{
	if (x==n+1)
	{
		if (f[sum]) 
		{
			fi=false;
			tmp=(f[sum]&mask);
			f[sum]^=tmp;mask^=tmp;
			for (int i=1;i<=n;i++) if (f[sum]&(1<<(i-1))) 
			{
				if (fi) printf(" ");
				printf("%d",a[i]);
				fi=true;
			}
			printf("\n");
			fi=false;
			for (int i=1;i<=n;i++) if (mask&(1<<(i-1)))
			{
				if (fi) printf(" ");
				printf("%d",a[i]);
				fi=true;
			}
			printf("\n");
			return true;
		}else f[sum]=mask;
		return false;
	}
	if (dfs(x+1,mask,sum)) return true;
	if (dfs(x+1,mask|(1<<(x-1)),sum+a[x])) return true;
	return false;
}

int main()
{
	freopen("c.in","r",stdin);freopen("c.out","w",stdout);
	
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		memset(f,0,sizeof(f));
		printf("Case #%d:\n",TT);
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		if (!dfs(1,0,0)) printf("impossible\n") ;
	}
	
	return 0;
}