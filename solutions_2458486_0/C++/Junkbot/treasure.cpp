#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#undef DEBUG
#ifdef DEBUG
#define D(x...) fprintf(stderr,x)
#else
#define D(x...)
#endif

const int MAX_N = 21;
const int MAX_TYPES = 205;
const int UNCOMPLETED = -2;
const int IMPOSSIBLE = -1;

int N;

int unlock[MAX_N];
vector<int> keys[MAX_N];

int current[MAX_TYPES];

// cache[mask] = -2 if uncompleted, next chest to unlock, or -1 if impossible
int cache[(1 << MAX_N)];

void reset(void);
bool dp(int mask);

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        printf("Case #%d: ", z);
        reset();

        int K;

        scanf("%d %d",&K,&N);

        for(int i=0;i<K;i++) {
            int a;
            scanf("%d",&a);
            a--;
            current[a]++;
        }

        for(int i=0;i<N;i++) {
            int k;
            scanf("%d %d",&unlock[i],&k);
            unlock[i]--;

            for(int j=0;j<k;j++) {
                int a;
                scanf("%d",&a);
                a--;
                keys[i].push_back(a);
            }
        }

        if(dp(0)) {
            int cur = 0;
            for(int i=0;i<N;i++) {
                printf("%d ",cache[cur]+1);
                cur |= (1 << cache[cur]);
            }
            printf("\n");
        } else {
            printf("IMPOSSIBLE\n");
        }
    }
    
    return 0;   
}

void reset(void) {
    for(int i=0;i<(1<<MAX_N);i++) {
        cache[i] = UNCOMPLETED;
    }

    for(int i=0;i<MAX_TYPES;i++) {
        current[i] = 0;
    }

    for(int i=0;i<MAX_N;i++) {
        keys[i].clear();
    }
}

bool dp(int mask) {
#ifdef DEBUG
    D("* dp(%d): ",mask);
    for(int i=0;i<5;i++) {
        D("%d ",current[i]);
    }
    D("\n");
#endif
    if(mask == (1<<N)-1) {
        return true;
    }

    cache[mask] = IMPOSSIBLE;

    for(int i=0;i<N;i++) {
        if(!(mask & (1<<i)) && current[unlock[i]] > 0) {
            int newMask = mask | (1 << i);
            bool works = false;

            if(cache[newMask] == UNCOMPLETED) {
                current[unlock[i]]--;
                for(int j=0;j<keys[i].size();j++) {
                    current[keys[i][j]]++;
                }

                works |= dp(newMask);

                current[unlock[i]]++;
                for(int j=0;j<keys[i].size();j++) {
                    current[keys[i][j]]--;
                }
            } else {
                works |= (cache[newMask] >= 0);
            }
            
            if(works) {
                cache[mask] = i;
                return true;
            }
        }
    }

    return false;
}
