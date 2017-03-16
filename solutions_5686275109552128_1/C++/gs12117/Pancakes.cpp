#include<stdio.h>
int tcn,tc;
int n;
int p[1010];
int main(){
	int i,j,ans,tans;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&p[i]);
		}
		ans=999999999;
		for(i=1;;i++){
			tans=0;
			for(j=0;j<n;j++){
				tans+=(p[j]-1)/i;
			}
			if(tans+i<ans)ans=tans+i;
			if(tans==0)break;
		}
		printf("Case #%d: %d\n",tc,ans);
	}
}