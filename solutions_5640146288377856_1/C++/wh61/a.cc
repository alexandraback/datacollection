#include <iostream>
#include <cstdio>

using namespace std;



int main() {
    freopen("a_in.txt", "r", stdin);
    freopen("a_out.txt", "w", stdout);
    int T, ca = 0;
    scanf("%d", &T);
    while (T--) {
		int R, C, W;
		scanf("%d%d%d", &R, &C, &W);
		int ans = R * (C / W);
		ans += W - 1;
		if (C % W != 0) ans++;
		printf("Case #%d: %d\n", ++ca, ans);
	}
}


