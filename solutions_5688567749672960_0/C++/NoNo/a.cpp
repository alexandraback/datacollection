#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#define ll long long

using namespace std;
ll rev(ll x){
    ll a[20];
    ll i = 0;
    while(x){
        i = i * 10 + x % 10;
        x /= 10;
    }
    return i;
}
int h[1111111];
void bfs(int x){
    queue<int> q;
    q.push(1);
    memset(h, -1, sizeof(h));
    h[1] = 1;
    while(!q.empty()){
        int y = q.front(), p = h[y];
        q.pop();
        ll v = rev(y);
        if (v <= x) if (h[v] == -1){
            h[v] = p + 1;
//            cout<<112<<endl;
            q.push(v);
        }
        v = y + 1;
        if (v <= x)
            if (h[v] == -1) {
            h[v] = p + 1;
//            cout<<222<<endl;
            q.push(v);
        }
    }
}
int main(){
    int T, cas = 0;
    freopen("a.in", "r", stdin);
     freopen("a.out", "w", stdout);
    cin>>T;
    bfs(1000000);
    while(T--){
        ll n;
        cin>>n;
//        ll now = 1;
        ll ans = h[n];
        printf("Case #%d: %I64d\n", ++cas, ans);
    }
    return 0;
}
