#include <cstdio>
#include <cstring>

using namespace std;
#define rep(i,l,r) for (int i=(l);i<=(r);i++)

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
			if (n>=3&&m>=3&&n*m%4==0)
				puts("GABRIEL");
			else puts("RICHARD");
		}
	}
}

int n,m,X;

void solve(int X,int n,int m) {
	if (X==5) {
		if (n>=4&&m>=4&&n*m%5==0)
			puts("GABRIEL");
		else puts("RICHARD");
	}
	if (X==6) {
		if (n>=4&&m>=4&&n*m%6==0)
			puts("GABRIEL");
		else puts("RICHARD");	
	}
	if (X>=7) {
		puts("RICHARD");
	}
}

int main() {
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int T;scanf("%d\n",&T);
	rep(t,1,T) {
		printf("Case #%d: ",t);
		scanf("%d%d%d\n",&X,&n,&m);
		if (X<=4)
			small::solve(X,n,m);
		else {
			solve(X,n,m);
		}
	}
	return 0;
}
