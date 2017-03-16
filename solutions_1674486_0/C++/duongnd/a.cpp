#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
long next[1111][11] = {}; 
long m[1111];
long pass[1111] = {};
long n;
long T,found;

using namespace std;

long input() {
    cin >> n;
    long i,j,k;
    for (i = 1; i <= n; i ++) {
        cin >> m[i];
        for (j = 1; j <= m[i]; j ++) cin >> next[i][j];
    }
}

long dfs(long p) {
    pass[p] = 1;

    long i,j;
    for (i = 1; i <= m[p]; i ++ ) {
        j = next[p][i];
        if (pass[j]) {
            found = 1;
            return 0;
        }
        dfs(j);
        if (found) return 0;
    }
}

int main () {
    long i,j,k;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);    
    cin >> T;
    for (i = 0; i < T; i ++ ) {
        input();
        found = 0;
        for (j = 1; j <= n; j ++) {
            for (k = 1; k <= n; k ++) pass[k] = 0;            
            dfs(j);
            if (found) break;
        }
        if (!found) {
            cout << "Case #" << i +1 << ": No\n";
        }
        else {
            cout << "Case #" << i + 1 <<": Yes\n";
        }
    }
}
