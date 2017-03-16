#include <cstdio>
#define REP(i,n) for (int i=1;i<=n;++i)

using namespace std;

int T;
int x,aa,ans;
int a[10];

bool check(int x) {
	while (x) {
		if (!a[x % 10]) {
			a[x%10] = true;
			++aa;
		}
		x/=10;
	}
	return aa == 10;
}

int calc(int x) {
	REP(i,1000) {
		if (check(x * i)) return i;
	}
	return -1;
}

int main() {
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	REP(T_T,T) {
		printf("Case #%d: ", T_T);
		scanf("%d", &x);
		aa = 0;
		REP(i,10) a[i-1] = false;
		ans = calc(x);
		if (ans == -1) puts("INSOMNIA");
		else printf("%d\n",ans*x);
	}
	return 0;
}