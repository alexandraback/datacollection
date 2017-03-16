#include <cstdio>
#include <list>
#define REP(i,n) for (int i=1;i<=n;++i)
#define FOR(i,n) for (__typeof(n.begin())i=n.begin();i!=n.end();++i)
using namespace std;

const int MAXN = 1010;
int T,n;
list<char> l;
char s[MAXN];
int a[MAXN];
int ans[MAXN];

void process(int last) {
	if (!last) return;
	int pos=1;
	for (int i=1;i<=last;++i)
		if (a[i]>a[pos]) pos=i;
	for (int i=pos;i<=last;++i) {
		if (a[i]==a[pos]) ans[i]=1;
		else ans[i]=-1;
	}
	process(pos-1);
}

int main() {
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	REP(T_T,T) {
		printf("Case #%d: ",T_T);
		scanf("%s",s);
		n=strlen(s);
		REP(i,n) a[i]=s[i-1];
		process(n);
		l.clear();
		REP(i,n)
			if (ans[i]==1) l.push_front(s[i-1]);
			else l.push_back(s[i-1]);
		FOR(p,l) printf("%c",*p);
		puts("");
	}
	return 0;
}