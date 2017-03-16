#include<cstdio>
#include<cstdlib>
#include<cstring>

#include<vector>

using namespace std;

#define MAX_NUM 20
#define MEMO_NUM (1 << 20)
char memo[MEMO_NUM];

int N;
int keys[201];
struct chest {
    int key_type;
    vector<int> keys;
};

void init_memo() {
    memset(memo, 0, sizeof(memo));
}

int seq[MAX_NUM]; // 1‚ð•Ô‚·‚Æ‚«‚Éˆê‚Âˆê‚Â–„‚ß‚Ä‚¢‚­
chest chests[MAX_NUM];
int state;

#define FLAG(n) (1 << (n))

int search(int n) {
    int i, j;
    if(n > N) { // ‘S•”‚ ‚¢‚½
        return 1;
    }

    for(i = 0; i < N; ++i) {
        int t = FLAG(i);
        int save = state;
        if(state & t) continue; // ‚·‚Å‚É‚ ‚¢‚Ä‚é
        if(keys[chests[i].key_type]) {
            // ŠJ‚¯‚Ä‚Ý‚é
            state |= t;
            if(memo[state]) { // ‚â‚Á‚½‚±‚Æ‚ ‚éó‘Ô‚¾‚Á‚½‚ç‚â‚ß‚é
                state = save;
                continue;
            }
            --(keys[chests[i].key_type]);
            for(j = chests[i].keys.size()-1; j >= 0; --j) {
                ++(keys[chests[i].keys[j]]);
            }

            if(search(n+1)) { // Œ©‚Â‚©‚Á‚½‚Ì‚Åƒƒ‚‚µ‚Ä‹A‚é
                seq[n-1] = i+1;
                return 1;
            }
            // Œ©‚Â‚©‚ç‚È‚©‚Á‚½‚Ì‚ÅŒãˆ—‚µ‚Ä‘±‚¯‚é
            // ƒƒ‚‰»
            memo[state] = 1;
            // ‹t‘€ì
            state = save;
            ++(keys[chests[i].key_type]);
            for(j = chests[i].keys.size()-1; j >= 0; --j) {
                --(keys[chests[i].keys[j]]);
            }
        }
    }

    return 0;
}


int main() {
    int num;
    int i, j, k, l;
    int K;

    scanf("%d", &num);
    for(i = 1; i <= num; ++i) {
        scanf("%d %d", &K, &N);
        // init
        init_memo();
        memset(keys, 0, sizeof(int)*201);
        for(j = 0; j < N; ++j) {
            chests[j].keys.clear();
        }
        state = 0;

        for(j = 0; j < K; ++j) {
            scanf("%d", &k);
            ++(keys[k]);
        }
        for(j = 0; j < N; ++j) {
            scanf("%d", &(chests[j].key_type));
            scanf("%d", &k);
            for(l = 0; l < k; ++l) {
                int t;
                scanf("%d", &t);
                chests[j].keys.push_back(t);
            }
        }

        printf("Case #%d:", i);
        if(search(1)) {
            for(j = 0; j < N; ++j) {
                printf(" %d", seq[j]);
            }
            printf("\n");
        }
        else {
            printf(" IMPOSSIBLE\n");
        }
        fflush(stdout);
    }

    return 0;
}



