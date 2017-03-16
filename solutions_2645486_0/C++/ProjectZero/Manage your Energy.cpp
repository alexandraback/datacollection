#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10005;
int T;
int E,R,N;
int V[MAXN];

int f(int n,int k){
	if(n<=0) return 0;
	//printf("f(%d,%d)\n",n,k);
	int val = -1000000;
	for(int i=k,j=0;i>=0;i--,j++){
		val = max(val,f(n-1,min(i+R,E)) + V[n]*j);
	//	printf("\tf(%d,%d) = %d\n",n,k,val);
	}
	
	return val;
}


int main(){
	freopen("B-small-attempt6.in","r",stdin);
	FILE *fout = fopen("B-small.out","w");
	
	scanf("%d",&T);
	for(int _i=1;_i<=T;_i++){
		fprintf(fout,"Case #%d: ",_i);
		scanf("%d %d %d",&E,&R,&N);
		R = min(E,R);
		for(int i=1;i<=N;i++) scanf("%d",&V[i]);
		
		int ans = f(N,E);
		printf("Case #%d: %d\n",_i,ans);
		fprintf(fout,"%d\n",ans);
	}
	return 0;
}