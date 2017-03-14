#include <stdio.h>
#include <math.h>
#include <set>
using namespace std;
#define eps 1E-8
#define N 33
#define K 10000
#define Q 1000000
struct P
{ 
	double x, y;
	P(double x=0, double y=0): x(x), y(y) {}
};
P operator +(P a, P b) { return P(a.x+b.x, a.y+b.y); }
P operator -(P a, P b) { return P(a.x-b.x, a.y-b.y); }
P operator *(P a, double b) { return P(a.x*b, a.y*b); }
double operator &(P a, P b) { return a.x*b.x+a.y*b.y; }
double operator *(P a, P b) { return a.x*b.y-a.y*b.x; }
double operator !(P a) { return sqrt(a&a); }
P operator ~(P a) { return P(-a.y, a.x); }
bool operator <(P a, P b) { return a.x+eps<b.x || (a.x-eps<b.x && a.y+eps<b.y); }
P operator |(P a, P b) { return b*((a&b)/(b&b)); }
P operator ^(P a, P b) { return (a|b)*2-a; }
P a[K], b[K], c[K], z[K];
char m[N][N];
int di[]={-1, 1, 0, 0}, dj[]={0, 0, -1, 1}, u[N][N], l, e, h;
set <int> s;
void dfs(int i, int j)
{
	int k;
	u[i][j]=1;
	for(k=0; k<4; k++)
		if(m[i+di[k]][j+dj[k]]=='.' && !u[i+di[k]][j+dj[k]]) dfs(i+di[k], j+dj[k]);
	if(m[i-1][j-1]=='#')
	{
		if(m[i-1][j]=='#' && m[i][j-1]=='#') c[e++]=P(i, j);
		else if(m[i-1][j]=='#') { a[l]=P(i, j-1); b[l]=P(i, j+1); l++; }
		else if(m[i][j-1]=='#') { a[l]=P(i-1, j); b[l]=P(i+1, j); l++; }
		else z[h++]=P(i, j);
	}
	if(m[i-1][j+1]=='#')
	{
		if(m[i-1][j]=='#' && m[i][j+1]=='#') c[e++]=P(i, j+1);
		else if(m[i-1][j]=='#') { a[l]=P(i, j); b[l]=P(i, j+2); l++; }
		else if(m[i][j+1]=='#') { a[l]=P(i-1, j+1); b[l]=P(i+1, j+1); l++; }
		else z[h++]=P(i, j+1);
	}
	if(m[i+1][j-1]=='#')
	{
		if(m[i+1][j]=='#' && m[i][j-1]=='#') c[e++]=P(i+1, j);
		else if(m[i+1][j]=='#') { a[l]=P(i+1, j-1); b[l]=P(i+1, j+1); l++; }
		else if(m[i][j-1]=='#') { a[l]=P(i, j); b[l]=P(i+2, j); l++; }
		else z[h++]=P(i+1, j);
	}
	if(m[i+1][j+1]=='#')
	{
		if(m[i+1][j]=='#' && m[i][j+1]=='#') c[e++]=P(i+1, j+1);
		else if(m[i+1][j]=='#') { a[l]=P(i+1, j); b[l]=P(i+1, j+2); l++; }
		else if(m[i][j+1]=='#') { a[l]=P(i, j+1); b[l]=P(i+2, j+1); l++; }
		else z[h++]=P(i+1, j+1);
	}
	if(m[i-1][j]=='#') { a[l]=P(i, j); b[l]=P(i, j+1); l++; }
	if(m[i+1][j]=='#') { a[l]=P(i+1, j); b[l]=P(i+1, j+1); l++; }
	if(m[i][j-1]=='#') { a[l]=P(i, j); b[l]=P(i+1, j); l++; }
	if(m[i][j+1]=='#') { a[l]=P(i, j+1); b[l]=P(i+1, j+1); l++; }
}
double sec(P a, P b, P c, P d)
{
	double d0, d1, d2;
	d0=b*d;
	d1=(c-a)*d;
	d2=(c-a)*b;
	if(d0<eps && d1>-eps) return 1E20;
	if(d0<0) { d0=-d0; d1=-d1; d2=-d2; }
	if(d1<eps || d2<eps || d2>d0-eps) return 1E20;
	return d1/d0;
}
bool lie(P a, P b, P c)
{
	return fabs((c-a)*b)<eps && ((c-a)&b)>eps;
}
bool can(P q, P v, double d)
{
	int i, j;
	double g, f;
	P t, p;
	for(t=q; d>-eps; d-=!(t-p), t=p)
	{
		f=1E20;
		j=-2;
		for(i=0; i<l; i++)
		{
			g=sec(t, v, a[i], b[i]-a[i]);
			if(g<f) { f=g; j=i; }
		}
		for(i=0; i<e; i++)
		{
			g=!(c[i]-t)/!v;
			if(lie(t, v, c[i]) && g<f) { f=g; j=-1; }
		}
		for(i=0; i<e; i++)
		{
			g=!(z[i]-t)/!v;
			if(lie(t, v, z[i]) && g<f) { f=g; j=-2; }
		}
		p=t+v*f;
		if(lie(t, v, q) && !(q-t)<!(p-t)+eps && !(q-t)<d+eps) return 1;
		if(j==-2) break;
		else if(j==-1) v=v*(-1);
		else v=v^(b[j]-a[j]);
	}
	return 0;
}
int gcd(int x, int y) { return !y?x:gcd(y, x%y); }
int ab(int x) { return x<0?-x:x; }
void ins(int x, int y)
{
	int g=gcd(ab(x), ab(y));
	s.insert((x/g+1000)*1000+y/g+1000);
}
int main()
{
	int ts, t, i, j, d, r, c;
	P o;
	for(scanf("%d", &ts), t=1; t<=ts; t++)
	{
		for(scanf("%d%d%d", &r, &c, &d), i=0; i<r; scanf("%s", m[i]), i++);
		for(l=0, e=0, h=0, i=0; i<r; i++)
			for(j=0; j<c; u[i][j]=0, j++);
		for(i=0; i<r; i++)
		{
			for(j=0; j<c && m[i][j]!='X'; j++);
			if(j<c) break;
		}
		dfs(i, j);
		o=P(i, j)+P(0.5, 0.5);
		for(s.clear(), i=-d; i<=d; i++)
			for(j=-d; j<=d; j++)
				if((i || j) && i*i+j*j<=d*d && can(o, P(i, j), d)) ins(i, j);
		printf("Case #%d: %d\n", t, s.size());
	}
	return 0;
}