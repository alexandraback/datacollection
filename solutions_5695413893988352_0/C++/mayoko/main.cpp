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

int p10[] = {1, 10, 100, 1000};

bool check(int a, string A) {
    int sz = A.size();
    for (int i = 0; i < sz; i++) {
        char num = (char)('0'+(a%10));
        a /= 10;
        if (A[sz-1-i] == '?') continue;
        if (num != A[sz-1-i]) return false;
    }
    return true;
}

string gen(int num, int sz) {
    string ret;
    ret.resize(sz);
    for (char& c : ret) c = '0';
    for (int i = 0; i < sz; i++) {
        ret[sz-1-i] = (char)('0'+(num%10));
        num /= 10;
    }
    return ret;
}

void solve(string C, string J) {
    pii best(100000, 100000);
    int mini = 1000000;
    for (int c = 0; c < p10[C.size()]; c++) for (int j = 0; j < p10[J.size()]; j++) {
        if (!check(c, C) || !check(j, J)) continue;
        if (mini > abs(c-j)) {
            mini = abs(c-j);
            best = pii(c, j);
        } else if (mini == abs(c-j)) {
            best = min(best, pii(c, j));
        }
    }
    cout << gen(best.first, C.size()) << " " << gen(best.second, J.size()) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string C, J;
        cin >> C >> J;
        cout << "Case #" << t << ": ";
        solve(C, J);
    }
    return 0;
}
