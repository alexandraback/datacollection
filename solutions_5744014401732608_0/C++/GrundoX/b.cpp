#include <bits/stdc++.h>
using namespace std;

#define fo(x,y,z) for(int x=y;x<z;x++)
typedef long long ll;
int tc;

int main(){
	scanf("%d", &tc);
	fo(x,1,tc+1){
		printf("Case #%d: ", x);
		ll n, m;
		scanf("%lld %lld", &n, &m);
		if(m > (1LL << (n-2))){
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("POSSIBLE\n0");
		if(m == (1LL << (n-2))){
		   	fo(i,1,n) printf("1");
		}
		else{
			bool yes[55];
			fo(i,0,n) yes[i] = 0;

			ll a = m;
			int ind = n-2;
			while(a > 0){
				if(a&1) yes[ind] = 1;
				ind--;
				a >>= 1;
			}
			fo(i,1,n){
				printf("%d",yes[i]?1:0);
			}
		}
		printf("\n");
		fo(i,1,n){
			fo(j,0,n){
				printf("%d",j<=i?0:1);
			}
			printf("\n");
		}
	}
	return 0;
}
