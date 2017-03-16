#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,l,r) for(int i = l;i <= r;++ i)
#define Max(a,b) (a > b ? a : b)
using namespace std;
int n,m,mx[105],my[105],a[105][105],T;

void solve()
{
    scanf("%d%d",&n,&m);
	rep(i,1,n) mx[i] = 0;
	rep(j,1,m) my[j] = 0;
	rep(i,1,n)
	 rep(j,1,m){
	    scanf("%d",&a[i][j]);
		mx[i] = Max(a[i][j],mx[i]);
		my[j] = Max(a[i][j],my[j]);
	 }
	rep(i,1,n)
	 rep(j,1,m)
	 if(a[i][j] != mx[i] && a[i][j] != my[j]){
	    puts("NO"); return;
	 }
	puts("YES");
}
int main()
{
	//freopen("input","r",stdin); freopen("output","w",stdout);
    scanf("%d",&T);
	rep(t,1,T){
	   printf("Case #%d: ",t);
	   solve();
	}
	return 0;
}
