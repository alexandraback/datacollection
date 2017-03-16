#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char w[4096];

struct trie {
    struct trie *down[26];
    bool end_of_word;
} node[4000000];

int nodes = 0;
struct trie *root = NULL;

bool add(struct trie **root_ptr, char *word) {
    struct trie *p;
    do {
        p = *root_ptr;
        if (p == NULL) {
            p = node + nodes++;
            for (int i = 0; i < 26; ++i) p->down[i] = NULL;
            p->end_of_word = false;
            *root_ptr = p;
        }
        root_ptr = p->down + (*word - 'a');
    } while (*word++);
    return p->end_of_word ? false : (p->end_of_word = true);
}

const int INF = 123456789;

int dp[4096][5];

void go2(trie* root, int p, int l, int c) {
    if (root->end_of_word) dp[p][l] = min(dp[p][l], c);

    if (w[p] != '\0' && root->down[w[p] - 'a'] != NULL) {
        go2(root->down[w[p] - 'a'], p + 1, max(0, l - 1), c);
    }

    if (w[p] != '\0' && l == 0) for (int i = 0; i < 26; ++i) {
        if (root->down[i] != NULL && w[p] != i + 'a') {
            go2(root->down[i], p + 1, 4, c + 1);
        }
    }
}

int go() {
    for (int i = 0; i < 4096; ++i) for (int j = 0; j < 5; ++j) dp[i][j] = INF;
    dp[0][0] = 0;

    for (int i = 0; w[i] != '\0'; ++i) for (int j = 0; j < 5; ++j) if (dp[i][j] < INF) {
        go2(root, i, j, dp[i][j]);
    }

    int re = INF;
    int len = strlen(w);
    for (int j = 0; j < 5; ++j) re = min(re, dp[len][j]);

    return re;
}

int main() {
    FILE* f;
    f = fopen("garbled_email_dictionary.txt", "r");
    while(fscanf(f, "%s", w) == 1) {
//      fprintf(stderr, "%s\n", w);
        add(&root, w);
    }
    fclose(f);

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%s", w);
        printf("Case #%d: %d\n", t, go());
    }

    return 0;
}
