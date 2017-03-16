#include "cstdio"
#include "iostream"
#include "vector"
#include "algorithm"
#include "cstring"
#include "set"
#include "map"
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define rep(i, n) for(int i=0; i<n; i++)
#define repp(i, a, b) for(int i=a; i<a+b; i++)
using namespace std;
inline int getint(){
  char c = getchar();
  for(;c<'0'||c>'9';) c = getchar();
  int x = 0;
  for(;c>='0' && c<='9'; c = getchar()) x*=10, x+=c-'0';
  return x;
}
const int maxn = 100010, maxm = 1000010;
int n,m,k,a[100];
double c,f,x;
int main(int argc, char const *argv[])
{
	int cass = getint();
	repp(cas,1,cass){
		scanf("%lf%lf%lf",&c,&f,&x);
		double ans = x/2.0, s = 0, r = 2;
		k = 0;
		for(int i=0; k<10;i++){
			s += c/r;
			r += f;
			if(ans < s+x/r) k++;
			ans = min(ans, s+x/r);
			//printf("time %d %.6lf k %d\n",i,s+x/r,k );
		}
		printf("Case #%d: %.6lf\n",cas, ans );
	}
	return 0;
}