#include <cstdio>
#include <string>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;

struct node {
    bool string_ends;
    struct node *next[26];
};

struct node root;

void init_node(struct node *t) {
    for (int i = 0; i < 26; ++i) {
        t->next[i] = NULL;
        t->string_ends = false;
    }
}

void build_trie() {
    FILE *f = fopen("garbled_email_dictionary.txt", "r");
    char s[11];
    struct node *t;
    int nodes = 1;

    init_node(&root);

    while (fscanf(f, "%s", s) > 0) {
        t = &root;

        for (int i = 0; s[i]; ++i) {
            if (t->next[s[i]-'a'] == NULL) {
                nodes += 1;
                t->next[s[i]-'a'] = (struct node *)malloc(sizeof(struct node));
                init_node(t->next[s[i]-'a']);
            }
            t = t->next[s[i]-'a'];
        }
        t->string_ends = true;
    }

    fclose(f);
}

char S[4010];

struct state{
    struct node *t;
    int k, errors;

    state(struct node *_t, int _k, int _errors) {
        this->t = _t;
        this->k = _k;
        this->errors = _errors;
    }
    state() {}
};

bool operator < (const state &a, const state &b) {
    if (a.t != b.t) return a.t < b.t;
    return a.k < b.k;
}

bool operator == (const state &a, const state &b) {
    return !(a < b) && !(b < a);
}

vector <state> states[2];

void expand(struct state s, vector <state>& dest, int C) {
    if (s.t->next[C] != NULL) {
        dest.push_back(state(s.t->next[C], s.k + 1, s.errors));
    }
    if (s.k >= 5) {
        for (int k = 0; k < 26; ++k) {
            if (k == C) continue;
            if (s.t->next[k] != NULL) {
                dest.push_back(state(s.t->next[k], 1, s.errors + 1));
            }
        }
    }
}

int solve() {
    states[0].clear();
    states[1].clear();

    states[0].push_back(state(&root, 5, 0));

    int q;
    for (int i = 0; S[i]; ++i) {
        q = i&1;
        states[!q].clear();

        //printf("-------------%d\n", i);
        for (int j = 0; j < states[q].size(); ++j) {
            //printf("%d %d\n", states[q][j].errors, states[q][j].k);

            expand(states[q][j], states[!q], S[i] - 'a');
            //printf("---> %d\n", states[!q].size());
        }

        int start_from_root_k[6];
        memset(start_from_root_k, -1, sizeof start_from_root_k);

        for (int j = 0; j < states[q].size(); ++j) {
            if (states[q][j].t->string_ends == false) {
                continue;
            }
            int k = states[q][j].k;
            if (k >= 5) k = 5;
            if (start_from_root_k[k] == -1 || start_from_root_k[k] > states[q][j].errors) {
                start_from_root_k[k] = states[q][j].errors;
            }
        }

        for (int k = 1; k <= 5; ++k) {
            if (start_from_root_k[k] == -1) {
                continue;
            }
            struct state s;
            s.t = &root;
            s.k = k;
            s.errors = start_from_root_k[k];

            expand(s, states[!q], S[i] - 'a');
        }
    }

    int sol = INF;
    for (int i = 0; i < states[!q].size(); ++i) {
        if (states[!q][i].t->string_ends) {
            sol = min(sol, states[!q][i].errors);
        }
    }

    return sol;
}

int main() {
    build_trie();
    int T;
    scanf("%d", &T);

    for (int tt = 1; tt <= T; ++tt) {
        scanf("%s", S);
        printf("Case #%d: %d\n", tt, solve());
    }

    return 0;
}
