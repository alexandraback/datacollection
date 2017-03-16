#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,l,r) for(int i = l;i <= r;++ i)
#define Min(a,b) (a < b ? a : b)
using namespace std;
const int oo = ~0U>>2;
int A,n,x[105],T;
long long sum;

void solve()
{
    int ans = oo,tmp = 0;
	scanf("%d%d",&A,&n);
	sum = A;
	rep(i,1,n) scanf("%d",&x[i]);
	sort(x + 1,x + 1 + n);
	rep(i,1,n){
	   if(sum <= x[i]){
		  ans = Min(ans,tmp + n - i + 1);
		  if(sum == 1) {tmp = oo; break;}
		  while(sum <= x[i]){
		     ++ tmp; sum += sum - 1;
		  }
	   }
	   sum += x[i];
	   if(tmp > ans) break;
	}
	ans = Min(ans,tmp);
	printf("%d\n",ans);
}
int main()
{
	freopen("input","r",stdin); freopen("output","w",stdout);
    scanf("%d",&T);
	rep(t,1,T){
	   printf("Case #%d: ",t);
	   solve();
	}
	return 0;
}	
