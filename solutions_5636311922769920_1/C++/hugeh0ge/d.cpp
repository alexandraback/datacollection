#include <cstdio>
using namespace std;

typedef long long int LLI;

int T;
LLI k, c, s;

void reduce_segment(LLI &l, LLI &r, int idx) {
    LLI len = r-l;
    l = l + len/k * idx;
    r = l+len/k;
}

int main() {
    scanf("%d", &T);
    for (int Case=1; Case<=T; Case++) {
        scanf("%lld%lld%lld", &k, &c, &s);
        printf("Case #%d:", Case);
        
        LLI require = k/c + (k%c != 0);
        if (require > s) {
            puts(" IMPOSSIBLE");
            continue;
        }

        LLI lim = 1;
        for (int i=0; i<c; i++) {
            lim *= k;
        }

        int idx = 0;
        while (idx < k) {
            LLI l = 0;
            LLI r = lim;
            for (int i=0; i<c; i++) {
                reduce_segment(l, r, idx++);
                if (idx >= k) break;
            }
            printf(" %lld", l+1);
        }
        puts("");
    }
}
