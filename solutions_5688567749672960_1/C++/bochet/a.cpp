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

ll dfs(ll num){
    if(num % 10 == 0)
        return dfs(num-1)+1;
    if(num == 1)
        return 1;
    ll tmp = num;
    vector<ll> digit;
    while(tmp){
        digit.push_back(tmp%10);
        tmp /= 10;
    }
    reverse(digit.begin(), digit.end());
    
    int len = digit.size();
    ll first = 0, second = 0;
    for(int i = 0; i < len/2; i++)
        first = first*10+digit[len/2-1-i];
    for(int i = len/2; i < len; i++)
        second = second*10+digit[i];
    ll base = pow(10, len-1);
    return dfs(base)+min(first+second, num-base);
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
//        printf("Case #%d: %lld %lld\n", cid, bfs(num), dfs(num));
        printf("Case #%d: %lld\n", cid, dfs(num));
    }
    return 0;
}
