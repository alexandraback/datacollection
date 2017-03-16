#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 55;

int remaining;
bool visited[10];

void count_in(ll x){
    while(x){
        if(!visited[x % 10])    visited[x % 10] = 1, remaining--;
        x /= 10;
    }
}

int main(){
    freopen("A-large.in", "r", stdin);
    freopen("lol.out", "w", stdout);
    ll t, x;
    cin>>t;
    for(int big = 1; big <= t; big++){
        cout<<"Case #"<<big<<": ";
        cin>>x;
        if(x == 0)  cout<<"INSOMNIA"<<endl;
        else{
            ll i;
            remaining = 10;
            memset(visited, 0, sizeof(visited));
            for(i = 1; remaining != 0;i++)  count_in(1LL * i * x);
            ll ans = 1LL * (i - 1) * x;
            cout<<ans<<endl;
        }
    }
}
