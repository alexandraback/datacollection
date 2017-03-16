#include<cstdio>
#include<algorithm>
#define LL long long 
#define E 5
#define N 10
using namespace std;

LL pd[N][E+1];
int cs[N][E+1],cass;
LL v[N];
int r,n,maxe;

LL solve(int p,int e){
	if(p==n) return 0;

	LL& ans = pd[p][e];
	int& cas = cs[p][e];
	if(cas==cass) return ans;
	ans = 0;
	cas=cass;
	for(int i=0;i<=e;++i){
		int ne=e-i+r;
		if(ne>maxe) ne=maxe;
		ans = max(ans,v[p]*i + solve(p+1,ne) );
	}
	return ans;

}

int main(){
	int T;scanf("%d",&T);
	for(int caso=1;caso<=T;++caso){
		cass++;
		scanf("%d%d%d",&maxe,&r,&n);
		for(int i=0;i<n;++i)
			scanf("%lld",v+i);
		printf("Case #%d: %lld\n",caso,solve(0,maxe) );
	}
	return 0;
}
