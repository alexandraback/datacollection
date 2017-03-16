#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;
typedef long long int ll;

int cache[1000001];

ll reverse(ll a) {
    if(a % 10 == 0) return a;
    ll re = 0;
    while(a != 0) {
        int t = a % 10;
        re = re * 10 + t;
        a = a / 10;
    }
    return re;
}

void prepare() {
    for(int i=1; i<1000001; i++) {
        ll r = reverse(i);
        if(r < i) {
            cache[i] = min(cache[i-1], cache[r]) + 1;
        } else {
            cache[i] = cache[i-1] + 1;
        }
    }
}

int main() {
    int T;
    cin>>T;
    memset(cache, -1, sizeof(cache));
    cache[0] = 0;
    prepare();
    for(int tcas=1; tcas<=T; tcas++) {
        ll n;
        cin>>n;
        cout<<"Case #"<<tcas<<": ";
        cout<<cache[n];
        cout<<endl;
    }
}
        
