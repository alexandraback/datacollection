#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 110
#define mo 1000000007
#define int64 long long
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
struct ww {
	int l,r,a;
} a[N];
int i,j,k,n,m,te,test,t,s,u;
int f[N],ff[N],sl[N],sr[N];
char p[N];
int64 an,g[N];
inline void P() {
	printf("Case #%d: 0\n",te);
}
void dfs(int x) {
	int i;
	f[x]=1;
	For(i,1,t) if (a[i].l==x) break;
	if (i>t) return;
	dfs(a[i].r);
}
int main() {
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	scanf("%d",&test);
	For(te,1,test) {
		scanf("%d",&n);
		For(i,0,N-1) g[i]=sl[i]=sr[i]=f[i]=0;
		t=0; s=0;
		For(i,1,n) {
			scanf("%s",p+1);
			m=strlen(p+1);
			for (j=2;j<=m&&p[j]==p[1];j++);
			int A=p[1]-'a';
			s|=1<<A;
			if (j==m+1) g[A]++;
			else {
				++t;
				a[t].l=p[1]-'a';
				a[t].r=p[m]-'a';
				a[t].a=0;
				s|=1<<p[m]-'a';
				sl[p[1]-'a']++;
				sr[p[m]-'a']++;
				
				if (p[1]==p[m]) {
					P();
					goto yy1;
				}
				for (j=1;j<=m&&p[j]==p[1];j++);
				for (k=m;k&&p[k]==p[m];k--);
				For(u,0,N-1) ff[u]=0;
				for (;j<=k;j=u) {
					for (u=j;u<=k&&p[u]==p[j];u++);
					if (ff[p[j]-'a']) {
						P();
						goto yy1;
					}
					ff[p[j]-'a']=1;
					a[t].a|=1<<(p[j]-'a');
				}
			}
		}
		For(i,1,t) if (s&a[i].a) {
			P();
			goto yy1;
		}
		For(i,1,t)For(j,i+1,t) if (a[i].a&a[j].a) {
			P();
			goto yy1;
		}
		For(i,0,25) if (sl[i]>1||sr[i]>1) {
			P();
			goto yy1;
		}
		an=1;
		For(i,0,25)For(j,1,g[i]) an=an*j%mo;
		k=0;
		For(i,0,25) {
			if (sl[i]>0&&!sr[i]) k++,dfs(i);
			if (!sl[i]&&!sr[i]&&g[i]) k++;
		}
		For(i,0,25) if (sl[i]>0&&!f[i]) {
			P();
			goto yy1;
		}
		For(i,1,k) an=an*i%mo;
		printf("Case #%d: %lld\n",te,an);
		yy1:;
	}
	return 0;
}
