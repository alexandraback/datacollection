#include <bits/stdc++.h>

using namespace std;

typedef long long llong;
llong rev(llong k){
    llong x = 0;
    while(k){
        llong d = k % 10ll;
        k /= 10ll;
        x = x * 10ll + d;
    }
    return x;
}

llong solveSlow(llong n){
    queue<pair<llong, llong>> q;
    const llong LIM = 10ll * n + 1ll;
    vector<bool> vis(LIM);
    q.push({1, 1});
    vis[1] = true;
    while(not q.empty()){
        auto here = q.front();
        q.pop();
        if(here.first == n) return here.second;
        
        pair<llong, llong> next1(here.first + 1, here.second + 1);
        assert(next1.first < LIM);
        if(not vis[next1.first]){
            vis[next1.first] = true;
            q.push(next1);
        }

        pair<llong, llong> next2(rev(here.first), here.second + 1);
        assert(next2.first < LIM);
        if(not vis[next2.first]){
            vis[next2.first] = true;
            q.push(next2);
        }
    }

    return -1;
}
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        llong n;
        cin >> n;

        cout << "Case #" << tc << ": " << solveSlow(n) << endl;
    }
}
