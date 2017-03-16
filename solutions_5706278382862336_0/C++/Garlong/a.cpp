#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const double kEPS = 1E-9;
const int kSize = 1024;

int cmp_asc(const void* p1, const void *p2) {
    return *(int*)p1 - *(int*)p2;
}

int cmp_desc(const void* p1, const void *p2) {
    return *(int*)p2 - *(int*)p1;
}

int64_t gcd(int64_t x, int64_t y)
{ if(y == 0) return x; if(x < y)      return gcd(y,x);
    else        return gcd(y, x%y);
}

int main() {
    int cnt_case = 0;
    scanf("%d", &cnt_case);
    int case_idx = 0;
    while (cnt_case--) {
        ++case_idx;

        // compute here
        int64_t p,q;
        scanf("%lld/%lld", &p, &q);
        
        int64_t dividor = gcd(p,q);
        p /= dividor;
        q /= dividor;
        bool possible = true;
        int cnt = 0;

        while (p < q) {
            if (q % 2) {
                possible = false;
                break;
            }

            q /= 2;
            ++cnt;
        }

        while (q>1) {
            if (q % 2) {
                possible = false;
                break;
            }

            q /= 2;
        }

        printf("Case #%d: ", case_idx);
        
        if (possible) {
            printf("%d\n", cnt);
        } else {
            printf("impossible\n");
        }
        // output here
    }
    return 0;
}
