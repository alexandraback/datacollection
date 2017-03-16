#include <bits/stdc++.h>
using namespace std;

#define FOR(i, to, from) for(int i=to; i<from; i++)
#define ri(n) scanf("%d", &n)

typedef long long ll;

ll K, C, S;
const int MAXC=150;
ll potk[MAXC];
int T;

ll generar(ll a){
	ll res = 1;
	FOR(i, 0, C) res+=(a+i)*potk[C-i-1];
	return res;
}
ll caso1(){
	ll res=1;
	FOR(i, 0, K) res+=i*potk[K-i-1];
	return res;
}

int main(){
	potk[0]=1;
	ri(T);
	FOR(t, 1, T+1){
		printf("Case #%d:", t);
		scanf("%lld %lld %lld", &K, &C, &S);
		FOR(i, 1, MAXC) potk[i] = potk[i-1]*K;
		if(S*C<K){
			printf("IMPOSSIBLE\n");
			continue;
		}
		S = (K+C-1)/C;
		if (S==1) printf(" %lld\n", caso1());
		else{
			FOR(i, 0, S-1) printf(" %lld", generar(C*i));
			printf(" %lld\n", generar(K-C));
		}
	}
}
