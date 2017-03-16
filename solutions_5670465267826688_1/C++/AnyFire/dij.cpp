#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 10005;

const int W[5][5] = 
{{0,0,0,0,0}, {0,1,2,3,4}, {0,2,-1,4,-3}, {0,3,-4,-1,2}, {0,4,3,-2,-1}};

int w(int x, int y)
{
	int d(0), r;
	if(x<0) d^=1, x=-x;
	if(y<0) d^=1, y=-y;
	
	r = W[x][y];
	if(d) r=-r;
	return r;
}

LL R;
int n, a[N];
int l[N], r[N];

int y[N];

int rd()
{
	int c;
	while(c=getchar(), c<=' ');
	return c;
}

int f[N<<2], opl, opr, ans;
void built(int x, int l, int r)
{
	if(l==r) {f[x]=a[l]; return;}
	
	int md = (l+r)>>1;
	built(x+x, l, md), built(x+x+1, md+1, r);
	f[x] = w(f[x+x], f[x+x+1]);
}

void qu(int x, int l, int r)
{
	if(opl <= l && r <= opr) {ans = w(ans, f[x]); return;}
	
	int md = (l+r)>>1;
	if(opl<=md) qu(x+x, l, md);
	if(opr>md) qu(x+x+1, md+1, r);
}

int work()
{
	scanf("%d%I64d", &n, &R);
	for(int i=1; i<=n; i++) a[i] = rd() - 'i' + 2;
	
	int g(1), c(0);
	for(int i=1; i<=n; i++) g = w(g, a[i]);
	y[0] = 1;
	for(int i=1; ; i++) { y[i] = w(y[i-1], g); if(y[i]==1) {c=i; break;} }
	
	l[0] = 1;
	for(int i=1; i<=n; i++) l[i] = w(l[i-1], a[i]);
	
	r[n+1] = 1;
	for(int i=n; i; i--) r[i] = w(a[i], r[i+1]);
	
	built(1, 1, n);
	
	for(int i=0; i<c; i++)
	for(int a=1; a<=n; a++) if(w(y[i],l[a])==2) // i
	for(int k=0; k<c; k++) 
	for(int b=n; b; b--) if(w(r[b],y[k])==4) // k
	{
		// encounter
		if(a<b-1 && (R-i-k-1)%c==0 && i+k+1<=R)
		{
			opl=a+1, opr=b-1, ans=1, qu(1,1,n);
			if(ans==3) return 1; 
		}
		// do not
		if(i+k+2<=R)
		{
			int d = int((R-i-k-2) % c);
			if(w(w(r[a+1], y[d]), l[b-1])==3) return 1;
		}
	}
	
	return 0;
}

int main()
{
	freopen("dij.in", "r", stdin);
	freopen("dij.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for(int i=1; i<=T; i++)
	if(work()) printf("Case #%d: YES\n", i);
	else printf("Case #%d: NO\n", i);
	
	/*
	for(int i=-4; i<=4; i++) if(i)
	{
		printf("Round %d\n", i);
		for(int j=1, k=i; j<=10; j++, k=w(k,i)) printf("%d ", k);
		puts("");
	}
	*/
	return 0;
}
