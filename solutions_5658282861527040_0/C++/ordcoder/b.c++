#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
void E(){}template<class A,class...B>void E(A _,B...$){cerr<<' '<<_;E($...);}
#define E($...) E(#$,'=',$,'\n')

void process() {
	int a, b, k;
	cin >> a >> b >> k;
	int ans = 0;
	for (int l = 0; l < a; ++l)
		for (int r = 0; r < b; ++r)
			if ((l & r) < k)
				++ans;
	printf("%d\n", ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	int tcases;
	cin >> tcases;
	for (int tcase = 1; tcase <= tcases; ++tcase) {
		printf("Case #%d: ", tcase);
		process();
	}
	return 0;
}
