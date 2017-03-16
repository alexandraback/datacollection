#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int p[1010];
int N;
int count(int m){
	int ret=0;
	for(int i=0;i<N;i++){
		if(p[i]>m){
			ret+=(p[i]/m)-((p[i]%m==0)?1:0);
		}else break;
	}
	return ret+m;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int _mx=0;
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%d",&p[i]);
			_mx=max(_mx,p[i]);
		}
		sort(p,p+N);
		reverse(p,p+N);
		int ans=99999999;
		for(int i=1;i<=_mx;i++){
			ans=min(ans,count(i));
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
