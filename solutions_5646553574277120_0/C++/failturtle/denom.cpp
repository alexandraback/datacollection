#include <bits/stdc++.h>

#define sz(z) (int)z.size()
#define fo(i,a,b) for (auto (i) = (a); (i) != (b); (i)++)
#define mp make_pair
#define pb push_back

using namespace std;

int c,d,v;
int ans;
	int good[35];

bool check(int kek) {
	fo(i,0,v+1) good[i] = 0;
	good[0] = 1;
	fo(i,0,31) {
		if (kek&(1<<i)) {
			for (int j = v; j>= 0; j--) {
				if (good[j] && j+i < 35) good[j+i] = 1;
			}
		}
	}
	int cntd = 0;
	fo(i,0,v+1) if (!good[i]) cntd++;
	if (cntd == 0) return 1;
	return 0;
}
int main() {
	int t;
	//freopen("denom.out","w",stdout);
	scanf("%d\n",&t);
	fo(_,1,1+t){ 
		scanf("%d %d %d\n",&c,&d,&v);
		int k;
		int kek;
		kek = 0;
		fo(i,0,d) {
			scanf("%d\n",&k);
			kek+=(1<<k);
		}
		queue <int> q;
		q.push(kek);
		while (!q.empty()) {
			kek = q.front();
			q.pop();
			if (check(kek)) {
				ans = __builtin_popcount(kek)-d;
				break;
			}
			fo(i,0,v+1) {
				if (((1<<i)&kek)==0) {
					q.push(kek+(1<<i));
				}
			}
		}
		printf("Case #%d: %d\n",_,ans);
	}
	return 0;
}
