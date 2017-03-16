#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cctype>
#include <map>
#include <iomanip>
                   
using namespace std;
                   
#define eps 1e-8
#define pi acos(-1.0)
#define inf 1<<30
#define linf 1LL<<60
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define fi first
#define se second


ll v[1000];
int e,r,n;
ll dp[10000][100];

bool cmp(int a,int b) {
    return a>b;
}

ll gao() {
    ll ans=0;
    for (int i=0; i<n; i++) {
        if (e<=r) { 
            ans+=e*v[i];
        }
        else {
            ans+=(e-r)*v[i];
        }
    }
}

int main() {
    freopen("b.in","r",stdin);
    freopen("bb.txt","w",stdout);
    int T,cas=0;
    cin >> T;
    while (T--) {
        cin >> e >> r >> n;
        for (int i=0; i<n; i++) cin >> v[i];
        sort(v,v+n,cmp);
        cas++;
        cout << "Case #" <<  cas << ": ";
        cout << gao() << endl;
    }
    return 0;
}
