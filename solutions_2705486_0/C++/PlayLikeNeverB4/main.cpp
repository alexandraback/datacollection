#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#include <cstring>
#include <ctime>
#include <cassert>
#include <utility>
#include <tr1/unordered_map>

using namespace std;

struct trie;

#define INF 1000000
#define MAXTR 1200000
#define MAXL 55
char str[MAXL];
int TN, N;
trie *tAddr[MAXTR];
tr1::unordered_map<trie*, int> tIdx;

struct trie {
    static int CNT;

    trie *f[26];
    bool word;

    trie() {
        word = false;
        for(int i = 0; i < 26; i++)
            f[i] = NULL;

        tAddr[CNT] = this;
        tIdx[this] = CNT;
        CNT++;
    }

    ~trie() {
        for(int i = 0; i < 26; i++)
            if(f[i] != NULL)
                delete f[i];
    }
};
int trie::CNT;

int mem[55][6][MAXTR];

int go(int p, int bad, int idx) {
    if(p == N) {
        if(idx == 0)
            return 0;
        return INF;
    }
    if(mem[p][bad][idx] > -1)
        return mem[p][bad][idx];

    int ret = MAXL;
    trie *TR = tAddr[idx];

    // continue
    int pidx = str[p] - 'a';
    if(TR->f[pidx] != NULL) {
        ret = min(ret, go(p + 1, max(0, bad - 1), tIdx[TR->f[pidx]]));

        // finish word
        if(TR->f[pidx]->word)
            ret = min(ret, go(p + 1, max(0, bad - 1), 0));
    }

    // change letter
    for(int i = 0; i < 26; i++)
        if(i != pidx && TR->f[i] != NULL) {
            if(bad == 0) {
                ret = min(ret, 1 + go(p + 1, 4, tIdx[TR->f[i]]));

                if(TR->f[i]->word)
                    ret = min(ret, 1 + go(p + 1, 4, 0));

            }
        }

    return mem[p][bad][idx] = ret;
}

int main() {
    freopen("dic.txt", "r", stdin);

    trie *T = new trie();
    while(!feof(stdin)) {
        fgets(str, sizeof(str), stdin);

        trie *t = T;
        for(int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
            int p = str[i] - 'a';
            if(t->f[p] == NULL)
                t->f[p] = new trie();

            t = t->f[p];
        }

        t->word = true;
    }

	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);

    scanf("%d\n", &TN);
    for(int tn = 1; tn <= TN; tn++) {
        fgets(str, sizeof(str), stdin);

        N = strlen(str);
        while(str[N - 1] == '\n')
            N--;

        memset(mem, -1, sizeof(mem));
        int ans = go(0, 0, tIdx[T]);

        printf("Case #%d: %d\n", tn, ans);
    }

    delete T;

	return 0;
}
