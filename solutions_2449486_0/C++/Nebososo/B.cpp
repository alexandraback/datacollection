#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define VERT 0
#define HOZ 1

using namespace std;

int N, M, T ,TS = 0;
int m[128][128];
int vm[128];
int vh[128];

int main(){
    int i, n;

    for(scanf("%d", &T); T--;){
        scanf("%d %d", &N, &M);
        printf("Case #%d: ", ++TS);

        for(i = 0; i < N; i++)
            for(n = 0; n < M; n++)
                scanf("%d", m[i] + n);

        memset(vm, 0, sizeof(vm));
        memset(vh, 0, sizeof(vh));

        for(i = 0; i < N; i++)
            for(n = 0; n < M; n++){
                vm[i] = max(vm[i], m[i][n]);
                vh[n] = max(vh[n], m[i][n]);
            }

        for(i = 0; i < N; i++)
            for(n = 0; n < M; n++)
                if(m[i][n] < vm[i] && m[i][n] < vh[n]){
                    printf("NO\n");
                    goto denovo;
                }

        printf("YES\n");
        denovo:;
    }

    return 0;
}
