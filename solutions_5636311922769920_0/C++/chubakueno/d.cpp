#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;++z){
		ll k,c,s;
		scanf("%lld%lld%lld",&k,&c,&s);
		printf("Case #%d:",z);
		if(s*c<k){printf(" IMPOSSIBLE\n");continue;}
		for(int i=0;c*i<k;++i){
			ll pot=1;
			ll x=0;
			for(int j=0;j<c;++j) pot*=k;
			for(int j=0;j<c&&c*i+j<k;++j){
				pot/=k;
				x+=pot*(c*i+j);
			}
			printf(" %lld",x+1);
		}
		printf("\n");
	}
}