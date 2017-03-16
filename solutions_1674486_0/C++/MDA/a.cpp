#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <memory>

using namespace std;

#define PROBLEM_NUM "a"
#define ATTEMPT "0"

#if 1
#   define SIZE "small"
#else
#   define SIZE "large"
#endif

#if 1
#   define PATH PROBLEM_NUM "."
#else
#   define PATH "C:/Downloads/" PROBLEM_NUM "-" SIZE "-attempt" ATTEMPT "."
#endif

bool compl(int i, vector< int >&  complete, vector< vector< int > >& inh) {
    if (complete[i]) return false;
    set< int > papas(inh[i].begin(), inh[i].end());
    for (int j = 0; j < inh[i].size(); ++j) {
        compl(inh[i][j], complete, inh);
        for (int k = 0; k < inh[inh[i][j]].size(); ++k) 
            if (papas.count(inh[inh[i][j]][k]))
                return true;
            else
                papas.insert(inh[inh[i][j]][k]);
    }
    inh[i].assign(papas.begin(), papas.end());
    complete[i] = true;
    return false;
}

void solve(int num) {
    bool diamand = false;
    int n;
    scanf("%d", &n);
    vector< vector< int > > inh(n, vector< int >());
    vector< int > complete(n, false);
    for (int i = 0; i < n; ++i) {
        int m;
        scanf("%d", &m);
        for (int j= 0; j < m; ++j) {
            int tmp;
            scanf("%d", &tmp);
            inh[i].push_back(tmp - 1);
        }
    }
    for (int i = 0; i < n; ++i) if (!complete[i]) {
        if (compl(i, complete, inh)) {
            diamand = true;
            break;
        }
    }
    printf("Case #%d: %s\n", num, diamand ? "Yes" : "No");
}

int main() {
    freopen(PATH "in", "r", stdin);
    freopen(PATH "out", "w", stdout);
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; ++i) 
        solve(i + 1);
}
