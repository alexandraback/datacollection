#include <cstdio>

#undef DEBUG
#ifdef DEBUG
#define D(x...) fprintf(stderr,x)
#else
#define D(x...)
#endif

const int MAX_N = 1005;

int T;

int N;
bool adjmat[MAX_N][MAX_N];
int ways[MAX_N][MAX_N];
bool done[MAX_N];

void reset(void) {
    for(int i=0;i<MAX_N;i++) {
        for(int j=0;j<MAX_N;j++) {
            ways[i][j] = 0;
            adjmat[i][j] = false;
        }
        done[i] = false;
    }
}

bool find(int start) {
    for(int i=0;i<N;i++) {
        if(adjmat[start][i]) {
            if(!done[i]) {
                done[i] = true;
                if(find(i)) {
                    return true;
                }
            }

            for(int j=0;j<N;j++) {
                ways[start][j] += ways[i][j];
                D("ways[%d][%d] = %d\n",start,j,ways[start][j]);
                if(ways[start][j] > 1) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    scanf("%d",&T);

    for(int t=1;t<=T;t++) {
        reset();
        scanf("%d",&N);

        for(int i=0;i<N;i++) {
            int k;
            scanf("%d",&k);

            for(int j=0;j<k;j++) {
                int l;
                scanf("%d",&l);
                l--;
                ways[l][i] = 1;
                adjmat[l][i] = true;
            }
        }

        bool works = false;
        for(int i=0;i<N;i++) {
            if(!done[i]) {
                done[i] = true;
                if(find(i)) {
                    works = true;
                    break;
                }
            }
        }

        printf("Case #%d: ",t);
        if(works) {
            printf("Yes");
        } else {
            printf("No");
        }
        printf("\n");
    }
    return 0;
}
