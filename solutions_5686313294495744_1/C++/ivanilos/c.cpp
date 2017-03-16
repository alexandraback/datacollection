#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#define MAXN 1005
#define MAX_LEN 25
#define pb push_back
using namespace std;

char s1[MAX_LEN];
char s2[MAX_LEN];
int used[MAXN];
int mt[MAXN];
map <string, int> left;
map <string, int> right;
vector <int> g[MAXN];

int kuhn(int node) {
    if (used[node]) {
        return 0;
    }
    used[node] = 1;

    for (int i = 0; i < (int)g[node].size(); i++) {
        int viz = g[node][i];
        if (mt[viz] == -1 || kuhn(mt[viz])) {
            mt[viz] = node;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int t;
    int n;

    scanf(" %d", &t);
    for (int caso = 1; caso <= t; caso++) {
        int next_l = 0;
        int next_r = 0;
        left.clear();
        right.clear();
        scanf(" %d", &n);
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
        for (int i = 0; i < n; i++) {
            scanf(" %s %s", s1, s2);
            string a = string(s1);
            string b = string(s2);

            if (left.find(a) == left.end()) {
                left[a] = next_l;
                next_l++;
            }
            if (right.find(b) == right.end()) {
                right[b] = next_r;
                next_r++;
            }
            int idx1 = left[a];
            int idx2 = right[b];
            g[idx1].pb(idx2);
        }

        int match = 0;
        for (int i = 0; i < next_r; i++) {
            mt[i] = -1;
        }
        for (int i = 0; i < next_l; i++) {
            for (int j = 0; j < next_l; j++) {
                used[j] = 0;
            }
            if (kuhn(i)) {
                match++;
            }
        }

        //printf("n = %d, match = %d, l = %d, r = %d\n", n, match, next_l, next_r);
        printf("Case #%d: %d\n", caso, n - (next_l + next_r - match));
    }
    return 0;
}
