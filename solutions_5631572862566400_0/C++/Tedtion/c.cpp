#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int setl(int i, int f[], int l[])
{
	if (l[i]>0) return l[i];
	l[i] = setl(f[i], f, l) + 1;
	return l[i];
}

void get_longest(int start, int f[], int l[], int c[])
{
	int i=start;
	while (l[i]==-1) {
		l[i]=0;
		i=f[i];
	}
	int circle_len = 1;
	int j=f[i];
	while (j!=i) {
		circle_len++;
		j=f[j];
	}
	bool danlian = true;
	if (circle_len>2) danlian=false;
	
	// circle
	c[i]=circle_len;
	
	// danlian
	if (danlian==false) return;
	l[i] = l[f[i]] = 2;
	setl(start, f, l);
}

int root(int a, int p[])
{
	int tmp = a;
	while (a!=p[a]) a=p[a];
	int pa = a;
	a = tmp;
	while (p[a]!=pa) {
		tmp = p[a];
		p[a] = pa;
		a = tmp;
	}
	return pa;
}

void merge(int a, int b, int p[])
{
	a = root(a, p);
	b = root(b, p);
	if (a==b) return;
	p[b] = a;
}

int main()
{
	int t,i,j;
	int f[1100], l[1100], c[1100], p[1100];
	
//	freopen("C-large.in", "r", stdin);
//	freopen("B-large.out", "w", stdout);

	scanf("%d", &t);
	for (int cas=1; cas<=t; cas++)
	{
		int n;
		memset(l, -1, sizeof(l));
		memset(c, 0, sizeof(c));
		scanf("%d", &n);
		for (i=1; i<=n; i++) scanf("%d", &f[i]);
		
		for (i=1; i<=n; i++) {
			if (l[i]>=0) continue;
			get_longest(i, f, l, c);
		}
		
		for (i=1; i<=n; i++) p[i]=i;
		for (i=1; i<=n; i++) merge(i, f[i], p);
		for (i=1; i<=n; i++)
		{
			if (l[i]<=0) continue;
			int m = l[i];
			for (j=i+1; j<=n; j++) {
				if (root(i, p)!=root(j,p)) continue;
				if (l[j]>m) m=l[j];
			}
			l[i]=m;
			for (j=i+1; j<=n; j++) {
				if (root(i, p)==root(j,p)) l[j]=0;
			}
		}
			
		int maxl = 0;
		for (i=1; i<=n; i++) maxl += l[i];
		
		int maxc = 0;
		for (i=1; i<=n; i++) if (maxc < c[i]) maxc = c[i];
		
		if (maxc < maxl) {
			printf("Case #%d: %d\n", cas, maxl);
		} else {
			printf("Case #%d: %d\n", cas, maxc);
		}
	}
	return 0;
}
		
