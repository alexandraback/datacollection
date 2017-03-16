#include <iostream>
#include <algorithm>
#include <map>
#define F first
#define S second
using namespace std;
int n, m;
pair<string, int> ids[50];
bool graph[50][50];
int whoNum[51];
map<string, int> tNum;
map<int, string> tNumRev;
bool visited[50];
bool active[50];
bool wasThere[50];
//bool debug;
void DFScore(int v) {
    //cout<<"dfs "<<v<<"\n";
    visited[v] = true;
    for (int v2 = 0; v2 < n; v2++) {
        if (!visited[v2] && graph[v][v2] && active[v2]) {
            DFScore(v2);
        }
    }
}
bool DFS(int v) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    DFScore(v);
    for (int i = 0; i < n; i++) {
        if ((!wasThere[i]) && (!visited[i])) {
            //cout<<"fail "<<i<<"\n";
            return false;
        }
    }
    return true;
}

vector<int> perm;
vector<int> stack;
void solve() {
    stack.clear();
    perm.clear();
    for (int i = 0; i < n; i++) {
        active[i] = true;
        wasThere[i] = false;
    }
    stack.push_back(0);
    perm.push_back(0);
    wasThere[0] = true;
    while (perm.size() < n) {
        for (int v = 0; v < n; v++) {
            if (!wasThere[v]) {
                //if (debug) cout<<"try "<<v<<"\n";
                bool possible = false;
                int possibleFrom = -1;
                for (int pos = stack.size() - 1; pos >= 0; pos--) {
                    int hippo = stack[pos];
                    //if (debug) cout<<"hippo="<<hippo<<"\n";
                    if (graph[hippo][v]) {
                        //cout<<"jest edge\n";
                        for (int j = pos + 1; j < stack.size(); j++) {
                            active[stack[j]] = false;
                           // cout<<"disactive "<<stack[j]<<"\n";
                        }
                        if (DFS(v)) {
                            possible = true;
                            possibleFrom = pos;
                        }
                        for (int j = pos + 1; j < stack.size(); j++) {
                            active[stack[j]] = true;
                        }
                    }
                    if (possible) {
                        break;
                    }
                }
                if (possible) { //nawalamy
                    wasThere[v] = true;
                    //if (debug) cout<<"add "<<v<<"--------------\n";
                    for (int j = stack.size() - 1; j > possibleFrom; j--) {
                        active[stack[j]] = false;
                        stack.pop_back();
                    }
                    perm.push_back(v);
                    stack.push_back(v);
                    break;
                }
            }
        }

    }
}
int main() {
    ios_base::sync_with_stdio(0);
    //debug = false;
    int t;
    cin>>t;
    for (int test = 1; test <= t; test++) {
        tNum.clear();
        tNumRev.clear();
        cin>>n;
        cin>>m;
        for (int i = 0; i < n; i++) {
            cin>>ids[i].F;
            ids[i].S = i;
        }
        sort(ids, ids + n);
        for (int i = 0; i < n; i++) {
            whoNum[ids[i].S] = i;
            tNum[ids[i].F] = i;
            tNumRev[i] = ids[i].F;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = false;
            }
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin>>a>>b;
            a--; b--;
            a = whoNum[a];
            b = whoNum[b];
            graph[a][b] = true;
            graph[b][a] = true;
            //cout<<"edge "<<a<<" "<<b<<"\n";
        }
        solve();
        cout<<"Case #"<<test<<": ";
        for (int i = 0; i < n; i++) {
            cout<<tNumRev[perm[i]];
            //cout<<perm[i]<<" ";
        }
        cout<<"\n";

    }
    return 0;
}

