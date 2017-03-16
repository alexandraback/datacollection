#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <cstring>


using namespace std;
typedef long long LL;


const int maxn = 1010;

int n;
vector<int> e[maxn];
int b[maxn];


bool Dfs(int v) {
    b[v] = 1;
    for (int i = 0; i < e[v].size(); ++i)
        if (!b[e[v][i]]) {
            if (Dfs(e[v][i]))
                return true;
        } else {
            return true;
        }
    return false;
}

string Do() {
    cin >> n;
    for (int i = 0; i <= n; ++i)    
        e[i].clear();
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            e[v].push_back(i);
        }
    }
    bool yes = false;
    for (int i = 1; i <= n; ++i) {
        memset(b, 0, sizeof(b));
        yes = yes || Dfs(i);
    }
    return yes ? "Yes" : "No";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": " << Do() << endl;
    } 
    

    return 0;
}
