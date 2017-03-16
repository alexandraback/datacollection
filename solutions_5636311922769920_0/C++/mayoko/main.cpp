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
    ll p = 1;
    for (int i = 0; i < C-1; i++) p *= K;
    ll t = 0;
    for (int i = 0; i < K; i++) {
        cout << t+1 ;
        if (i < K-1) {
            t += p;
            cout << " ";
        }
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
        assert(K==S);
        cout << "Case #" << t << ": " ;
        solve(K, C, S);
    }
    return 0;
}
