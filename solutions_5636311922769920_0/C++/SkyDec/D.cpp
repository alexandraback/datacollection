#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
int main(){
	int T;scanf("%d",&T);
	rep(Cas,1,T){
		int k,c,s;
		scanf("%d%d%d",&k,&c,&s);
		LL base=1;
		rep(i,1,c-1)base*=1ll*k;
		printf("Case #%d: ",Cas);
		rep(i,1,k)printf("%I64d ",base*i);
		printf("\n");
	}
	return 0;
}


