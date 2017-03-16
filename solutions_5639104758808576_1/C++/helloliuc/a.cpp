#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=1;cas<=T;cas++) {
        int smax;
        char s[1100];
        scanf("%d%s", &smax, s);
        int ans = 0;
        int sum = 0;
        for(int i=0;s[i]; i++) {
            if(sum < i) {
                ans += i - sum;
                sum += i - sum;
            }
            sum += s[i] - '0';
        }
        printf("Case #%d: %d\n", cas, ans);
    }

    return 0;
}
