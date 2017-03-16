#include <cstdio>
#include <algorithm>
#include <cstring>
#include <assert.h>
using namespace std;

#define MAXL    (2000000)
int L;
char name[MAXL+1];
char ft[MAXL];
int nId[MAXL+1];

static
bool is_con(char z) {
    return (z != 'a') && (z != 'e') && (z != 'i') && (z != 'o') && (z != 'u');
}

int main() {
    int _nT; scanf("%d", &_nT);
    for(int _T=0; _T<_nT; _T++) {
        int n;
        scanf("%s%d", name, &n);
        L = strlen(name);

        {
            int cnt = 0;
            for(int i=0; i<L; i++) {
                int pIdx = i-n;
                if(pIdx >= 0 && is_con(name[pIdx]))
                    cnt--;
                if(is_con(name[i]))
                    cnt++;
                ft[i] = (cnt >= n);
                assert(cnt <= n);
                //printf("cnt %c: %d\n", name[i], cnt);
            }
        }

        {
            nId[L] = L;
            for(int i=L-1; i>=0; i--) {
                nId[i] = ft[i] ? i : nId[i+1];
                //printf("nId[%d] = %d\n", i, nId[i]);
            }
        }

        long long count = 0;
        for(int i=0; i<=(L-n); i++) {
            count += max(0, L - nId[i+n-1]);
        }

        printf("Case #%d: %lld\n", _T+1, count);
    }
    return 0;
}

