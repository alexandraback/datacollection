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

int n, nk;
vector<short> t, k;

vector<vector<int> > v;

short dyn[1<<20];

short rec(int mask) {
    short &ret = dyn[mask];
    if (ret != -1) return ret;
    ret = 0;
    vector<short> cur = k;
    int i;
    for(i=0; i<n; ++i) {
        if ((mask>>i) & 1) continue;
        if (k[t[i]] == 0) continue;
        k[t[i]]--;
        for(int j=0; j<v[i].size(); ++j) {
            k[v[i][j]]++;
        }
        ret = rec(mask | (1<<i));
        k[t[i]]++;
        for(int j=0; j<v[i].size(); ++j) {
            k[v[i][j]]--;
        }
        if (ret) break;
    }
    return ret;
}

vector<int> path;

void findPath() {
    int cur=0;
    path.clear();
    while(path.size() < n) {
        for(int i=0; i<n; ++i) {
            if ((cur>>i) & 1) continue;
            if (dyn[cur | (1<<i)] != 1) continue;
            path.push_back(i);
            cur |= (1<<i);
            break;
        }
    }
}

void printPath() {
    for(int i=0; i<n; ++i) {
        cout<<" "<<path[i]+1;
    }
    cout<<endl;
}


int main() {
    freopen("D-small-attempt1.in", "r", stdin);
    freopen("D-small-attempt1.out", "w", stdout);
    int i, j;
    int NT, T;
    cin>>NT;
    for(T=1; T<=NT; ++T) {
        cout<<"Case #"<<T<<":";
        cin>>nk>>n;
        memset(dyn, -1, sizeof(dyn));
        dyn[(1<<n)-1] = 1;
        t.clear();
        k.clear();
        v.clear();
        t.resize(n);
        k.resize(201, 0);
        v.resize(n);
        for(i=0; i<nk; ++i) {
            short a;
            cin>>a;
            k[a]++;
        }
        for(i=0; i<n; ++i) {
            int a;
            cin>>t[i]>>a;
            v[i].resize(a);
            for(j=0; j<a; ++j) {
                cin>>v[i][j];
            }
        }
        map<int, int> mm;
        int cc=0;
        for(i=0; i<n; ++i) {
            if (!mm.count(t[i])) {
                mm[t[i]] = cc++;
            }
            t[i] = mm[t[i]];
        }
        for(i=0; i<n; ++i) {
            vector<int> tt;
            for(j=0; j<v[i].size(); ++j) {
                if (mm.count(v[i][j])) {
                    tt.push_back(mm[v[i][j]]);
                }
            }
            v[i] = tt;
        }
        vector<short> tt(cc, 0);
        for(i=0; i<201; ++i) {
            if (k[i]>0 && mm.count(i)) tt[mm[i]] = k[i];
        }
        k = tt;
        if (rec(0)) {
            findPath();
            printPath();
        } else {
            cout<<" IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}
