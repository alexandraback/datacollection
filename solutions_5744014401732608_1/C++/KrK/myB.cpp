#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int t;
int B;
ll M;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
	    printf("Case #%d: ", tc);
        cin >> B >> M;
        if ((1ll << ll(B - 2)) < M) printf("IMPOSSIBLE\n");
        else {
            printf("POSSIBLE\n");
            printf("0");
            ll cur = B - 3;
            for (int i = 2; i <= B; i++) {
                if (M >= (1ll << cur)) { printf("1"); M -= (1ll << cur); }
                else printf("0");
                cur = max(cur - 1, 0ll);
            }
            printf("\n");
            for (int i = 2; i <= B; i++) {
                for (int j = 1; j <= B; j++)
                    printf("%c", i < j? '1': '0');
                printf("\n");
            }
        }
	}
	return 0;
}
