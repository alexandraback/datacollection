#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		int b;
		long long m;
		scanf("%d %lld", &b, &m);
		printf("Case #%d: ", kase);
		if(m > (1ll << (b - 2))) printf("IMPOSSIBLE\n");
		else {
			printf("POSSIBLE\n");
			vector<string> ans(b);
			for(int i = 1; i < b; i++) {
				for(int j = 0; j < b; j++)
					if(j <= i) ans[i] += "0";
					else ans[i] += "1";
			}
			if(m == (1ll << (b - 2))) {
				ans[0] = "0";
				for(int i = 1; i < b; i++) ans[0] += "1";
			} else {
				ans[0].resize(b, '0');
				int ind = b - 2;
				while(m > 0) {
					if(m % 2 == 1) ans[0][ind] = '1';
					m /= 2;
					ind--;
				}
			}
			for(auto s: ans) printf("%s\n", s.c_str());
		}
	}

	return 0;
}