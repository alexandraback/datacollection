#include <iostream>
#include <vector>

using namespace std;

int m = 512;

class Node {
public:
    int t;
    int k;
    int keys[512];
    bool try_begin;

    Node() {
        try_begin = true;
    }
};

bool check(int n, Node *nodes, int *keys, int* v) {
    int agg[m];
    for(int i=0; i<m; i++) {
        agg[i] = keys[i];
    }

    for(int i=0; i<n; i++) {
        if(v[i] == 0) {
            int t = nodes[i].t;
            agg[t]--;

            for(int j=0; j<nodes[i].k; j++) {
                int k = nodes[i].keys[j];
                agg[k]++;
            }
        }
    }

    for(int i=0; i<m; i++) {
        if(agg[i] < 0) {
            return false;
        }
    }
    return true;
}

void visit(int n, Node *nodes, int *keys, int *v, int *ans, int &sz) {
    if(sz == n) {
        return;
    }

    for(int i=0; i<n; i++) {
        int t = nodes[i].t;
        if(keys[t] > 0 && v[i] == 0) {

            if(sz == 0) {
                if(nodes[i].try_begin) {
                    nodes[i].try_begin = false;
                } else {
                    continue;
                }
            }

            if(!check(n, nodes, keys, v)) {
                continue;
            }

            ans[sz] = i+1;

            keys[t]--;
            v[i] = 1;
            sz++;
            for(int j=0; j<nodes[i].k; j++) {
                int k = nodes[i].keys[j];
                keys[k]++;
            }
            
            visit(n, nodes, keys, v, ans, sz);

            if(sz == n) {
                return;
            }

            keys[t]++;
            v[i] = 0;
            sz--;
            for(int j=0; j<nodes[i].k; j++) {
                int k = nodes[i].keys[j];
                keys[k]--;
            }

            if(sz != 0) {
                return;
            }
        }
    }
    return;
}

int solve(int* ans) {
    int sz = 0; 
    int keys[m], v[m];
    for(int i=0; i<m; i++) {
        keys[i] = 0;
        v[i] = 0;
    }

    int k, n;
    cin>>k>>n;
    for(int i=0; i<k; i++) {
        int t;
        cin>>t;
        keys[t]++;
    }

    Node nodes[m];
    for(int i=0; i<n; i++) {
        int t;
        cin>>nodes[i].t>>nodes[i].k;
        for(int j=0; j<nodes[i].k; j++) {
            cin>>nodes[i].keys[j];
        }
    }

    visit(n, nodes, keys, v, ans, sz);

    return sz;
}

int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)  {
        int ans[m];

        int sz = solve(ans);
        cout<<"Case #"<<t<<": ";
        if(sz == 0) {
            cout<<"IMPOSSIBLE"<<endl;
        } else {
            for(int j=0; j<sz-1; j++) {
                cout<<ans[j]<<" ";
            }
            cout<<ans[sz-1]<<endl;
        }
    }
    return 0;
}

