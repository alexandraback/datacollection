#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define upd(a,b) (a)=min((a),(b))
typedef long long ll;

ll T, k, l, s, maxhits;
char key[10], targ[10], build[10];
double ans, am;

void rec(int i) {
	if(i == s) {
		ll hits = 0;
		for(int a = 0; a < s && a+l-1 < s; a++) {
			bool bad = 0;
			for(int b = a; b-a < l && b < s; b++) {
				if(targ[b-a] != build[b]) {
					bad = 1;
					break;
				}
			}
			if(!bad) hits++;
		}
		maxhits = max( maxhits, hits);
		ans += hits;
		am += 1;
		return;
	}
	for(int j = 0; j < k; j++) {
		build[i] = key[j];
		rec(i+1);
	}
}

int main(){
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%lld\n", &T);
	for(int z = 1; z <= T; z++) {
		for(int i = 0; i < 10; i++) key[i] = targ[i] = build[i] = 0;
		scanf("%lld %lld %lld\n", &k, &l, &s);
		scanf("%s\n%s " , key, targ);
		maxhits = 0;
		ans = 0;
		am = 0;
		rec(0);
		ans = (ans / am);
		ans = maxhits - ans;
		printf("Case #%d: %.7lf\n", z, ans);
	}
}
