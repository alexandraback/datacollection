#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAXS = 4000;

struct tree_node
{
    bool end;
    tree_node* link[26];
};

char S[MAXS+1];
int N, res[MAXS+1][5];

void go(tree_node* T, int pos, int e0, int ne, int pe)
{
    if (T->end) {
        int tpe = (pe > 4) ? 4 : pe;
        if (res[pos][tpe] == -1 || res[pos][tpe] > e0+ne) res[pos][tpe] = e0+ne;
    }

    if (pos == N) return;

    if (T->link[S[pos]] != 0) {
        go(T->link[S[pos]], pos+1, e0, ne, pe+1);
    }

    if (pe >= 4) {
        for (int c = 0; c < 26; ++c)
            if (T->link[c] != 0)
                go(T->link[c], pos+1, e0, ne+1, 0);
    }
}

tree_node* root;

void solve()
{
    memset(res, -1, sizeof(res));
    res[0][4] = 0;

    for (int start = 1; start <= N; ++start) {
        for (int pe = 0; pe <= 4; ++pe) {
            if (res[start-1][pe] == -1) continue;

            go(root, start-1, res[start-1][pe], 0, pe);
        }
    }

    int mn = 1000000000;

    for (int pe = 0; pe <= 4; ++pe)
        if (res[N][pe] != -1 && res[N][pe] < mn) mn = res[N][pe];

    printf("%d", mn);
}

void add_word(tree_node* T, char *s)
{
    if (*s == 0) { T->end = true; return; }

    if (T->link[*s-'a'] == 0) {
        tree_node* tmp = new tree_node;
        tmp->end = false; memset(tmp->link, 0, sizeof(tmp->link));
        T->link[*s-'a'] = tmp;
    }

    add_word(T->link[*s-'a'], s+1);
}

int main()
{
    FILE* dict = fopen("garbled_email_dictionary.txt", "r");

    char tmp[100];
    root = new tree_node;
    root->end = false; memset(root->link, 0, sizeof(root->link));

    while (true) {
        if (fscanf(dict, "%s", tmp) < 1) break;
        add_word(root, tmp);
    }

    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%s", S); N = strlen(S);
        for (int i = 0; i < N; ++i) S[i] -= 'a';

        printf("Case #%d: ", t+1);
        solve();
        printf("\n");
    }

    return 0;
}
