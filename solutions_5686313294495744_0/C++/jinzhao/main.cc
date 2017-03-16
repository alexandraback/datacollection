#include <map>
#include <string>
#include <cstdio>

using namespace std;

const int N=3000;
const int M=100000;
const int INF=~0u>>1;
struct NetWorkFlow {
	struct Edge {
		int t,f;
		Edge *ne,*p;
		Edge *clear(int tt,int ff,Edge *nee) {
			t=tt;f=ff;ne=nee;
			return this;
		}
	};
	Edge b[M*2];
	Edge *bp,*fe[N],*cur[N];
	int n,s,t;
	int h[N],vh[N];
	void clear(int nn,int ss,int tt) {
		n=nn;s=ss;t=tt;
		for (int i=0;i<n;i++) fe[i]=NULL;
		bp=b;
	}
	void putedge(int x,int y,int f) {
		fe[x]=(bp++)->clear(y,f,fe[x]);
		fe[y]=(bp++)->clear(x,0,fe[y]);
		fe[x]->p=fe[y];
		fe[y]->p=fe[x];
	}
	int aug(int i,int f) {
		if (i==t) return f;
		int minh=n;
		Edge *seg=cur[i],*&j=cur[i];
		do {
			if (j->f) {
				if (h[j->t]+1==h[i]) {
					int tmp=aug(j->t,min(j->f,f));
					if (tmp) {
						j->f-=tmp;
						j->p->f+=tmp;
						return tmp;
					}
				}
				minh=min(minh,h[j->t]+1);
				if (h[s]==n) return 0;
			}
			j=j->ne;
			if (j==NULL) j=fe[i];
		} while (j!=seg);
		if (!--vh[h[i]]) h[s]=n;
		else ++vh[h[i]=minh];
		return 0;
	}
	int flow() {
		int ans=0;
		for (int i=0;i<=n;i++) {
			cur[i]=fe[i];
			h[i]=vh[i]=0;
		}
		vh[0]=n;
		while (h[s]<n) ans+=aug(s,INF);
		return ans;
	}
};

int n, n1, n2;
char s1[30], s2[30];
map<string, int> c1, c2;
NetWorkFlow d;

int main() {
	int t, tt;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d", &n);
		d.clear(n * 2 + 2, 0, n * 2 + 1);
		c1.clear();
		c2.clear();
		n1 = n2 = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%s%s", s1, s2);
			if (c1[s1] == 0) c1[s1] = ++n1;
			if (c2[s2] == 0) c2[s2] = ++n2;
			d.putedge(c1[s1], n + c2[s2], 1);
			d.putedge(0, i, 1);
			d.putedge(n + i, n * 2 + 1, 1);
		}
		int ans = d.flow();
		ans = ans + (n1 - ans) + (n2 - ans);
		ans = n - ans;
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
