#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int T, N, n[1000], sumn, ord[1000];
double m[1000];

int cmp(const void* a, const void* b) {
    int A = *(int*)a, B = *(int*)b;
    return n[A] - n[B];
}

int main()
{
    scanf("%d", &T);
    for(int z=1; z<=T; ++z) {
        sumn = 0;
        scanf("%d", &N);
        for(int i=0; i<N; ++i) {
            scanf("%d", &n[i]);
            ord[i] = i;
            sumn += n[i];
            m[i] = 0.0;
        }
        qsort(ord, N, sizeof(int), cmp);
        int tsumn = sumn;
        for(int i=1; i<N; ++i) {
            int diff = n[ord[i]] - n[ord[i-1]];
            if(diff*i<tsumn) {
                tsumn -= diff*i;
                for(int j=0; j<i; ++j) {
                    m[ord[j]] += diff;
                }
                //printf ("c");
            }
            else {
                for(int j=0; j<i; ++j) {
                    m[ord[j]] += double(tsumn) / i;
                }
                tsumn = 0.0;
                break;
            }
        }
        for(int i=0; i<N; ++i) {
            m[i] += double(tsumn) / N;
            m[i] /= sumn;
            m[i] *= 100;
        }
        if(N==1) {
            m[0] = 0.0;
        }
        printf("Case #%d:", z);
        for(int i=0; i<N; ++i) {
            printf(" %.10f", m[i]);
        }
        printf("\n");
    }
    return 0;
}
