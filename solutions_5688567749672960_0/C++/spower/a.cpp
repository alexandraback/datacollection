#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;

map<long long, long long> mp;
long long n;
inline long long rvs(long long x) {
    long long res = 0;
    while(x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}
long long getfind(long long x) {
    // cout<<"x="<<x<<" n="<<n<<endl;
    if(x > n) return n + 1;
    if(mp.find(x) != mp.end())
        return mp[x];
    long long res = rvs(x);
    // cout<<"x="<<x<<" res="<<res<<endl;
    if(res > x && res <= n)
        res = getfind(res);
    else
        res = n;
    long long inc = getfind(x+1);
    // cout<<"res="<<res<<" inc="<<inc<<endl;
    return mp[x] = ((res < inc) ? res : inc) + 1;
}
int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++) {
        cin>>n;
        mp.clear();
        mp[n] = 0;
        // cout<<"n="<<n<<endl;
        cout<<"Case #"<<cas<<": "<<getfind(0)<<endl;
    }
    return 0;
}
