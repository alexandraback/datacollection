#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int,int> P;
typedef long long ll;
#define mp make_pair
#define fi first
#define sc second
int main(){
	{
		printf("Case #1:\n");
		int n,t; cin >> n >> t;
		int sum = 0;
		for(int i=0;i<(1<<(n-2));i++){
			vector<ll>ret;
			for(int a=2;a<=10;a++){
				ll val = 1,x = 1;
				for(int j=0;j<n-2;j++){
					x *= a;
					if(((i>>j)&1)){
						val += x;
					}
				}
				val += x*a;
				for(ll q = 2;q*q<=val;q++){
					if(val%q == 0){
						ret.pb(q); goto nxt;
					}
				}
				goto fail; nxt:;
			}
			printf("1");
			for(int j=n-3;j>=0;j--){
				printf("%d",((i>>j)&1));
			}
			printf("1");
			for(int j=0;j<ret.size();j++){
				printf(" %lld",ret[j]);
			}
			puts(""); sum++;
			if(sum == t) break;
			fail:;
		}
	}
}