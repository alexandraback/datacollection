#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int T,top,n,i,j,t;
int s[10000],ans[10000];
int main(){
	freopen("temp.in","r",stdin);
	freopen("temp.out","w",stdout);
	scanf("%d",&T);
	for (int tt = 1;tt<=T;tt++)
	{
		printf("Case #%d: ",tt);
		top = 0;
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		for (i = 1;i <= 2*n -1;i++)
			for (j = 1;j<=n;j++)
			{
				scanf("%d",&t);
				s[t]++;
			}
		for (i = 1;i<=2500;i++)
		{
			if (s[i]%2==1)
			{
				top++;
				ans[top] = i;
			}
		}
		sort(ans+1,ans+1+n);
		for (i = 1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}
