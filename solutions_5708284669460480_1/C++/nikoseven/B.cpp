#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


char sk[200];
char st[200];
int l;
int p[200];
void kmp() {
	char *s = st;
	p[0] = -1;
	for(int i=0;i<l-1;++i) {
		int j = p[i];
		while( j!=-1 && s[i+1] != s[j+1] )
			j = p[j];
		if( s[i+1] == s[j+1] )
			p[i+1] = j+1;
		else
			p[i+1] = -1;
	}
}
int k,s;



char kbd[256];
int nkbd;
double probcnt[256];
double prob[256];

bool vis[110][110][110];
double f[110][110][110];

double dp(int step,int js,int k) {
	if( k < 0 )
		return 0.0;
	if( step == s ) {
		if( js == l-1 )
			return (k == 1)?1.0:0.0;
		else
			return (k == 0)?1.0:0.0;
		return 0.0;
	}
	if( vis[step][js+1][k] )
		return f[step][js+1][k];
	vis[step][js+1][k] = true;
	double rv = 0.0;
	for(int i=0;i<nkbd;++i) {
		char c = kbd[i];
		int j = js;
		
		if(j==l-1)
			j = p[j];
		
		while( j!=-1 && st[j+1] != c )
			j = p[j];
		if( st[j+1] == c )
			++j;
		rv += prob[i] * dp(step+1,j,k-(js==l-1));
	}
	return f[step][js+1][k] = rv;
}

double pp[1000];

int main() {
	int T,ics = 0;
	scanf("%d",&T);
	while(T--) {
		cin >> k >> l >> s;
		cin >> sk >> st;
		kmp();
		for(int i=0;i<256;++i)
			probcnt[i] = 0;
		for(int i=0;i<k;++i)
			probcnt[(int)sk[i]] += 1.0 / k;
		
		strcpy(kbd,sk);
		sort(kbd,kbd+k);
		nkbd = unique(kbd,kbd+k) - kbd;
		for(int i=0;i<nkbd;++i)
			prob[i] = probcnt[(int)kbd[i]];
		
		int mx = 0;
		double ss = 0;
		for(int i=0;i<=s;++i)for(int j=0;j<=l;++j)for(int z=0;z<=s;++z)
			vis[i][j][z] = false;
		for(int i=0;i<=s;++i) {
			pp[i] = dp(0,-1,i);
			if( pp[i] > 0.0 ) {
				mx = i;
				ss += pp[i] * i;
			}
		}
		
		printf("Case #%d: %.8lf\n",++ics,mx-ss);
	}
	return 0;
}