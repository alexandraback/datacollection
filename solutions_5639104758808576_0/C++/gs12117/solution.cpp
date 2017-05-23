#include<stdio.h>
int tcn,tc;
int n;
char a[1010];
int main(){
	int i,sum,ans;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d%s",&n,a);
		ans=0;
		sum=0;
		for(i=0;i<=n;i++){
			sum+=a[i]-'0';
			if(sum==0)ans++;
			else sum--;
		}
		printf("Case #%d: %d\n",tc,ans);
	}
}