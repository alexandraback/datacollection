#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 1005;

int N;
char buf[MAX_N];

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        scanf(" %d %s ",&N,buf);
        
        int ans = MAX_N;

        for(int x=0;x<=N;x++) {
            int tot = x;
            bool ok = true;
            for(int i=0;i<=N;i++) {
                int here = buf[i]-'0';
                if(here > 0) {
                    if(tot >= i) {
                        tot += (int)(buf[i]-'0');
                    } else {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) {
                ans = x;
                break;
            }
        }
        printf("Case #%d: %d\n",z,ans);
    }

    return 0;
}
