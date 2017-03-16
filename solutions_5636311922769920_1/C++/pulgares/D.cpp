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

int main(){
	int TC; ri(TC);
	FOR(tc,1,TC+1){
		int K, C, S; scanf("%d%d%d",&K,&C,&S);
		if(S<(K+C-1)/C){
			printf("Case #%d: IMPOSSIBLE\n",tc);
			continue;
		}
		int i=0;
		vector<ll> ans;
		while(i<K){
			ll pos=i; int j=i;
			FOR(c,1,C){
				if(j<K-1) j++;
				pos= pos*K + j;
			}
			i=j+1;
			ans.pb(pos+1);
		}
		printf("Case #%d:",tc);
		FOR(k,0,ans.size()){
			printf(" %lld",ans[k]);
		}
		printf("\n");
	}
}
