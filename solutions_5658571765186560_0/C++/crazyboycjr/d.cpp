#include <cstdio>
#include <cstring>

using namespace std;
#define rep(i,l,r) for (int i=(l);i<=(r);i++)

const int maxn=100;

namespace small {
	void solve(int X,int n,int m) {
		if (X==1) puts("GABRIEL");
		if (X==2) puts((n*m%2==0)?"GABRIEL":"RICHARD");
		if (X==3) {
			if (n>=2&&m>=2&&n*m%3==0)
				puts("GABRIEL");
			else puts("RICHARD");
		}
		if (X==4) {
			if (n*m==16||n*m==12)
				puts("GABRIEL");
			else puts("RICHARD");
		}
	}
}

int n,m,X;

int main() {
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int T;scanf("%d\n",&T);
	rep(t,1,T) {
		printf("Case #%d: ",t);
		scanf("%d%d%d\n",&X,&n,&m);
		small::solve(X,n,m);
	}
	return 0;
}
