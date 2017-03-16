#include <cstdio>
#include <cstring>

char buf[1000006];
char map[256];

int main(void) {
    int t, k;

    map['a'] = 1;
    map['e'] = 1;
    map['i'] = 1;
    map['o'] = 1;
    map['u'] = 1;
    
    scanf("%d", &t);
    for (int ti=1; ti<=t; ++ti) {
        scanf("%s %d", buf, &k);
        int n = strlen(buf);
        int start = -1;
        int curstart = 0;
        int cur = 0;
        long long ans = 0;
        for (int i=n-1; i>=0; --i) {
            if (map[buf[i]]) {
                cur = 0;
                curstart = i; 
            } else {
                ++cur;
            }

            if (cur>=k) {
                start = i + k - 1;
            }
            if (start>=0) {
                ans += (n - start);
            }
        }
        printf("Case #%d: %lld\n", ti, ans);

    }
    return 0;
}
