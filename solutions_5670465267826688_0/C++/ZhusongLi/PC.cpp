#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
    freopen("input","r",stdin);
    freopen("output","w",stdout);
*/

struct node {
    char c;
    bool p;
};

node cal(node a,node b) {
    node res;
    bool q;
    if (a.p == 1 && b.p == 1) q = 0;
    else if (a.p == 0 && b.p == 0) q = 0;
    else q = 1;
    if (a.c == '1') {
        if (b.c == '1') {
            res.c = '1';
            res.p = q;
        }
        if (b.c == 'i') {
            res.c = 'i';
            res.p = q;
        }
        if (b.c == 'j') {
            res.c = 'j';
            res.p = q;
        }
        if (b.c == 'k') {
            res.c = 'k';
            res.p = q;
        }
    }
    if (a.c == 'i') {
        if (b.c == '1') {
            res.c = 'i';
            res.p = q;
        }
        if (b.c == 'i') {
            res.c = '1';
            res.p = 1 - q;
        }
        if (b.c == 'j') {
            res.c = 'k';
            res.p = q;
        }
        if (b.c == 'k') {
            res.c = 'j';
            res.p = 1 - q;
        }
    }
    if (a.c == 'j') {
        if (b.c == '1') {
            res.c = 'j';
            res.p = q;
        }
        if (b.c == 'i') {
            res.c = 'k';
            res.p = 1 - q;
        }
        if (b.c == 'j') {
            res.c = '1';
            res.p = 1 - q;
        }
        if (b.c == 'k') {
            res.c = 'i';
            res.p = q;
        }
    }
    if (a.c == 'k') {
        if (b.c == '1') {
            res.c = 'k';
            res.p = q;
        }
        if (b.c == 'i') {
            res.c = 'j';
            res.p = q;
        }
        if (b.c == 'j') {
            res.c = 'i';
            res.p = 1 - q;
        }
        if (b.c == 'k') {
            res.c = '1';
            res.p = 1 - q;
        }
    }
    return res;
}

int X,L;
string s;

bool operator < (node a,node b) {
    if (a.c == b.c) {
        return a.p > b.p;
    }
    return a.c > b.c;
}

bool solve() {
    map<node,int> M,R;
    int i,j,k;
    node q,r,x,y;
    q.c = '1';
    q.p = 0;
    r.p = 0;
    for (i = 0;i < L;i++) {
        r.c = s[i];
        q = cal(q,r);
        if (M.find(q) == M.end()) M[q] = i + 1;
    }
    
    if (q.c == '1' && q.p == 0) return 0;
    if (q.c == '1' && X % 2 == 0) return 0;
    if (q.c != '1' && X % 4 != 2) return 0;
    
    q.c = '1';
    q.p = 0;
    r.p = 0;
    for (i = 0;i < 4 * L;i++) {
        r.c = s[i % L];
        q = cal(q,r);
        if (M.find(q) == M.end()) M[q] = i + 1;
    }
    q.c = '1';
    q.p = 0;
    r.p = 0;
    for (i = 4 * L - 1;i >= 0;i--) {
        r.c = s[i % L];
        q = cal(r,q);
        if (R.find(q) == R.end()) R[q] = (4 * L - i);
    }
    q.c = 'i';
    q.p = 0;
    if (M.find(q) == M.end()) return 0;
    j = M[q];
    q.c = 'k';
    if (R.find(q) == R.end()) return 0;
    j += R[q];
    if (j < L * X) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    freopen("C-small-attempt2.in.txt","r",stdin);
    freopen("output","w",stdout);
    int T,i,j,k;
    cin >> T;
    for (int z1 = 1;z1 <= T;z1++) {
        cin >> L >> X;
        cin >> s;
        bool ok = solve();
        if (ok == 1) cout << "Case #" << z1 << ": YES" << endl;
        else cout << "Case #" << z1 << ": NO" << endl;
    }
    return 0;
}
