#include <bits/stdc++.h>

using namespace std;

#define Long long long
#define ld long double
#define pii pair<int, int>
#define pli pair<Long, int>

const int me = 125;
const int mod = 1.e9 + 7;
const int MAX_LOG = 20;

int t, k, c, s;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &t);
    for(int cc = 0; cc < t; cc ++){
        scanf("%d%d%d", &k, &c, &s);
        assert(k == s);
        printf("Case #%d: ", cc + 1);
        for(int i = 1; i <= k; i ++)
            printf(" %d", i);
        printf("\n");
    }

    return 0;
}
