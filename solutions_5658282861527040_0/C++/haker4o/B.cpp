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

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    ll i, j;
    ll T, NT, a, b, k;
    cin>>NT;
    ll res;
    for(T=1; T<=NT; ++T) {
        cin>>a>>b>>k;
        res = 0;
        for(i=0; i<a; ++i) for(j=0; j<b; ++j) {
            if ((i & j) < k) ++res;
        }
        cout<<"Case #" << T << ": " << res << endl;
    }
    return 0;
}
