#include <cstdio>
#define LL long long
#define REP(i,n) for (int i=1;i<=n;++i)
using namespace std;

int n,m;
int a[110];

void output() {
	REP(i,n) printf("%d", a[i]);
	for (int c=2;c<=10;++c) {
		LL ret=0;
		REP(i,n/2) ret=ret*c+a[i];
		printf(" %lld",ret);
	}
	puts("");
}

int main() {
	freopen("1.out","w",stdout);
	scanf("%d%d",&n,&m);
	puts("Case #1:");
	a[1]=a[n/2]=a[n/2+1]=a[n]=1;
	for (int i=0;i<(1<<(n/2-2));++i) {
		int x=i;
		for (int j=2;j<=n/2-1;++j) {
			a[j]=a[j+n/2]=x%2;
			x/=2;
		}
		output();
		--m;
		if (!m) return 0;
	}
	return 0;
}