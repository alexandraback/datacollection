/// in the name of ALLAH

///#include <bits\stdc++.h>

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <deque>
#include <sstream>
#include <string>
#include <fstream>
#include <utility>
#include <cstring>

#define bits(a) __builtin_popcount(a)
#define ll long long
int dx[] = {1 , -1 , 0 , 0 };
int dy[] = {0 ,  0 , 1 , -1};
const int mod = (int)1e9 + 7;
const int oo = 1<<30;
const ll loo = (ll)1<<60;
const double pi = 3.14159265359;
const int N = (int) 50 + 5;

using namespace std;
int v[N][N];
//#define in cin
//#define out cout
int ans;
bool ok;
int limit;
ll n , m;
void put(int i) {
    int r = 0 , cur = n - 1;
    while(i >= cur){
        i -= cur;
        r++;
        cur --;
    }
    v[r][i+r+1] = 1;
}
bool bit(int i , int bm) {
    return (1<<i) & bm;
}
bool memo[1<<20];
int dfs(int src) {
    if(src == n-1)
        return 1;
    int res = 0;
    for(int i = 0; i < n; i ++)
        if(v[src][i])
            res += dfs(i);
    return res;
}
bool valid(int bm) {
    memset(v, 0, sizeof v);
    for(int i = 0; i < limit; i ++) {
        if(bit(i , bm)) {
            put(i);
        }
    }
    if(dfs(0) == m)
        return true;
    return false;
}
void solve(int bm) {
    if(ok)
        return;
    if(valid(bm)) {
        ans = bm;
        ok = true;
        return;
    }
    if(memo[bm])
        return;
    for(int i = 0; i < limit; i ++) {
        if(!bit(i , bm)) {
            solve(bm | (1<<i));
        }
    }
    memo[bm] = true;
}





int main() {
    fstream  in("B-small-attempt2.in" , ios::in);
    fstream out("out.out" , ios::out);
    int t;
    in >> t;
    for(int q = 1; q <= t; q ++){
        in >> n >> m;
        ok = false;
        limit = (n-1)*n / 2;
        out << "Case #" << q << ": ";
        memset(memo , 0 , sizeof memo);
        solve(0);
        if(ok) {
            out << "POSSIBLE\n";
            for(int i = 0; i < n; i ++) {
                for(int j = 0; j < n; j ++) {
                    out << v[i][j];
                }
                out << endl;
            }
        } else {
            out << "IMPOSSIBLE\n";
        }
    }
}
