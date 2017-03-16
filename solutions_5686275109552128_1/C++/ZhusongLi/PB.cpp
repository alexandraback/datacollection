#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
    freopen("input","r",stdin);
    freopen("output","w",stdout);
*/

vector<int> D;
int N;

int solve() {
    int i,j,k,r;
    sort(D.begin(),D.end());
    int res = D[D.size() - 1];
    int m = res;
    if (res == 0) return 0;
    for (i = 1;i <= m;i++) {
        k = 0;
        for (j = 0;j < D.size();j++) {
            if (D[j] <= i) continue;
            r = D[j] / i;
            if (D[j] % i == 0) r--;
            k += r;
        }
        res = min(res,i + k);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    
    freopen("B-large.in.txt","r",stdin);
    freopen("output","w",stdout);
    
    int T,i,j,k,n,m;
    cin >> T;
    for (int z1 = 1;z1 <= T;z1++) {
        D.clear();
        cin >> N;
        D.resize(N);
        for (i = 0;i < N;i++) cin >> D[i];
        cout << "Case #" << z1 << ": " << solve() << endl;
    }
    
    
    return 0;
}
