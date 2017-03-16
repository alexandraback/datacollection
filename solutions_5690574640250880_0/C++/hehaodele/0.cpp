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
int n,m,k;
int a[100][100];

bool test(int x, int y){
	memset(a, 0, sizeof(a));
	int now = k - (x*m+y*n-x*y);
	if(now<0) return 0;
	rep(i,x)rep(j,m) a[i][j] = 1;
	rep(i,n)rep(j,y) a[i][j] = 1;
	for(int i = x, j = y; now; now--){
		while(j>=m-2 && i<n-2) i++, j = y;
		if(i>=n-2) return 0;
		a[i][j] = 1;
		j++;
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	int cass = getint();
	repp(cas,1,cass){
		n = getint(), m = getint(), k = getint();
		bool ok = 0;
		memset(a, 0, sizeof(a));
		if(n==1){
			ok = 1;
			rep(j,k) a[0][j] = 1;
		}else if(m==1){
			ok = 1;
			rep(i,k) a[i][0] = 1;
		}else if(k==n*m-1){
			ok = 1;
			rep(i,n)rep(j,m) a[i][j] = 1;
		}else{

		rep(i,n-1) if(!ok){
			rep(j,m-1) if(test(i,j)) {ok = 1;//printf("ok %d %d\n",i,j );
				break;}
		}

		}
		printf("Case #%d:\n", cas);
		if(!ok) printf("Impossible\n"); else{
			rep(i,n){
				rep(j,m){
					if(i==n-1 && j==m-1) printf("c"); else
					printf("%c", a[i][j]?'*':'.');
				}
				printf("\n");
			}
		}
	}
	return 0;
}