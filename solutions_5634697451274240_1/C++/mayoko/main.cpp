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

int solve(string s) {
    int n = s.size();
    vector<int> flip(n), target(n);
    for (int i = 0; i < n; i++) {
        // 裏返してたら 1
        if (s[i] == '-') target[i] = 1;
    }
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        if (flip[i] != target[i]) {
            ans++;
            for (int j = 0; j <= i; j++) flip[j] ^= 1;
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string s;
        cin >> s;
        cout << "Case #" << t << ": " << solve(s) << endl;
    }
    return 0;
}
