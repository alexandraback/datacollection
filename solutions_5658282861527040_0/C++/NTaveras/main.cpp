#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long llong;

int main(int argc, char* argv[]) {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int tc;
    cin >> tc;
    int t = 1;
    while(tc--){
        llong a, b, k;
        cin >> a >> b >> k;
        int cnt = 0;
        for(llong i = 0; i < a; ++i){
            for(llong j = 0; j < b; ++j){
                llong res = i;
                res &= j;
                if(res < k) cnt++;
            }
        }
        printf("Case #%d: %d\n", t, cnt);
        t++;
    }
    return 0;
}
