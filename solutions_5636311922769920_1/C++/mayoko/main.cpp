#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<list>
#include<queue>
#include<deque>
#include<algorithm>
//#include<numeric>
#include<utility>
#include<complex>
//#include<memory>
#include<functional>
#include<cassert>
#include<set>
#include<stack>
#include<random>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(int K, int C, int S) {
    if (C==1) {
        if (K > S) cout << "IMPOSSIBLE" << endl;
        else {
            for (int i = 0; i < K; i++) {
                cout << i+1 ;
                if (i < K-1) cout << " ";
            }
            cout << endl;
        }
        return;
    }
    if (2*S < K) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    ll p = 1;
    for (int i = 0; i < C-1; i++) p *= K;
    for (int i = 0; i < K; i+=2) {
        ll t = p*i;
        if (i+1 < K) t+=i+1;
        cout << t+1;
        if (i+2 < K) cout << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int K, C, S;
        cin >> K >> C >> S;
        cout << "Case #" << t << ": " ;
        solve(K, C, S);
    }
    return 0;
}
