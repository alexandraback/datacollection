#include<bits/stdc++.h>

using namespace std;

int T,J,P,S,K,arr[20][20][20],cnt1[200],cnt2[200],cnt3[200],ans[1005][5],tot;

int main(){
int a,b,c;
	freopen("fashion.in","r",stdin);
	freopen("fashion.out","w",stdout);

	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		
		scanf("%d%d%d%d",&J,&P,&S,&K);
		memset(arr,0,sizeof(arr));
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		memset(cnt3,0,sizeof(cnt3));
		
		a=1; b=1; c=1; tot=0;
		while (a<=J){
			if (cnt1[a*10+b]<K && cnt2[b*10+c]<K && cnt3[a*10+c]<K){
				tot++;
				ans[tot][1]=a; ans[tot][2]=b; ans[tot][3]=c;
				cnt1[a*10+b]++; cnt2[b*10+c]++; cnt3[a*10+c]++;
			}
			
			c++;
			if (c>S){
				c=1; b++;
			}
			if (b>P){
				b=1; a++;
			}
		}		
		printf("Case #%d: %d\n",i,tot);
		for(int j=1;j<=tot;j++){
			printf("%d %d %d\n",ans[j][1],ans[j][2],ans[j][3]);
		}
	}
	
	return 0;
}
