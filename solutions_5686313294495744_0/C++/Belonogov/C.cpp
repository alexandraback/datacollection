#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1111;
const long long INF = 1e9 + 19;

int n, m;
map < string, int > a, b;
vector < int > e[N];
bool use[N];
int p[N];


bool dfs(int v) {
    use[v] = 1;
    for (auto u: e[v]) {
        if (p[u] == -1 || (!use[p[u]] && dfs(p[u]))) {
            p[u] = v;
            return 1;
        }
    }
    return 0;
}

void read() {
    a.clear();
    b.clear();
    n = 0;
    m = 0;
    int l;
    scanf("%d", &l);
    for (int i = 0; i < l; i++)
        e[i].clear();
    
    for (int i = 0; i < l; i++) {
        string s, t;
        cin >> s >> t;
        int v, u;
        if (a.count(s) == 0) 
            a[s] = n++;
        v = a[s];
        if (b.count(t) == 0) 
            b[t] = m++;
        u = b[t];
        e[v].pb(u);
    }
    for (int i = 0; i < m; i++)
        p[i] = -1;
    //db2(n, m);
    int answer = n + m;
    //db(answer);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            use[j] = 0;
        answer -= dfs(i);
    }
    //db2(l, answer);
    answer = l - answer;
    assert(0 <= answer && answer < l);
    printf("%d\n", answer);
}

void solve() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        scanf("%d", &k);
        for (int tt = 0; tt < k; tt++) {
            printf("Case #%d: ", tt + 1);
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}

