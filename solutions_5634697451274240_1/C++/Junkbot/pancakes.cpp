#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;

char buf[MAX_N];

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        scanf(" %s ",buf);
        int N = strlen(buf);

        char cur = '+';
        int ans = 0;
        for(int i=N-1;i>=0;i--) {
            if(buf[i] != cur) {
                if(cur == '+') {
                    cur = '-';
                } else {
                    cur = '+';
                }
                ans++;
            }
        }

        printf("Case #%d: %d\n",z,ans);
    }

    return 0;
}
