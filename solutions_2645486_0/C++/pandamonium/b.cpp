#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int mem[10][15],E,R,N;
int v[15];
int dp(int e, int n){
	if(n==N-1) return e*v[N-1];
	if(mem[e][n]>=0) return mem[e][n];
	mem[e][n]=0;
	for(int x=0;x<=e;x++){
		mem[e][n]=max(mem[e][n],dp(min(e-x+R,E),n+1)+v[n]*x);
	}
	return mem[e][n];
}
int main(){
	int t,cnt=0;
	scanf("%d",&t);
	while(t--){
		cnt++;
		memset(mem,-1,sizeof(mem));
		scanf("%d %d %d",&E,&R,&N);
		for(int x=0;x<N;x++){
			scanf("%d",&v[x]);
		}
		printf("Case #%d: %d\n",cnt,dp(E,0));
	}
	return 0;
}
