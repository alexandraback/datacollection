#include <iostream>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)

int n;
int gc[1024], g[1024][1024];

int v[1024];
bool dfs(int u) {
    v[u] = 1;
    FOR(i,0,gc[u]) {
        if(v[g[u][i]]) return true;
        if(dfs(g[u][i])) return true;
    }
    return false;
}

int _gc[1024], _g[1024][1024];

void do_case(int case_no) {
    cin >> n;
    FOR(i,0,n) {
        cin >> _gc[i];
        FOR(j,0,_gc[i]) {
            cin >> _g[i][j];
            _g[i][j]--;
        }
        gc[i] = 0;
    }
    FOR(i,0,n) {
        FOR(j,0,_gc[i]) {
            int u = _g[i][j];
            int idx = gc[u];
            g[u][idx] = i;
            gc[u]++;
        }
    }
    //FOR(i,0,n) { cout << gc[i] << ": "; FOR(j,0,gc[i]) cout << g[i][j] << " "; cout << endl; }
    bool res = false;
    FOR(i,0,n) if(!_gc[i]) {
        FOR(t,0,n) v[t] = 0;
        if(dfs(i)) {
            res = true;
            break;
        }
    }
    cout << "Case #" << case_no << ": " << (res?"Yes":"No") << endl;
}

int main() {
    int T;
    cin >> T;
    for(int te=1;te<=T;te++) do_case(te);
    return 0;
}
