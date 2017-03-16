#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000

typedef pair<int, int> ii;
typedef long long ll;

void binary(ll n) {
    if(n/2 != 0)
        binary(n/2);
    printf("%lld", n%2);
}

int main() {
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc) {
        printf("Case #%d: ", tc);
        int B; ll M; scanf("%d%lld", &B, &M);
        if(M > (1LL << B-2))
            printf("IMPOSSIBLE\n");
        else {
            printf("POSSIBLE\n0");
            if(M == (1LL << B-2))
                for(int i = 0; i < B-1; ++i)
                    printf("1");
            else {
                cout << bitset<64>(M).to_string().substr(64-B+2, B-2);
                printf("0");
            }
            printf("\n");
            for(int i = 2; i <= B; ++i) {
                for(int j = 0; j < B; ++j)
                    printf("%c", (j < i) ? '0' : '1');
                printf("\n");
            }
        }
    }
}

