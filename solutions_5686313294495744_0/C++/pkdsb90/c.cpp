#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 7;
const int N = 5555;

int T, cas;

struct edge{
    int v, next;
} e[M];

int first[N], ecnt;

void addedge(int u, int v){
    e[++ ecnt].v = v, e[ecnt].next = first[u], first[u] = ecnt;
}

int vote[N], match[N]; bool vis[N];

bool gao(int u){ // f1 means left or right, f2 means change match or not ..
    for(int i = first[u]; i != -1; i = e[i].next){
        int v = e[i].v;
        if(!vis[v]){
            vis[v] = true;
            if(match[v] == -1 || gao(match[v])){
                match[v] = u, match[u] = v;
                return true;
            }
        }
    }
    return false;
}

int tot;

int Hungary() {
    memset(match, -1, sizeof(match));
    int ret = 0;
    for(int i = 1; i <= tot; i ++){
        memset(vis, 0, sizeof(vis));
        if(gao(i)) ret ++;
    }
    return ret;
}

int n; char ch0[55], ch1[55];
map<string, int> M0, M1;

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> T;
    while (T --) {
        printf("Case #%d: ", ++ cas);
        cin >> n;
        M0.clear(), M1.clear();
        tot = 0;
        memset(first, -1, sizeof(first));
        ecnt = -1;
        for (int i = 0; i < n; i ++) {
            scanf(" %s %s", ch0, ch1);
            if (M0.find(ch0) == M0.end()) {
                M0[ch0] = ++ tot;
            }
            if (M1.find(ch1) == M1.end()) {
                M1[ch1] = ++ tot;
            }
            addedge(M0[ch0], M1[ch1]);
//            cout << M0[ch0] << ' ' << M1[ch1] << endl;
        }
        int t = Hungary();
//        cout << t << "~~" << endl;
        t = tot - t;
        t = n - t;
        printf("%d\n", t);
    }
}
