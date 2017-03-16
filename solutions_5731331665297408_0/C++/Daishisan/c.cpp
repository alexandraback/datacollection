#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

struct V {
    set<int> ns;
};

int n;
int m;

int greedy_dfs(int idx, int order[], V vs[]) {
    V& curr = vs[order[idx]];
    int next = idx + 1;
    if (next == n)
        return -1;
    while (next != -1) {
        if (curr.ns.find(order[next]) == curr.ns.end())
            return next;
        next = greedy_dfs(next, order, vs);
    }
    return -1;
}

int main() {
    int t; cin >> t;
    for (int test = 1; test <= t; ++test) {
        // read input
        cin >> n;
        cin >> m;
        int zips[n];
        for (int i = 0; i < n; ++i)
            cin >> zips[i];
        V vs[n];
        for (int i = 0; i < m; ++i) {
            int a; cin >> a; --a;
            int b; cin >> b; --b;
            vs[a].ns.insert(b);
            vs[b].ns.insert(a);
        }
        // try all possibilities
        string ans = "";
        int order[n];
        for (int i = 0; i < n; ++i)
            order[i] = i;
//int cows = 0;
        do {
//++cows;
//cout << "cows = " << cows << endl;
            bool possib = greedy_dfs(0, order, vs) == -1;
            if (possib) {
                string cand = "";
                stringstream str;
                for (int i = 0; i < n; ++i)
                    str << zips[order[i]];
                str >> cand;
                if (ans == "")
                    ans = cand;
                ans = min(ans, cand);
            }
        } while (next_permutation(order, order + n));
        cout << "Case #" << test << ": " << ans << endl;
    }
}

