#include <cstdio>
#include <algorithm>
#define MAXN 1000001
using namespace std;
typedef unsigned long long int ull;
ull M[MAXN];
int t,cas,i,n;
int _min(int x, int y){
	return (x<y?x:y);
}
int _dp(int ma, int cur){
	//printf("M[%d]=%d %d\n",cur,M[cur],ma);
	//if(ma<=0) return 0;
	if(cur>=n) return 0;
	if(M[cur]<ma) return _dp(ma+M[cur],cur+1);
	if(M[cur]<ma+ma-1) return 1+_dp(ma+ma+M[cur]-1,cur+1);
	if(ma<=1) return (1+_dp(ma,cur+1));
	int op=0,aux=ma;
	while(ma<=M[cur]){ ma+=ma-1; op++; }
	if(op==0) return (1+_dp(aux,cur+1));
	//printf("1) %d %d\n",ma,cur);
	return _min(1+_dp(aux,cur+1),op+_dp(ma+M[cur],cur+1));
}
int main(){
	ull a;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){
		scanf("%llu %d",&a,&n);
		for(i=0;i<n;i++)
			scanf("%llu",&M[i]);
		sort(M,M+n);
		printf("Case #%d: %d\n",cas,_dp(a,0));
	}
	return 0;
}
