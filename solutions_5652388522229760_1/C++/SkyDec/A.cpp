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
bool has[12];
int main(){
	int T;scanf("%d",&T);
	rep(Cas,1,T){
		memset(has,0,sizeof has);
		int n;scanf("%d",&n);
		if(n==0){printf("Case #%d: INSOMNIA\n",Cas);continue;}
		for(LL x=n;;x+=n){
			LL y=x;
			while(y){
				has[y%10]=1;
				y/=10;
			}
			bool fl=1;
			rep(i,0,9)fl&=has[i];
			if(fl){
				printf("Case #%d: %I64d\n",Cas,x);
				break;
			}
		}
	}
}


