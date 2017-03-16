#include <cstdio>
#include <string>
#include <memory.h>
#include <vector>
#include <map>
using namespace std;

map<string, int> M;

int num(string S) {
    if (M.find(S) == M.end()) {
        int x = M.size();
        M[S] = x;
    } 
    return M[S];
}

char buf[25];

const int N = 2050;
vector<int> E[N];

int to[N];

int was[N];
int curit = 0;

bool go(int x) {
    was[x] = curit;
    for (int y : E[x]) {
        if (to[y] == -1) {
            to[y] = x;
            return true;
        }
    }
    for (int y : E[x]) {
        if (was[to[y]] != curit && go(to[y])) {
            to[y] = x;
            return true;
        }
    }
    return false;
}

int kuhn() {
    memset(to, -1, sizeof(int) * M.size());
    int ans = 0;
    for (int i = 0; i < M.size(); i++) {
        ++curit;
        ans += go(i);
    }
    return ans;
}

void solve(int cs) {
    M.clear();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        int a = num("0" + string(buf));
        scanf("%s", buf);
        int b = num("1" + string(buf));
        E[a].push_back(b);        
    }
    int match = kuhn();
    int ans = n - ((int)M.size() - match);
    for (int i = 0; i < M.size(); i++)
        E[i].clear();
    printf("Case #%d: %d\n", cs, ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
