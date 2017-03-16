#include <bits/stdc++.h>



using namespace std;




#define fr(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;

int t;
ll r, qtd;


ll f(ll meio){
	return (meio + 2LL*meio*(meio-1)) + 2*r*meio;
}



bool overmult(ll a, ll b){
	if(a == 0 || b == 0) return false;
	ll c = a*b;
	if(c%a == 0 && c%b == 0 && c/a == b && c/b == a) return false;
	return true;
}

bool oversum(ll a, ll b){
	ll c = a+b;
	if((a > 0 && b > 0 && c <= 0) || (a < 0 && b < 0 && c >= 0)) return true;
	return false;
}


bool over(ll meio){
	ll x = 0, y = 0;
	if(!overmult(meio,meio-1)) x = meio*(meio-1);
	else return true;
	if(!overmult(x, 2)) x = x*2;
	else return true;
	if(!oversum(meio,x)) x = x + meio;
	else return true;
	if(!overmult(x, 2)) x = x*2;
	else return true;
	if(!overmult(r,meio)) y = r*meio;
	else return true;
	if(!overmult(y,2)) y = y*2;
	else return true;
	if(!oversum(x,y)) x = x+y;
	else return true;
	return false;
}





int main(){
	scanf("%d",&t);
	fr(cas,1,t+1){
		scanf("%lld %lld",&r,&qtd);
		ll ini = 1, fim = min(qtd+1, 707106781LL);
		while(ini < fim){
			ll meio = (ini+fim)>>1;
			if(f(meio) <= qtd && !over(meio)) ini = meio+1;
			else fim = meio;
		}
		printf("Case #%d: %lld\n",cas,ini-1);
	}
}












































