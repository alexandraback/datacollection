#include <cstdio>
#include <algorithm>

using namespace std;

int p[1111];
const int INF = 987654321;

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t; ++ti){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%d", &p[i]);
        }
        int ans = INF;
        for(int th = 1; th <= 1000; ++th){
            int s = 0;
            for(int i = 0; i < n; ++i){
                s += (p[i] - 1) / th;
            }
            ans = min(ans, s + th);
        }
        printf("Case #%d: %d\n", ti, ans);
    }
    return 0;
}
