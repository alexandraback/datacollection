#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

string S;
vector<string> dict;

struct Node {
    bool end;
    Node *children[26];

    Node() {
        memset(children, 0, sizeof(children));
        end = false;
    }
};

Node root;

unsigned int state[4001][5];

void probe(unsigned old_state, int pos, int mod, int count, Node *curr) {
    if (curr->end) {
        if (state[pos][mod] > old_state + count)
            state[pos][mod] = old_state + count;
    }
    if (pos >= S.size())
        return;

    for (char c = 'a'; c <= 'z'; c++) {
        if (mod > 0 && c != S[pos])
            continue;
        if (curr->children[c - 'a'] == NULL)
            continue;
        if (c == S[pos])
            probe(old_state, pos+1, mod > 0 ? mod-1 : 0, count, curr->children[c - 'a']);
        else
            probe(old_state, pos+1, 4, count+1, curr->children[c - 'a']);
    }
}

int solve() {
    memset(state, -1, sizeof(state));
    state[0][0] = 0;

    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < 5; j++) {
            if (state[i][j] > S.size())
                continue;
            probe(state[i][j], i, j, 0, &root);
            /* for (vector<string>::iterator w_it = dict.begin(); w_it != dict.end(); ++w_it) {
                const string &w = *w_it;
                if (i + w.size() > S.size())
                    continue;
                int count = 0;
                int mod = j;
                for (int pos = 0; pos < w.size(); pos++) {
                    if (w[pos] != S[i+pos]) {
                        if (mod > 0) {
                            count = 9999;
                            break;
                        } else {
                            count++;
                            mod = 5;
                        }
                    }
                    mod--;
                }
                if (mod < 0)
                    mod = 0;
                if (state[i + w.size()][mod] > state[i][j] + count)
                    state[i + w.size()][mod] = state[i][j] + count;
            } */
        }
    }

    unsigned int ans = 9999;
    for (int i = 0; i < 5; i++)
        ans = min(ans, state[S.size()][i]);

    return ans;
}

void build_tree() {
    for (vector<string>::iterator w_it = dict.begin(); w_it != dict.end(); ++w_it) {
        const string &w = *w_it;
        Node *curr = &root;
        for (int i = 0; i < w.size(); i++) {
            if (curr->children[w[i] - 'a'] == NULL) {
                curr->children[w[i] - 'a'] = new Node();
            }
            curr = curr->children[w[i] - 'a'];
        }
        curr->end = true;
    }
}

int main() {
    ifstream dict_file;
    dict_file.open("garbled_email_dictionary.txt");
    for (int i = 0; i < 521196; i++) {
        string w;
        dict_file >> w;
        dict.push_back(w);
    }
    dict_file.close();
    build_tree();


    int T;
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; testcase++) {
        cin >> S;
        printf("Case #%d: %d\n", testcase, solve());
    }
    return 0;
}
