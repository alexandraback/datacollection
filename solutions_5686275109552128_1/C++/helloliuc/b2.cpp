#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int d,p[1100];
int cnt[1100];

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++) {
        int m = 0;
        memset(cnt, 0, sizeof(cnt));
        scanf("%d",&d);
        for(int i=0; i<d;i++) {
            scanf("%d",&p[i]);
        }

        int ans = 1100;
        for(int last = 1; last <= 1000; last++) {
            int sum = 0;
            for(int i=0;i<d;i++) {
                sum += (p[i] - 1) / last;
            }
            if(sum + last < ans) {
                ans = sum + last;
            }
        }

        printf("Case #%d: %d\n", cas, ans);
    }

    return 0;
}
