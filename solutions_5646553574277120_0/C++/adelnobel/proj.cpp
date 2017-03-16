/* In the name of ALLAH, most gracious, most merciful */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <ios>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <queue>
#include <cassert>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

int C, D, V;
const int N = 50;

int coverWith(int mask, int n){
    int ret = mask;
    for(int j = 0; j < V; j++){
        if(((mask >> j) & 1) && j + n <= V){
            ret |= 1 << (j + n);
        }
    }
    return ret;
}

bool taken[N];
int best;

void solve(int cur, int mask, int total){
    if(mask == (1 << (V + 1)) - 1){
        best = min(best, total);
        return;
    }
    if(cur > V){
        return;
    }
    if(taken[cur]){
        return solve(cur + 1, mask, total);
    }
    solve(cur + 1, mask, total);
    int take = coverWith(mask, cur);
    if(take == mask){
        return;
    }
    solve(cur + 1, take, total + 1);
}

int main()
{
    /*freopen("in.in", "w", stdout);
    cout << 2000 << endl;
    for(int i = 1; i <= 2000; i++){
        cout << i << endl;
    }
    return 0;*/
    freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int t;
    cin >> t;

    vector< int > v;
    for(int T = 1; T <= t; T++){
        cin >> C >> D >> V;
        v.clear();
        v.resize(D);
        int covered = 1;
        memset(taken, false, sizeof taken);
        for(int i = 0; i < D; i++){
            cin >> v[i];
            taken[v[i]] = true;
            covered = coverWith(covered, v[i]);
        }
        best = 1e9;
        solve(1, covered, 0);
        cout << "Case #" << T << ": "<< best << endl;
    }

}
