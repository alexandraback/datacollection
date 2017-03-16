#include <cstdio>
#include <cmath>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX_NUM 1000001

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll flip(ll v){
    ll ret = 0;
    while(v){
        ret = ret*10+(v%10);
        v /= 10;
    }
    return ret;
}

ll bfs(ll num){
    bool visited[MAX_NUM] = {false};
    visited[1] = true;
    queue<pll> qll;
    qll.push({1, 1});
    
    while(!qll.empty()){
        pll tmp = qll.front(); qll.pop();
        ll v = tmp.first;
        ll n = tmp.second;
        if(v == num)
            return n;
        ll v1 = v+1, v2 = flip(v);
        if(!visited[v1]){
            visited[v1] = true;
            qll.push({v1, n+1});
        }
        if(!visited[v2]){
            visited[v2] = true;
            qll.push({v2, n+1});
        }
    }
    return -1;
}
int main()
{
    freopen("/Users/bochen/Downloads/textfile.in","r", stdin);
    freopen("/Users/bochen/Downloads/textfile.out","w", stdout);

    int t;
    cin >> t;
    for(int cid = 1; cid <= t; cid++){
        ll num;
        cin >> num;
        printf("Case #%d: %lld\n", cid, bfs(num));
    }
    return 0;
}
