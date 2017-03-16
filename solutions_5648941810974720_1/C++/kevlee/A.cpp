#include <bits/stdc++.h>
using namespace std;
int T, n, f[30], g[15];
char s[2005];
int main () {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	for (int test=1; test<=T; test++) {
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		memset(s, 0, sizeof s);
		scanf("%s", s);
		n=strlen(s);
		for (int i=0; i<n; i++) f[s[i]-'A']++;
		int b=f['Z'-'A'];
		g[0]+=b;
		f['Z'-'A']-=b;	f['E'-'A']-=b;	f['R'-'A']-=b;	f['O'-'A']-=b;
		b=f['X'-'A'];
		g[6]+=b;
		f['S'-'A']-=b;	f['I'-'A']-=b;	f['X'-'A']-=b;	
		b=f['U'-'A'];
		g[4]+=b;
		f['F'-'A']-=b;	f['O'-'A']-=b;	f['U'-'A']-=b;	f['R'-'A']-=b;
		b=f['R'-'A'];
		g[3]+=b;
		f['T'-'A']-=b;	f['H'-'A']-=b;	f['R'-'A']-=b;	f['E'-'A']-=b; f['E'-'A']-=b;
		b=f['W'-'A'];
		g[2]+=b;
		f['T'-'A']-=b;	f['W'-'A']-=b;	f['O'-'A']-=b;	
		b=f['G'-'A'];
		g[8]+=b;
		f['E'-'A']-=b;	f['I'-'A']-=b;	f['G'-'A']-=b;	f['H'-'A']-=b; f['T'-'A']-=b;
		b=f['F'-'A'];
		g[5]+=b;
		f['F'-'A']-=b;	f['I'-'A']-=b;	f['V'-'A']-=b;	f['E'-'A']-=b;
		b=f['V'-'A'];
		g[7]+=b;
		f['S'-'A']-=b;	f['E'-'A']-=b;	f['V'-'A']-=b;	f['E'-'A']-=b; f['N'-'A']-=b;
		b=f['O'-'A'];
		g[1]+=b;
		f['O'-'A']-=b;	f['N'-'A']-=b;	f['E'-'A']-=b;
		g[9]+=f['N'-'A']/2;
		printf("Case #%d: ", test);
		for (int i=0; i<10; i++) {
			for (int j=0; j<g[i]; j++) printf("%d", i);
		}
		printf("\n");
	}
}
