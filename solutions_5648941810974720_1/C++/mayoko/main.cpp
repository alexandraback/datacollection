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

int p[10] = {0, 8, 2, 3, 4, 5, 6, 7, 1, 9};
string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string dd = "ZGWTRFXVOI";
int calc(char c) {return c-'A';}

void solve(string s) {
    vector<int> cnt(26);
    for (char c : s) cnt[c-'A']++;
    vector<int> ans(10);
    for (int i = 0; i < 10; i++) {
        ans[p[i]] = cnt[calc(dd[i])];
        for (char c : digits[p[i]]) {
            cnt[calc(c)] -= ans[p[i]];
        }
    }
    for (int i = 0; i < 10; i++) for (int j = 0; j < ans[i]; j++) cout << i ;
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string s;
        cin >> s;
        cout << "Case #" << t << ": " ;
        solve(s);
    }
    return 0;
}
