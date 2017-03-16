#include <bits/stdc++.h>

using namespace std;



#define fr(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;



ll sq[10001000];



char st[1000];
ll a,b;


bool ehPal(ll num){
	sprintf(st, "%lld",num);
	int tam = strlen(st);
	fr(i,0,tam){
		if(st[i] != st[tam-i-1]) return false;
	}
	return true;
}

int t;









int main(){
	fr(i,0,10000001){
		sq[i] = ll(i+1)*(i+1);
	}
	int pnt = 0;
	fr(i,0,10000001){
		if(ehPal(i+1) && ehPal(sq[i])) sq[pnt++] = sq[i];
	}
	scanf("%d",&t);
	fr(cas,1,t+1){
		scanf("%lld %lld",&a,&b);
		int p1 = lower_bound(sq, sq+pnt, a)-sq;
		int p2 = upper_bound(sq,sq+pnt,b)-sq-1;
		printf("Case #%d: ",cas);
		printf("%d\n",max(0,p2-p1+1));
	}
	return 0;
}













































