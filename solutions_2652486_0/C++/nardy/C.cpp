#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define rep(i,l,r) for(int i = l;i <= r;++ i)
using namespace std;
int n,m,k,r,T,a,b,c,pro[10];

bool check(int x,int a,int b,int c)
{
    if(x == 1) return true;
	if(a == x || b == x || c == x) return true;
	if(a * b == x || b * c == x || a * c == x) return true;
	if(a * b * c == x) return true;
	return false;
}
void solve()
{
	rep(i,1,k) scanf("%d",&pro[i]);
	rep(i,2,m)
	 rep(j,2,m)
	  rep(q,2,m){
	     bool flag = true;
		 rep(p,1,k)
		 if(!check(pro[p],i,j,q)){
		    flag = false; break;
		 }
		 if(flag){
		    printf("%d%d%d\n",i,j,q); return;
		 }
	  }
	printf("333\n");
}
int main()
{
	freopen("input","r",stdin); freopen("output","w",stdout);
    scanf("%d",&T);
	puts("Case #1:");
	scanf("%d%d%d%d",&r,&n,&m,&k);
	rep(i,1,r) 
	   solve();
	return 0;
}
