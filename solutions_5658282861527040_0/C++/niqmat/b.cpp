#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
#include <set>

using namespace std;
const int MAXN = 1000000;

int a, b, k, t;

int main() {
    scanf("%d", &t);
    for(int f = 1; f <= t; ++f) {
        scanf("%d %d %d", &a, &b, &k);
        int cnt = 0;
        for(int i = 0; i < a; ++i) {
            for(int j = 0; j < b; ++j) {
                if((i & j) < k) {
                    //printf("(%d,%d)\n", i,j);
                    ++cnt;
                }
            }
        }
        printf("Case #%d: %d\n", f, cnt);
    }
    return 0;
}
