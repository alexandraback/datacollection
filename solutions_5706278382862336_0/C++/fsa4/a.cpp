#include <bits/stdc++.h>
#define fr(i, a, b) for(int i = (a); i < (b); i++)
#define inf 0x3F3F3F3F
#define pb push_back
#define ST first
#define ND second

using namespace std;
typedef long long ll;

int main(){
	int t, caso = 1;
	scanf("%d", &t);
	ll p, q;
	char lixo;
	
	while(t--){
		scanf("%lld", &p);
		scanf(" %c", &lixo);
		scanf("%lld", &q);
		ll aux = q;
		
		for(ll i = 2; i*i <= q; i++){
			while(aux%i == 0){
				aux /= i;
			}
			while(q%i == 0 && p%i == 0){
				q /= i;
				p /= i;
			}
		}
		
		if(q%aux == 0 && p%aux == 0){
			q /= aux;
			p /= aux;
		}
		
		int ok = 0;
		for(ll i = 1; i <= ((1LL)<<13); i = (i<<1)){
			if(q == i){
				ok = 1;
				break;
			}
		}
		
		if(!ok){
			printf("Case #%d: impossible\n", caso++);
			continue;
		}
		
		int ans = 0;
		while(p < q){
			if(p < q/2){
				p *= 2;
				ans++;
			}else{
				p = q;
				ans++;
			}
		}		
		
		printf("Case #%d: %d\n", caso++, ans);
			
	}
	
	return 0;
}

