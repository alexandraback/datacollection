#include <bits/stdc++.h>
using namespace std;
map<string ,int> msi[2];
int cnt[2];
int a[2][20];
char s1[50],s2[50];
int valid[2][17];
int main()
{
	freopen("inc.txt","r",stdin);
	freopen("outc.txt","w",stdout);
	int T,ca=0,n;
	scanf("%d",&T);
	while(T--){
		cnt[0]=cnt[1]=0;
		msi[1].clear();
		msi[0].clear();
		scanf("%d",&n);
		for (int i=0;i<n;i++){
			for (int j=0;j<2;j++){
				scanf("%s",s1);
				if (!msi[j][s1]) msi[j][s1]=++cnt[j];
				a[j][i]=msi[j][s1];
			}
		}
		int flag=1,ans=0,cnt;
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				if (a[0][i]==a[0][j]&&a[1][i]==a[1][j]) flag=0;
		if (flag)
		for (int j=1;j<(1<<n);j++){
			flag=1;
			cnt=0;
			memset(valid,0,sizeof valid);
			for (int k=0;k<n;k++)
				if ((1<<k)&j) valid[0][a[0][k]]=valid[1][a[1][k]]=1;
			for (int k=0;k<n;k++)
				if (!((1<<k)&j)) 
					{
						cnt++;
						if (valid[0][a[0][k]]+valid[1][a[1][k]]!=2) {flag=0;}
					}
			if (flag) ans=max(ans,cnt);
		}
		printf("Case #%d: ", ++ca);
		printf("%d\n", ans);
	}
}