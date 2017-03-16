#include <cstdio>
#include <algorithm>
using namespace std;

#ifdef DEBUG
#define D(x...) fprintf(stderr,x)
#else
#define D(x...)
#endif

const int MAX_N = 2*1005;
int T;

int N;
bool done[MAX_N];
bool used[MAX_N];

pair<int,int> one[MAX_N];
pair<int,int> two[MAX_N];

void reset(void) {
    for(int i=0;i<MAX_N;i++) {
        done[i] = false;
        used[i] = false;
        one[i].first = MAX_N;
        two[i].first = MAX_N;
        one[i].second = MAX_N;
        two[i].second = MAX_N;
    }
}

int main() {
    scanf("%d",&T);

    for(int t=1;t<=T;t++) {
        reset();
        scanf("%d",&N);

        for(int i=0;i<N;i++) {
            scanf("%d %d",&one[i].first,&two[i].first);
            one[i].second = i;
            two[i].second = i;
        }

        sort(one, one+N);
        sort(two, two+N);

        int upOne = 0;
        int upTwo = 0;
        bool suck = false;
        int tot = 0;
        int times = 0;
        while(upTwo < N && !suck) {
            while(tot < two[upTwo].first) {
                if(upOne >= N) {
                    suck = true;
                    break;
                }
              
                if(!done[one[upOne].second] && tot >= one[upOne].first) {
                    used[one[upOne].second] = true;
                    tot++;
                    times++;
                }
                upOne++;
            }

            if(!suck) {
                done[two[upTwo].second] = true;
                tot++;
                if(!used[two[upTwo].second]) {
                    tot++;
                }
                upTwo++;
            }
        }

        printf("Case #%d: ",t);
        if(suck) {
            printf("Too Bad");
        } else {
            printf("%d",times + N);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
