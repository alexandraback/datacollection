#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)

int cases;
int c[2555];
int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &cases);
	fo(_case,1,cases+1) {
		printf("Case #%d: ", _case);
		int n;
		fo(i,0,2555) c[i] = 0;
		scanf("%d", &n);
		fo(i,0,(2*n-1)*n) {
			int a;
			scanf("%d", &a);
			c[a]++;
		}
		vector<int> ans;
		fo(i,0,2555) if (c[i]%2 != 0) printf("%d ", i);
		puts("");
	}

	return 0;
}