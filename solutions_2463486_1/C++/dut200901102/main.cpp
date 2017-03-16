#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
const ll up = 1e14;

vector<ll> vec;
ll l, r;

bool check(ll x){
    string xx, yy;
    while(x){
        xx += x % 10 + '0';
        yy += x % 10 + '0';
        x /= 10;
    }
    reverse(xx.begin(), xx.end());
    return xx == yy;
}
void init(){
    for(ll i = 1; i * i <= up; ++i){
        if(check(i) && check(i * i))
            vec.push_back(i * i);
    }
}
int main(){
    int t, cas = 1;
    init();
    for(cin >> t; t--; ){
        printf("Case #%d: ", cas++);
        cin >> l >> r;
        int cnt = 0;
        for(int i = 0; i < vec.size(); ++i)
            if(vec[i] >= l && vec[i] <= r) cnt++;
        cout << cnt << endl;
    }
    return 0;
}
