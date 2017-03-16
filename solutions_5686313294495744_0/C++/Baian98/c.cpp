//
//  c.cpp
//  Round 1B 2016
//
//  Created by Bayan on 30.04.16.
//  Copyright © 2016 Bayan. All rights reserved.
//
#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#define y1 lalka
#define right napravo
#define left nalevo
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = (int)1e9+7, N = (int)1e5+123, M = (int)1e6+123;
const double eps = 1e-9;
const long long inf = 1e18 + 17;

int tests;
int n;
pair<string, string> a[1005];
int calc(int mask){
    unordered_map<string, int> cnt1, cnt2;
    for(int i=1; i<=n; i++){
        if(mask & (1<<(i-1))){
            cnt1[a[i].f]++;
            cnt2[a[i].s]++;
        }
    }
    int res = 0;
    for(int i=1; i<=n; i++){
        if(!(mask & (1<<(i-1)))){
            if(cnt1[a[i].f] && cnt2[a[i].s]){
                res++;
            }
        }
    }
    return res;
}
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    freopen("C-small-attempt2.in.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    cin>>tests;
    for(int test=1; test <= tests; test++){
        cout<<"Case #"<<test<<": ";
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>a[i].f>>a[i].s;
        }
        int ans = 0;
        for(int mask = 1; mask < (1 << n); mask ++){
            ans = max(ans, calc(mask));
        }
        cout<<ans<<"\n";
        cerr<<test<<"\n";
    }

    
    return 0;
}
