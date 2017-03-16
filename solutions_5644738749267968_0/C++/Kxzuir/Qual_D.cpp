#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int T,m,n,tmp;
double naomi[1001],ken[1001];
int main()
{
	freopen("Qual_D.in","r",stdin);freopen("Qual_D.out","w",stdout);
	cin>>T;
	for(int Case=1;Case<=T;Case++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lf",&naomi[i]);
		for(int i=1;i<=n;i++) scanf("%lf",&ken[i]);
		sort(naomi+1,naomi+1+n);
		sort(ken+1,ken+1+n);
	//	for(int i=1;i<=n;i++)printf("%.3lf ",naomi[i]);printf("\n");
	//	for(int i=1;i<=n;i++)printf("%.3lf ",ken[i]);printf("\n");
		int p=1,q=1,ans=0;
		while(p<=n&&q<=n){
			if(ken[q]<naomi[p])q++;else ans++,q++,p++;
		}
		int ans2=n-ans;ans=0,p=1,q=1;
		while(p<=n&&q<=n){
			if(naomi[q]<ken[p])q++;else ans++,q++,p++;
		}
		printf("Case #%d: ",Case);
		printf("%d %d\n",ans,ans2);
	}
}






