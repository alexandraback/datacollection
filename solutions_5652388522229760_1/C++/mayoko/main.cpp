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

ll solve(int N) {
    bool ok[10];
    memset(ok, false, sizeof(ok));
    int ans = 1;
    while (1) {
        {
            ll tmp = (ll)N * ans;
            while (tmp) {
                ok[tmp%10] = true;
                tmp /= 10;
            }
        }
        bool finish = true;
        for (int i = 0; i < 10; i++) finish &= ok[i];
        if (finish) return (ll)N * ans;
        ans++;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": ";
        if (N==0) cout << "INSOMNIA" << endl;
        else cout << solve(N) << endl;
    }
    return 0;
}
