#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<map>
#include<string.h>
#include<set>
typedef long long lnt;
int ans[100],a[200][100],x[100][3];
bool use[200];
int main(){
	int n,k,i,T,t=0,c,min,in;
	freopen("B-large.in","r",stdin);
	freopen("pBout.txt","w",stdout);
	scanf("%d",&T);
	while(T--){
		int n;
		t++;
	 	scanf("%d",&n);
	 	memset(ans,0,sizeof(ans));
	 	memset(use,0,sizeof(use));
	 	for(k=1;k<=2*n-1;k++){
	 		for(i=1;i<=n;i++){
	 			scanf("%d",&a[k][i]);
	 			//printf("%d ",a[k][i]);
	 		}
	 		//puts("");
	 	}
	 	//puts("");
	 	for(k=1;k<=n;k++){
	 		min=10000;x[k][0]=x[k][1]=0;
	 		for(i=1;i<=2*n-1;i++){
	 			if(use[i]) continue;
	 			if(a[i][k]<min){
	 				min=a[i][k];
	 				x[k][0]=i;x[k][1]=0;
	 			}
	 			else if(a[i][k]==min){
	 				x[k][1]=i;
	 			}
	 		}
	 		//printf("QQ %d %d\n",x[0],x[1]);
	 		use[x[k][0]]=1;
	 		use[x[k][1]]=1;
	 		if(x[k][1]==0) in=k;
	 	}
	 	ans[in]=a[x[in][0]][in];
	 	for(k=1;k<=n;k++){
	 		if(k==in) continue;
	 		if(a[x[in][0]][k]==a[x[k][0]][in]) ans[k]=a[x[k][1]][in];
	 		else ans[k]=a[x[k][0]][in];
	 	}
	 	printf("Case #%d: ",t);
	 	for(k=1;k<=n;k++) printf("%d ",ans[k]);
	 	puts("");
	
	}
}
