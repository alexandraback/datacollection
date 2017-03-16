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
int n;
bool a[2600];
void Main(int Cas){
	memset(a,0,sizeof a);
	scanf("%d",&n);
	rep(i,1,2*n-1){
		rep(j,1,n){int x;scanf("%d",&x);a[x]^=1;}
	}
	printf("Case #%d: ",Cas);
	rep(i,1,2500)if(a[i])printf("%d ",i);
	printf("\n");
}
int main(){
	int T;scanf("%d",&T);
	rep(Cas,1,T)Main(Cas);
	return 0;
}


