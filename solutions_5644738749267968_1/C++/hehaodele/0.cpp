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
const int maxn = 10010, maxm = 1000010;
int n,m,k;
double a[maxn], b[maxn];

int dev(){
	int j = 0, k = 0;
		rep(i, n){
			while(j<n && a[j]<b[i])j++;
			if(j==n)break;
			k++;j++;
		}
	return k;
}
int war(){
	set<double>s;
	rep(i, n) s.insert(b[i]);
	int k = 0;
	rep(i, n){
		set<double>::iterator it;
		it = s.upper_bound(a[i]);
		if(it==s.end()){
			s.erase(s.begin());
			k++;
		}else{
			s.erase(it);
		}
	}
	return k;
}
int main(int argc, char const *argv[])
{
	int cass = getint();
	repp(cas,1,cass){
		n = getint();
		rep(i, n) scanf("%lf", &a[i]);
		rep(i, n) scanf("%lf", &b[i]);
		sort(a, a+n), sort(b, b+n);
		printf("Case #%d: %d %d\n",cas, dev(), war());
	}
	return 0;
}