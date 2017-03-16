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

int e, r, n, v[16];

int dyn[16][16];

int rec(int pos, int left) {
    int &ret = dyn[pos][left];
    if (ret != -1) return ret;
    if (pos == n) return ret=0;
    ret = 0;
    for(int i=0; i<=left; ++i) {
        int cur = i*v[pos];
        cur += rec(pos+1, min((left-i+r), e));
        ret = max(cur, ret);
    }
    return ret;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int i, j;
    int T, NT;
    cin>>NT;
    for(T=1; T<=NT; ++T) {
        memset(dyn, -1, sizeof(dyn));
        cin>>e>>r>>n;
        for(i=0; i<n; ++i) {
            cin>>v[i];
        }
        cout<<"Case #"<<T<<": "<<rec(0, e)<<endl;
    }
    return 0;
}
