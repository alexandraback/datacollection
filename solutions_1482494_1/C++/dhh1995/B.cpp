#include<cstdio>
#include<cstring>
int x[1005],y[1005];
bool b1[1005],b2[1005];
int t,Case=0,n,m,cnt,ans;
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n); memset(b1,0,sizeof(b1)); memset(b2,0,sizeof(b2));
		for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]); cnt=ans=0;
		while (cnt<n+n){
			int j=-1,m;
			for (int i=1;i<=n;i++) if (!b2[i] && y[i]<=cnt) {j=i; break;}
		//	printf("2 %d %d\n",cnt,j);
			if (j>0){				
				if (b1[j]) cnt++; else cnt+=2;
				ans++,b1[j]=b2[j]=1;
				continue;				
				}
			j=-1; m=0;
			for (int i=1;i<=n;i++) if (!b1[i] && x[i]<=cnt && y[i]>m) j=i,m=y[i];
		//	printf("1 %d %d\n",cnt,j);
			if (j>0) cnt++,ans++,b1[j]=1;
			else break;
			}
		if (cnt<n+n) printf("Case #%d: Too Bad\n",++Case);
		else printf("Case #%d: %d\n",++Case,ans);
		}
	return 0;
}
