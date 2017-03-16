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

ll _reverse(ll n){
    ll res = 0;
    while(n > 0){
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

map<int, int> vis;
set< int > S;

void bfs(){
    queue<ll> q;
    vis[1] = 1;
    q.push(1);
    while(!q.empty()){
        ll cur = q.front(); q.pop();
        ll cost = vis[cur];
        S.erase(cur);
        if(S.empty()) return;
        if(!vis.count(cur + 1)){
            vis[cur + 1] = cost + 1;
            q.push(cur + 1);
        }
        ll rev = _reverse(cur);
        if(!vis.count(rev)){
            vis[rev] = cost + 1;
            q.push(rev);
        }
    }
    assert(false);
}

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= 1000000; i++){
        S.insert(i);
    }
    bfs();
    for(int T = 1; T <= t; T++){
        int n;
        cin >> n;
        cout << "Case #" << T << ": " << vis[n] << endl;
    }
}
