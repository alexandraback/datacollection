#include <cstdio>
#include <tchar.h>
#include <algorithm>

using namespace std;

int A, N;
int a[100], pre[101], nxt[101];
int _tmain(int argc, TCHAR* argv[])
{
    int i, j, k, pn = 1;
    scanf("%*d");
    while (2 == scanf("%d%d", &A, &N)) {
        for (i = 0; i < N; i++) scanf("%d", &a[i]);
        if (A == 1) {
            printf("Case #%d: %d\n", pn++, N);
            continue;
        }
        sort(a, a + N);
        memset(pre, -1, sizeof(pre));        
        pre[0] = A;
        for (i = 0; i < N; i++) {
            memset(nxt, -1, sizeof(nxt));
            for (j = 0; j <= N; j++) {
                if (pre[j] != -1) {
                    
                    if (pre[j] > a[i]) nxt[j] = max(nxt[j], pre[j] + a[i]); // eatable
                    else { // non-eatable
                        nxt[j + 1] = max(nxt[j + 1], pre[j]); // remove

                        // add
                        int cnt = 0; 
                        int size = pre[j];
                        do {
                            cnt++;
                            size += size - 1;
                        } while (!(size > a[i]));
                        nxt[j + cnt] = max(nxt[j + cnt], size + a[i]);
                    }
                }
            }
            memcpy(pre, nxt, sizeof(pre));
        }
        for (i = 0; i <= N; i++) {
            if (pre[i] != -1) {
                printf("Case #%d: %d\n", pn++, i);
                break;
            }
        }
    }	
}