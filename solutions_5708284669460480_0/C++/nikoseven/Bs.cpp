#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

char sk[200];
char st[200];

int k,l,s;
char ss[200];
int nhit = 0;
int mx = 0;
void dfs(int d) {
	if(d == s) {
		ss[d] = '\0';
		int thisHit = 0;
		for(int i=0;i+l<=d;++i) {
			int j;
			for(j=0;j<l;++j) 
				if( st[j] != ss[i+j] )
					break;
			if( j == l ) {
				++thisHit;
			}
		}
		nhit += thisHit;
		mx = max(thisHit,mx);
		return;
	}
	for(int i=0;i<k;++i) {
		ss[d] = sk[i];
		dfs(d+1);
	}
}

int main() {
	int T,ics = 0;
	scanf("%d",&T);
	while(T--) {
		cin >> k >> l >> s;
		cin >> sk >> st;
		mx = 0;
		nhit = 0;
		dfs(0);
		printf("Case #%d: %.8lf\n",++ics,mx-nhit/pow(k,s));
	}
	return 0;
}