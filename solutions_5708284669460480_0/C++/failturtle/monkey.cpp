#include <bits/stdc++.h>
int best;

#define sz(z) (int)z.size()
#define fo(i,a,b) for (auto (i) = (a); (i) != (b); (i)++)
#define mp make_pair
#define pb push_back

using namespace std;

char required[105];
char keyboard[105];

int l,k,s;
int total;
int curtotal;
char me[105];

long double totalPermutation;

void check() {
	totalPermutation++;
	curtotal = 0;
	fo(i,0,s-l+1) {
		bool yes = true;
		fo(j,0,l) {
			if (me[i+j] != required[j]) {
				yes = false;
				break;
			}
		}
		if (yes) curtotal++;
	}
	best = max(curtotal,best);
	total+=curtotal;
}

void build(int at) {
	if (at == s) {
		check();
		return;
	}
	fo(i,0,k) {
		me[at] = keyboard[i];
		build(at+1);
	}
}

int fact[55];
int wr[26];
int main() {
	int t;
	scanf("%d\n",&t);
	fo(i,0,15) fact[i] = fact[i-1]*i;
	freopen("mon.in","w",stdout);
	fo(_,1,1+t) {
		scanf("%d %d %d\n",&k,&l,&s);
		scanf("%s\n%s\n",keyboard,required);
		total = 0;
		best = 0;
		totalPermutation = 0;
		build(0);
		printf("Case #%d: %.6Lf\n",_,(long double)best-total/totalPermutation);
	}
	return 0;
}
