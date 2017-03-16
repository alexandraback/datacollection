#include <vector>
#include<cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#endif
#include <ctime>
#include <queue>
#include <stack>
#include<iomanip>
#include <sstream>
#include <cmath>
#include <list>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, double> PID;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
typedef pair<PII, int> PIP;
vector<vector<int>> mul = {
 {0, 0, 0, 0, 0},
 {0, 1, 2, 3, 4},
 {0, 2, -1, 4, -3},
 {0, 3, -4, -1, 2},
 {0, 4, 3, -2, -1},
};
inline int char2int(char c) {
    switch(c) {
        case 'i' : return 2;
        case 'j' : return 3;
        case 'k' : return 4;
    }
}
bool findfirst(string& str, int key, int& index) {
    bool e = false;
    int ans = 1;
    for(int i = index; i < str.size(); i ++) {
        int tmp = char2int(str[i]);
        int flag = ans < 0 ? -1 : 1;
        ans = flag * mul[abs(ans)][tmp];
        //cout << i << " " << tmp << " " << ans << " " << key << endl;
        if (ans == key) {
            index = i + 1;
            e = true;
            break;
        }
    }
    //cout << index << " " << e << endl;
    return e;
}
bool check(string& str) {
    int index = 0;
    if (!findfirst(str, 2, index)) return false;
    if (!findfirst(str, 3, index)) return false;
    if (!findfirst(str, 4, index)) return false;
    int ans = 1;
    for(int i = index; i < str.size(); i ++) {
        int tmp = char2int(str[i]);
        int flag = ans < 0 ? -1 : 1;
        ans = flag * mul[abs(ans)][tmp];
    }
    if (ans != 1) return false;
    return true;
}
void solve(int ncase) {
    ll l, x;
    cin >> l >> x;
    string s;
    cin >> s;
    string str;
    if (x > 12) {
        for(int i = 0; i < 12; i ++) str += s;
        for(int i = 0; i < x % 12; i ++) str += s;
    } else {
        for(int i = 0; i < x; i ++) str += s;
    }
    cout << "Case #" << ncase << ": " << (check(str) ? "YES" : "NO") << endl;
}

int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    //freopen("in.txt", "r", stdin);
    freopen("C-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //init();
    int T = 1;
    cin >> T;
    //scanf("%d", &T);
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
