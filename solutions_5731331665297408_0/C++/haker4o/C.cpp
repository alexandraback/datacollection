#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <sstream>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

vector<vector<int> > ne;
vector<int> tag;
int n;

bool connected(int st, vector<int> &out) {
    vector<bool> u(n, false);
    u[st] = true;
    for(int i=0; i<out.size(); ++i) {
        u[out[i]] = true;
    }
    queue<int> q;
    q.push(st);
    int cur;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        for(int i=0; i<ne[cur].size(); ++i) {
            if (!u[ne[cur][i]]) {
                u[ne[cur][i]] = true;
                q.push(ne[cur][i]);
            }
        }
    }
    for(int i=0; i<n; ++i) {
        if (!u[i]) return false;
    }
    return true;
}

pii nextVert(vector<int> st, vector<int> out) {
    int best, par;
    vector<bool> u(n, false);
    for(int i=0; i<st.size(); ++i) {
        u[st[i]] = true;
    }
    for(int i=0; i<out.size(); ++i) {
        u[out[i]] = true;
    }
    best = par = -1;
    while(!st.empty()) {
        int p = st.back();
        for(int i=0; i<ne[p].size(); ++i) {
            int v = ne[p][i];
            if (u[v]) continue;
            u[v] = true;
            if (best == -1 || tag[v] < tag[best]) {
                best = v;
                par = p;
            }
        }
        out.push_back(p);
        if (!connected(st[0], out)) break;
        st.pop_back();
    }

    return mp(best, par);
}

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int i, j;
    int T, NT;
    cin>>NT;
    int m;
    for(T = 1; T <= NT; ++T) {
        ne.clear();
        tag.clear();
        cin>>n>>m;
        ne.resize(n);
        for(i=0; i<n; ++i) {
            int s;
            cin>>s;
            tag.push_back(s);
        }
        for(i=0; i<m; ++i) {
            int a, b;
            cin>>a>>b;
            ne[a-1].push_back(b-1);
            ne[b-1].push_back(a-1);
        }
        int start = 0;
        for(i=1; i<n; ++i) {
            if (tag[i] < tag[start]) start = i;
        }
        vector<int> st;
        st.push_back(start);
        vector<int> res;
        res.push_back(start);
        vector<int> out;
        for(i=1; i<n; ++i) {
            pii next = nextVert(st, out);
            while(st.back() != next.second) {
                out.push_back(st.back());
                st.pop_back();
            }
            st.push_back(next.first);
            res.push_back(next.first);
        }
        cout<<"Case #" << T << ": ";
        for(int i=0; i<n; ++i) {
            cout<<tag[res[i]];
        }
        cout<<endl;
    }

    return 0;
}
