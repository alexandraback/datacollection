#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

int n;
map< string, vector<string> > lr;
set<string> le, ri;
char b1[1 << 20], b2[1 << 20];

set<string> us;
map<string, string> from;

bool augment(string v) {
    if (us.find(v) != us.end()) {
        return false;
    }
    us.insert(v);
    for (const auto &u: lr[v]) {
        if (from.find(u) == from.end() || augment(from[u])) {
            from[u] = v;
            return true;
        }
    }
    return false;
}

int max_match() {
    from.clear();
    int res = 0;
    for (const auto &a: le) {
        us.clear();
        if (augment(a)) {
            ++res;
        }
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int te = 1; te <= T; ++te) {
        scanf("%d", &n);
        lr.clear();
        le.clear();
        ri.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%s %s", b1, b2);
            lr[b1].push_back(b2);
            le.insert(b1);
            ri.insert(b2);
        }
        int mat = max_match();
        // printf("Matching %d\n", mat);
        int edgecov = (int) le.size() + (int) ri.size() - mat;
        // printf("Edge cover %d\n", edgecov);
        printf("Case #%d: %d\n", te, n - edgecov);
    }
    return 0;
}
