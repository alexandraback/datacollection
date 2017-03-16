#include <bits/stdc++.h>

using namespace std;

#define Long long long
#define ld long double
#define pii pair<int, int>
#define pli pair<Long, int>

const int me = 2025;
const int mod = 1.e9 + 7;
const int MAX_LOG = 20;

int t, n;
int have[15];
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &t);
    for(int c = 0; c < t; c ++){
        scanf("%d", &n);
        Long cur = n, ans = -1;
        int all = 0;
        for(int i = 0; i < 10; i ++)
            have[i] = 0;
        for(int tt = 1 ; tt < 5000; tt ++){
            Long temp = cur;
            while(temp > 0){
                if(!have[temp % 10])
                    all ++, have[temp % 10] = 1;
                temp /= 10;
            }
            if(all == 10){
                ans = cur;
                break;
            }
            cur += n;
        }
        printf("Case #%d: ", c + 1);
        if(ans == -1)
            puts("INSOMNIA");
        else printf("%lld\n", ans);
    }

    return 0;
}
