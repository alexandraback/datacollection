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
const int bit=32;
const int limit=500;
int a[35];
int ans[15];
int cc=0;
void check(){
	rep(base,2,10){
		ans[base]=-1;
		rep(x,2,1000){
			int now=1;
			rep(i,2,bit){
				now=(now*base+a[i])%x;
			}
			if(now==0){
				ans[base]=x;
				break;
			}
		}
		if(ans[base]==-1)return;
	}
	++cc;
	rep(i,1,bit)printf("%d",a[i]);printf(" ");
	rep(i,2,10)printf("%d ",ans[i]);printf("\n");
	if(cc==limit)exit(0);
}
void dfs(int x){
	if(x==bit){
		check();return;
	}
	a[x]=0;dfs(x+1);
	a[x]=1;dfs(x+1);
}
int main(){
	int T;scanf("%d",&T);
	printf("Case #1:\n");
	a[1]=1;
	a[bit]=1;
	dfs(2);
	return 0;
}


