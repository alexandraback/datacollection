#include <cstdio>
#include <cstring>
#define REP(i,n) for (int i=1;i<=n;++i)
using namespace std;

int T,n;
char s[110];
int a[110];
int b[110];

int main() {
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	REP(T_T,T) {
		printf("Case #%d: ", T_T);
		scanf("%s",s);
		n=strlen(s);
		REP(i,n) {
			if (s[i-1]=='-') a[i]=0;
			else a[i]=1;
		}
		b[0]=0;
		REP(i,n)
			if (i==1 || a[i]!=a[i-1])
				b[++b[0]]=a[i];
		if (b[0] && b[b[0]]==1) --b[0];
		printf("%d\n",b[0]);
	}
	return 0;
}