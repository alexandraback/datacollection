#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define FOR(i,f,t) for(int i=f; i<t; i++)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define pb push_back
#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d %d", &x, &y)
#define SYNC ios_base::sync_with_stdio(false)

typedef long long ll;

bool seen[10];
void ref(ll a){
	while(a>0){
		seen[a%10] = true;
		a/=10;
	}
}
bool check(){
	FOR(i,0,10) if(!seen[i]) return false;
	return true;
}

int main(){
	int TC; ri(TC);
	FOR(tc,1,TC+1){
		ll x; scanf("%lld",&x);
		if(x==0){
			printf("Case #%d: INSOMNIA\n",tc);
			continue;
		}
		ms(seen,false);
		ref(x);
		int n=1;
		while(!check()){
			n++;
			ref(x*n);
		}
		printf("Case #%d: %lld\n",tc, x*n);
	}
	
}

