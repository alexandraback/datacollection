#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define rep(i,l,r) for(int i = l;i <= r;++ i)
#define Min(a,b) (a < b ? a : b)
#define Max(a,b) (a > b ? a : b)
using namespace std;
int n,x,y,T,sum[10];

void solve()
{
    scanf("%d%d%d",&n,&x,&y);
	x = abs(x); y = abs(y);
	if(x > 6 || y > 6){
	   puts("0.0"); return;
	}
    int th = (x + y) / 2 + 1;
	if(n <= sum[th - 1]){
	   puts("0.0"); return;
	}else n -= sum[th - 1];
    if(n < y + 1 || (x == 0 && n < sum[th])){
	   puts("0.0"); return;
	}
	if(n >= (th - 1) * 2 + y + 1){
	   puts("1.0"); return;
	}
	double A = 1.0,B = 0.0,C = 0.0;
	rep(i,1,n) A = A * i;
	rep(i,Max(0,n - 2 * (th - 1)),2 * (th - 1)){
	   double tmp = A;
	   rep(j,1,i) tmp /= j;
	   rep(j,1,n - i) tmp /= j;
	   B += tmp;
	}
	rep(i,y + 1,Min(n,2 * (th - 1))){
	   double tmp = A;
	   rep(j,1,i) tmp /= j;
	   rep(j,1,n - i) tmp /= j;
	   C += tmp;
	}
	printf("%.8lf\n",C / B);
}
int main()
{
	freopen("input","r",stdin); freopen("output","w",stdout);
    scanf("%d",&T);
	sum[1] = 1; sum[2] = 6; sum[3] = 15; sum[4] = 28;
	rep(t,1,T){
	   printf("Case #%d: ",t);
	   solve();
	}
	return 0;
}
