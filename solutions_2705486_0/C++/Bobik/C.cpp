// {{{
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <numeric>
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define FOR(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
#define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define SIZE(x) ((int) ((x).size()))
#define DEBUG(x) { cerr << #x << ": " << (x) << endl; }
#define SQR(x) ((x) * (x))
#define INF 1023456789
using namespace std;

typedef long long LL;
typedef pair<int, int> PI;
typedef pair<int, PI> TRI;
typedef vector<int> VI;
typedef vector<VI> VVI;
// }}}

struct Node {
    Node(int d): next(26, NULL), end(false), depth(d) {}

    vector<Node*> next;
    bool end;
    int depth;
};

void insert(Node* x, const string& W) {
    REP(i, SIZE(W)) {
        if (x->next[W[i] - 'a'] == NULL)
            x->next[W[i] - 'a'] = new Node(x->depth + 1);
        x = x->next[W[i] - 'a'];
    }
    x->end = true;
}

Node* root;

int solve() {
    string SS;
    cin >> SS;
    VI S(SIZE(SS));
    REP(i, SIZE(S))
        S[i] = SS[i] - 'a';
    VVI D(SIZE(S) + 1, VI(5, INF));
    D[0][0] = 0;
    REP(i, SIZE(S)) REP(j, 5) if (D[i][j] < INF) {
        queue<pair<Node*, PI> > Q;
        Q.push(make_pair(root, PI(j, D[i][j])));
        while (!Q.empty()) {
            Node* x = Q.front().first;
            int j = Q.front().second.first;
            int c = Q.front().second.second;
            Q.pop();
            if (x->end)
                D[i + x->depth][j] = min(D[i + x->depth][j], c);
            if (i + x->depth < SIZE(S)) {
                if (x->next[S[i + x->depth]])
                    Q.push(make_pair(x->next[S[i + x->depth]], PI(max(0, j - 1), c)));
                if (j == 0)
                    REP(k, 26) if (x->next[k] && k != S[i + x->depth])
                        Q.push(make_pair(x->next[k], PI(4, c + 1)));
            }
        }
    }

    int res = INF;
    REP(i, 5)
        res = min(res, D[SIZE(S)][i]);
    assert(res != INF);
    return res;
}

int main() {
    root = new Node(0);
    ifstream ifs;
    ifs.open("garbled_email_dictionary.txt", ifstream::in);
    string W;
    while (ifs >> W)
        insert(root, W);

    int T;
    cin >> T;
    FOR(ti, 1, T)
        cout << "Case #" << ti << ": " << solve() << endl;
}
