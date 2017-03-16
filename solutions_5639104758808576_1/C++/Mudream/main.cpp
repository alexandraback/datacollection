#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    int T; scanf("%d", &T);
    for(int lt = 1;lt <= T;lt++){
        int len; scanf("%d", &len);
        char tmp[2001]; scanf("%s", tmp);
        int ans = 0, cnt = 0;
        for(int lx = 0;lx <= len;lx++){
            int det = max(lx-cnt, 0);
            ans += det;
            cnt += tmp[lx] - '0' + det;
        }
        printf("Case #%d: %d\n", lt, ans);
    }
    return 0;
}
