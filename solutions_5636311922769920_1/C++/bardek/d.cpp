#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inft = 1000000009;
const int MOD = 1000000007;
const int MAXN = 1000006;
int k,c,s;
LL dorzuc(vi v){
	LL ret=0;
	while(v.size()<c) v.pb(0);
	fru(i,v.size()){
		ret*=k;
		ret+=v[i];
	}
	return ret;
}

int main(){
	int o;
	scanf("%d",&o);
	fru(oo,o){
		 printf("Case #%d:",oo+1);
		 scanf("%d%d%d",&k,&c,&s);
		 if(s<(k+c-1)/c){
			 puts(" IMPOSSIBLE");
			 continue;
		 }
		 vi now;
		 fru(i,k){
			 now.pb(i);
			 if(now.size()==c || i+1==k){
				printf(" %lld",dorzuc(now)+1);
			 	now.clear();
			 }
		 }
		 puts("");
	}
    return 0;
}
