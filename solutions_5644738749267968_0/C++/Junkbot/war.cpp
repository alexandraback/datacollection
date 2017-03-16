#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 1005;

int N;
double naomi[MAX_N];
double ken[MAX_N];
bool done[MAX_N];

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        for(int i=0;i<MAX_N;i++) {
            done[i] = false;
        }

        scanf("%d",&N);

        for(int i=0;i<N;i++) {
            scanf("%lf",&naomi[i]);
        }

        for(int i=0;i<N;i++) {
            scanf("%lf",&ken[i]);
        }

        sort(naomi, naomi+N);
        sort(ken, ken+N);

        int best = 0;
        for(int i=0;i<N;i++) {
            int here = 0;
            for(int j=i;j<N;j++) {
                if(naomi[j] > ken[j-i]) {
                    here++;
                }
            }

            best = max(best, here);
        }

        int tot = 0;
        for(int i=0;i<N;i++) {
            int index = -1;
            for(int j=0;j<N;j++) {
                if(!done[j] && ken[j] > naomi[i]) {
                    index = j;
                    break;
                }
            }

            if(index == -1) {
                for(int j=0;j<N;j++) {
                    if(!done[j]) {
                        index = j;
                        break;
                    }
                }
            }

            done[index] = true;
            if(ken[index] < naomi[i]) {
                tot++;
            }
        }

        printf("Case #%d: %d %d\n",z,best,tot);
    }

    return 0;
}
