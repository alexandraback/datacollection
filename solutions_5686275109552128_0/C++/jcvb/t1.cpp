#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;


int n;
int cnt[1005];
int mi[1005];
int main(){
	freopen("me.in","r",stdin);
	freopen("me.out","w",stdout);
	int tes;scanf("%d",&tes);
	for (int tt=1;tt<=tes;tt++){
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		while(n--){
			int x;scanf("%d",&x);
			cnt[x]++;
		}
		int ans=1000;
		for (int i=1;i<=1000;i++){
			int su=0;
			for (int j=1;j<=1000;j++)su+=cnt[j]*((j-1)/i);
			ans=min(ans,su+i);
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
			

