#include <bits/stdc++.h>
using namespace std;

int n;
bool has[10];

void solve() {
	scanf("%d",&n);
	memset(has,0,sizeof has);
	for (int i=1;i<=1000;i++) {
		int cur = i*n;
		string s = to_string(cur);
		for (char c: s) has[c-'0'] = 1;
		if (*min_element(has,has+10)==1) {
			printf("%d\n",cur);
			return;
		}
	}
	printf("INSOMNIA\n");
}

int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++) {
		printf("Case #%d: ",t);
		solve();
	}

	return 0;
}
