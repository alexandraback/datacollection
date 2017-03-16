#include <bits/stdc++.h>
using namespace std;
int t,k,c,s;
typedef long long ll;
int main(){
	scanf("%d",&t);
	for(int w=1;w<=t;w++){
		printf("Case #%d:",w);
		scanf("%d %d %d",&k,&c,&s);
		if(s*c<k){printf(" IMPOSSIBLE\n");continue;}
		if(k==1){printf(" 1\n");continue;}
		int cnt=0;
		ll v=0ll;
		for(int d=0;d<k;d++){
			v=v*ll(k)+ll(d);
			cnt++;
			if(cnt==c){
				printf(" %lld",v+1ll);
				cnt=0;
				v=0ll;
			}
		}
		if(v!=0ll) printf(" %lld",v+1ll);
		printf("\n");
	}
	return 0;
}
