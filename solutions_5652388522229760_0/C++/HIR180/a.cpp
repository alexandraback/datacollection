#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int,int> P;
typedef long long ll;
#define mp make_pair
#define fi first
#define sc second
int main(){
	int t; cin >> t;
	for(int i=0;i<t;i++){
		printf("Case #%d: ",i+1);
		int n; cin >> n;
		if(!n){
			puts("INSOMNIA"); continue;
		}
		bool u[10]={};
		int zan = 10;
		for(ll x=n;;x+=n){
			ll y = x;
			while(y){
				if(u[y%10]==0) zan--;
				u[y%10] = 1;
				y /= 10;
			}
			if(zan==0){
				printf("%lld\n",x); break;
			}
		}
	}
}