#include <cstdlib>
#include <cstdio>
#include <memory.h>

struct TChest {
    int type;
    int nkey;
    int keys[41];
};

int N, K;
bool Visit[1<<21];
int Inven[21];
int Order[21];
TChest Chest[21];
bool Possible;
void go(int depth, int bit) {
    if (depth == N || Possible) {
        Possible = true;
        return;
    }
    if (Visit[bit]) return;
    Visit[bit] = true;
    
    for (int i = 0; i < N; ++i) {
        if ((bit & (1<<i)) == 0) {
            if (Inven[Chest[i].type] > 0) {
                Inven[Chest[i].type] -= 1;
                for (int k = 0; k < Chest[i].nkey; ++k) Inven[Chest[i].keys[k]] += 1;
                
                Order[depth] = i;
                go(depth + 1, bit | (1<<i));
                if (Possible) return;
                
                for (int k = 0; k < Chest[i].nkey; ++k) Inven[Chest[i].keys[k]] -= 1;
                Inven[Chest[i].type] += 1;
            }
        }
    }
}

int main() 
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        memset(Visit, 0, sizeof(Visit));
        memset(Inven, 0, sizeof(Inven));
        memset(Order, 0, sizeof(Order));
        memset(Chest, 0, sizeof(Chest));
        Possible = false;

        scanf("%d%d", &K, &N);
        for (int i = 0; i < K; ++i) {
            int key;
            scanf("%d", &key);
            Inven[key] += 1;
        }
        for (int i = 0; i < N; ++i) {
            scanf("%d%d", &Chest[i].type, &Chest[i].nkey);
            for (int j = 0; j < Chest[i].nkey; ++j) {
                int key;
                scanf("%d", &key);
                Chest[i].keys[j] = key;
            }
        }
        go(0, 0);

        printf("Case #%d:", t);
        if (Possible) {
            for (int i = 0; i < N; ++i) printf(" %d", Order[i] + 1);
        } else {
            printf(" IMPOSSIBLE");
        }
        printf("\n");
    }
    return 0;
}
