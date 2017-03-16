#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
using namespace std;

int cases, kejs;
int i, j, k;
int n;
int path[200];
int npath;
int have[201]; // how many keys of the type we have
bool opened[200];
int locktype[200]; // which key opens this chest
map<int, int> cont[200]; // how many keys of which types contains the chest
bool done;
set<map<int, int> > was[1<<20];
map<int, int> state;

void go() {
    int i, j;
    map<int, int>::iterator it;
    bool ok = true;
    state.clear();
    for (i = 1; i <= 200; i++) {
        if (have[i] > 0) state[i] = have[i];
    }
    j = 0;
    for (i = 0; i < n; i++) {
        if (opened[i]) j |= (1 << i);
    }
    if (was[j].find(state) != was[j].end()) return;
    was[j].insert(state);
/*
    for (i = 0; i < npath; i++) {
        fprintf(stderr, " %d", path[i]);
    }
    fprintf(stderr, "\n");
*/
    for (i = 0; i < n; i++) {
        if (opened[i]) continue;
        ok = false;
        if (have[locktype[i]]) {
            opened[i] = true;
            have[locktype[i]]--;
            for (it = cont[i].begin(); it != cont[i].end(); ++it) {
                have[it->first] += it->second;
            }
            path[npath++] = i;
            go();
            if (done) return;
            npath--;
            opened[i] = false;
            have[locktype[i]]++;
            for (it = cont[i].begin(); it != cont[i].end(); ++it) {
                have[it->first] -= it->second;
            }
        }
    }
    if (ok) done = true;
}

int main() {
    scanf("%d", &cases);
    for (kejs = 1; kejs <= cases; kejs++) {
        printf("Case #%d:", kejs);
        scanf("%d%d", &j, &n);
        for (i = 0; i <= 200; i++) have[i] = 0;
        while (j-- > 0) {
            scanf("%d", &i);
            have[i]++;
        }
        for (j = 0; j < (1 << n); j++) was[j].clear();
        for (i = 0; i < n; i++) {
            scanf("%d%d", &locktype[i], &j);
            cont[i].clear();
            opened[i] = false;
            while (j-- > 0) {
                scanf("%d", &k);
                cont[i][k]++;
            }
        }
        done = false;
        npath = 0;
        go();
        if (done) {
            for (i = 0; i < n; i++) printf(" %d", path[i] + 1);
            printf("\n");
        } else printf(" IMPOSSIBLE\n");
    }
    return 0;
}
