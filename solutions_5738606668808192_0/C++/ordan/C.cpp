#include <bits/stdc++.h>
#define ll long long

int MAX;

using namespace std;

long long power (ll n, ll p, ll b){
    ll k = 1;
    if (p == 0) return 1;
    for (ll i = 0; i < p; i++){
        k = (k * n) % b;
    }
    return k;
}

bool eequal (ll n, ll b, ll d){
    ll number = 0;
    for (ll i = 32; i >= 0; i--){
        if (n & (1LL<<i)){
            if (i == 0) number += 1;
            else{
                ll k = 1;
                for (int j = 0; j < i; j++){
                    k *= b;
                    if (k > d) return false;
                }
                number += k;
            }
            if (number > d) return false;
        }
    }

    return number == d;
}

long long solve2 (ll n, ll b){

    for (ll j = 2; j < MAX; j++){
        ll number = 0;
        if (eequal(n, b, j)) continue;
        for (ll i = 32; i >= 0; i--){
            if (n & (1LL<<i))
                number = (number + power(b, i, j)) % j;
        }
        if ((number) % j == 0) return j;
    }
    return -1LL;
}

void print (ll n){
    if (n){
        print (n>>1);
        printf ("%lld", n&1LL);
    }
}

void solve (ll n, ll j){
    ll number = 1LL << (n - 1);
    while (j){
        number++;
        if ((number&1LL)==0) number++;
        vector <ll> ans;
        for (ll i = 2; i <= 10; i++){
            ll d = solve2(number, i);
            if (d == -1) break;
            ans.push_back(d);
        }
        if (ans.size() == 9){
            print (number);
            for (ll i = 0; i < ans.size(); i++)
                printf (" %lld", ans[i]);
            j--;
            printf ("\n");
            if (number > (1LL << (n)) -1){
                cout << 1/0;
            }
        }
    }

}

int main(){
    MAX = 100000;
    int t, c = 1;
    scanf ("%d", &t);

    while (t--){
        ll n, m;
        scanf ("%lld %lld", &n, &m);
        printf ("Case #%d:\n",c++);
        solve(n, m);
    }


    return 0;
}

