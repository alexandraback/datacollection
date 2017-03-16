#include <stdio.h>
#include <cmath>

using namespace std;

typedef long long ll;

const ll MAX = 1000*1000*10 + 1;
ll mask[MAX];

inline bool pal(ll x){
	ll d = (MAX-1)*(MAX-1);
	while(!(x/d)) d /= 10;
	while(d){
		if(x%10 != (x/d)%10)
			return false;
		d /= 100;
		x /= 10;
	}
	return true;	
}

inline void init(){
	for(int i=1;i<MAX;i++)
		mask[i] = mask[i-1] + (pal(i) && pal(i*i));
}

inline ll ans(int l, int r){
	return mask[r]-mask[l-1];
}

inline ll findL(ll x){
	return (ll)sqrt(x)+!((ll)sqrt(x)*(ll)sqrt(x) == x);
}

inline ll findR(ll x){
	return (ll)sqrt(x);
}

int main(){
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
    int T;
 	scanf("%d\n", &T);
 	init();
 	ll l, r;
 	for(int t=1;t<=T;t++){
		scanf("%I64d %I64d\n", &l, &r);
        printf("Case #%d: %I64d\n", t, ans(findL(l), findR(r)));		
	}
	return 0;
}
