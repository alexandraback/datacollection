#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cmath>

using namespace std;

typedef long long int int64;

int main(){
    int T; scanf("%d", &T);
    for(int lt = 1;lt <= T;lt++){
        int R, C, W; scanf("%d %d %d", &R, &C, &W);
        int t = (C-W)/W;
        int _r = C/W;
        printf("Case #%d: %d\n", lt, _r*(R-1) + t + W + (C-W*t > W));
    }
    return 0;
}
