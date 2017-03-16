#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 105;

ll power_of(ll base, ll expo){
    ll prod = 1;
    for(int i = 1; i <= expo; i++)  prod *= base;
    return prod;
}

int main(){
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("lol.out", "w", stdout);
    int t, k, c, s;
    cin>>t;
    for(int big = 1; big <= t; big++){
        cin>>k>>c>>s;
        cout<<"Case #"<<big<<": ";
        for(int i = 1; i <= k; i++) cout<<i<<" ";
        cout<<endl;
    }
}
