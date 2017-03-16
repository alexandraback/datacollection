#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef long long LL;

int f[1000010];

int DFS(int x) {
    if (x <= 10) return f[x] = x;
    if (f[x]) return f[x];
    std::string x_str = std::to_string(x);
    reverse(x_str.begin(), x_str.end());
    // cout << x << " " << atoi(x_str.c_str()) << endl;
    f[x] = DFS(x - 1) + 1;
    int y;
    if (x_str[0] != '0' && (y = atoi(x_str.c_str())) < x) {
        f[x] = min(f[x], DFS(y) + 1);
    }
    return f[x];
}

void solve() {
    int x;
    cin >> x;
    cout << DFS(x) << endl;
}

int main() {
    
    int testcase;
    for (int i = 1; i < 1000000; ++i) {
        DFS(i);
    }
    freopen("/Volumes/Data/download/A-small-attempt0.in", "r", stdin);
    freopen("/Volumes/Data/download/out.txt", "w", stdout);

    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
