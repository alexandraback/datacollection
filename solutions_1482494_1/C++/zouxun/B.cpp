#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1050;
int lev[MAXN],a[MAXN],b[MAXN];
int main()
{
	int cases;
	scanf("%d",&cases);
	for (int tcase=1;tcase<=cases;tcase++)
	{
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
		memset(lev,0,sizeof(lev));		
		int now=0;
		int ts=0;
		int ans=0;		
		while (ts<n)
		{
			bool flag=false;
			for (int j=1;j<=n;j++)
				if (lev[j]<2 && b[j]<=now){
						ans++;
						now++;
						now+=lev[j]==0;
						lev[j]=2;
						ts++;
						flag=true;
						break;
					}
			if (flag) continue;
			int bestk=-1,bestx=-100;
			for (int j=1;j<=n;j++)
				if (lev[j]==0 && a[j]<=now){
					int v=b[j];
					if (v>bestx){
						bestx=v;
						bestk=j;
					}
				}
			if (bestk==-1) break;
			lev[bestk]=1;
			ans++;
			now++;
		}
		printf("Case #%d: ",tcase);
		if (ts<n) printf("Too Bad\n");
		  else printf("%d\n",ans);
	}
	return 0;
}
