#include <stdio.h>
int n,shy[1005];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int testt;
	scanf("%d",&testt);
	for(int test=1;test<=testt;test++){
		scanf("%d", &n);
		for(int i=0;i<=n;i++)
			scanf("%1d",&shy[i]);
		for(int ans=0;;ans++){
			int sum=ans+shy[0];
			int i;
			for(i=1;i<=n;i++){
				if(shy[i]==0 || sum>=i)
					sum+=shy[i];
				else break;
			}
			if(i==n+1){
				printf("Case #%d: %d\n",test,ans);
				break;
			}
		}
	}
	return 0;
}
