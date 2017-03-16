#include <cstdio>
#include <cstring>
using namespace std;

int T, N, n[1000];
int cnt[10000000], last[10000000];

int main()
{
    scanf("%d", &T);
    for(int z=1; z<=T; ++z) {
        memset(cnt, 0, sizeof(cnt));
        cnt[0] = 1, last[0] = 0;
        scanf("%d", &N);
        for(int i=0; i<N; ++i) {
            scanf("%d", &n[i]);
        }
        printf("Case #%d:\n", z);
        bool found = false;
        for(int i=0; i<N && found==false; ++i) {
            for(int j=5000000; j>=0; --j) {
                if(cnt[j-n[i]]) {
                    if(cnt[j]) {
                        int p1 = j, p2 = j;
                        int c1 = last[j], c2 = n[i];
                        printf("%d", c1);
                        p1 -= c1;
                        c1 = last[p1];
                        while(c1) {
                            printf(" %d", c1);
                            p1 -= c1;
                            c1 = last[p1];
                        }
                        printf("\n");
                        printf("%d", c2);
                        p2 -= c2;
                        c2 = last[p2];
                        while(c2) {
                            printf(" %d", c2);
                            p2 -= c2;
                            c2 = last[p2];
                        }
                        printf("\n");
                        found = true;
                        break;
                    }
                    else {
                        ++cnt[j];
                        last[j] = n[i];
                    }
                }
            }
        }
        if(!found) {
            printf("Impossible");
        }
    }
    return 0;
}
