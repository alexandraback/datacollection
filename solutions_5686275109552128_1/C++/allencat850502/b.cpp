#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int N;
int p[1010];
int check(int m){
	int res=0;
	for(int i=0;i<N;i++){
		if(p[i]>m){
			res+=(p[i]/m)-(p[i]%m==0?1:0);
		}else break;
	}
	return res+m;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d",&N);
		int sum=0;
		int mx=0;
		for(int i=0;i<N;i++){
			scanf("%d",&p[i]);
			sum+=p[i];
			mx=max(mx,p[i]);
		}
		sort(p,p+N);
		reverse(p,p+N);
		int ans=0x3f3f3f3f;
		for(int i=1;i<=mx;i++){
			ans=min(ans,check(i));
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
