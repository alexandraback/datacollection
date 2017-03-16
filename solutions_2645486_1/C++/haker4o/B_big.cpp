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

ll E, R, n, v[1<<14];

ll calc(ll a, ll b, ll s, ll e) {
    if (a == b) return 0;
    int maxIdx=a;
    for(int i=a+1; i<b; ++i) {
        if (v[maxIdx] < v[i]) maxIdx = i;
    }
    ll canSt = min(E, s + (maxIdx-a)*R);
    ll canEnd = max(0LL, e - (b-maxIdx)*R);
    ll res = (canSt-canEnd)*v[maxIdx];
    res += calc(a, maxIdx, s, canSt);
    if (canEnd == 0) {
        res += calc(maxIdx+1, b, min(E, canEnd+R), e);
    }
    return res;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T, NT;
    ll i, j;
    cin>>NT;
    for(T=1; T<=NT; ++T) {
        cin>>E>>R>>n;
        for(i=0; i<n; ++i) {
            cin>>v[i];
        }
        cout<<"Case #"<<T<<": "<<calc(0, n, E, 0)<<endl;
    }
    return 0;
}
