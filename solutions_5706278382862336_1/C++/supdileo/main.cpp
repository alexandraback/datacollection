#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

bool ge(ll P,ll Q,ll b){
	return b*P>=Q;
}

ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	freopen("A-large.in","r",stdin);
	freopen("out","w",stdout);

	int nCase;
	scanf("%d",&nCase);
	for(int nc=1;nc<=nCase;nc++){
		ll P,Q;
		scanf("%lld/%lld",&P,&Q);
		ll ret = 0,b = 1;
		while(ret<40&&!ge(P,Q,b)){
			b = b<<1;
			ret ++;
		}
		ll round = ret,Dvi,Denom,_gcd;
		while(round<=40&&P){
			if(ge(P,Q,b)){
				_gcd = gcd(Q,b);
				Dvi = Q/_gcd*b;
				Denom = b/_gcd*P-Q/_gcd;
				P = Denom,Q=Dvi;
			}
			round ++;
			b = b<<1;
			}
		if(P)printf("Case #%d: impossible\n",nc);
		else printf("Case #%d: %d\n",nc,ret);
	}
	return 0;
}

