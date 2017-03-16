#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 15;
const int MAX_E = 10;

int N, E, R;
int value[MAX_N];
int cache[MAX_N][MAX_E];

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        scanf("%d %d %d",&E,&R,&N);

        for(int i=0;i<N;i++) {
            scanf("%d",&value[i]);
        }

        for(int i=0;i<MAX_N;i++) {
            for(int j=0;j<MAX_E;j++) {
                cache[i][j] = 0;
            }
        }

        for(int i=N;i>=0;i--) {
            for(int j=0;j<=E;j++) {
                if(i == N) {
                    cache[i][j] = 0;
                } else {
                    cache[i][j] = cache[i+1][min(E,j+R)];

                    if(j > 0) {
                        cache[i][j] = max(cache[i][j],
                                          cache[i][j-1] + value[i]);
                    }
                }
            }
        }

        printf("Case #%d: %d\n",z,cache[0][E]);
    }
    return 0;
}
