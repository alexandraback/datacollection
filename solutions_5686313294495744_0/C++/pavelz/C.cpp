// Description
// https://code.google.com/codejam/contest/11254486/dashboard#s=p2

#include <bits/stdc++.h>
using namespace std;

#define FOR(c, m) for(int c=0;c<(int)(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)
#define LLI long long int
#define MOD 1000000007

int power(int a, int b) {
    int sq = a;
    int result = 1;
    while (b > 0) {
        if ((b & 1) == 1) result = result * (LLI)sq % MOD;
        sq = sq * (LLI)sq % MOD;
        b >>= 1;
    }
    return result;
}

int inv(int a) {
    return power(a, MOD - 2);
}

void fail() {
    *((char *)0) = 0;
}

#define MAX_W 2500
#define MAX_L 30
char words[MAX_W][MAX_L];
int totalWords;
int inputPairs[MAX_W][2];

bool fake[MAX_W];
bool available[MAX_W][2];

int getWordIndex(char *word) {
    FOR(i, totalWords) if (!strcmp(word, words[i])) return i;
    strcpy(words[totalWords], word);
    return totalWords++;
}

int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int cc=1;cc<=cases;cc++) {
        totalWords = 0;
        int pairs;
        scanf("%d", &pairs);
        FOR(i, pairs) {
            char w1[MAX_L], w2[MAX_L];
            scanf("%s %s", w1, w2);
            inputPairs[i][0] = getWordIndex(w1);
            inputPairs[i][1] = getWordIndex(w2);
            //printf("%d %d\n", inputPairs[i][0], inputPairs[i][1]);
        }

        int result = 0;
        FOR(i, (1<<pairs)) {
            int tmp = i;
            FOR(j, pairs) {
                fake[j] = (tmp & 1) == 1;
                tmp >>= 1;
            }
            FOR(j, totalWords) available[j][0] = available[j][1] = false;
            FOR(j, pairs) {
                if (!fake[j]) {
                    available[inputPairs[j][0]][0] = true;
                    available[inputPairs[j][1]][1] = true;
                }
            }
            //printf("\n");
            //FOR(j, totalWords) printf("%d %d\n", available[j][0], available[j][1]);
            int total = 0;
            FOR(j, pairs) {
                if (fake[j]) {
                    total++;
                    if (!available[inputPairs[j][0]][0] || !available[inputPairs[j][1]][1]) {
                        total = 0;
                        break;
                    }
                }
            }
            if (total > result) result = total;
        }
        printf("Case #%d: %d\n", cc, result);
    }
}
