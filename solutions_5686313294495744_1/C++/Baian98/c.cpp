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

int tests, n;
pii a[1005];
struct node{
    pii a[1002];
    int res = 0;
    void calc(){
        int cnt1[1002], cnt2[1002];
        for(int i=1; i<=n; i++)cnt1[i] = cnt2[i] = 0;
        bool start = 0;
        res = 0;
        for(int i=1; i<=n; i++){
            if(!start && cnt1[a[i].f] && cnt2[a[i].s]){
                start = 1;
            }
            if(!start){
                cnt1[a[i].f]++;
                cnt2[a[i].s]++;
            }
            else{
                if(cnt1[a[i].f] && cnt2[a[i].s]) res--;
            }
        }
    }
}now, nxt;
int main ()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    freopen("C-large.in.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    cin>>tests;
    for(int test=1; test <= tests; test++){
        cout<<"Case #"<<test<<": ";
        unordered_map<string, int> used1, used2;
        cin>>n;
        for(int i=1; i<=n; i++){
            string s, t;
            cin>>s>>t;
            if(!used1.count(s)){
                used1[s] = used1.size() + 1;
            }
            if(!used2.count(t)){
                used2[t] = used2.size() + 1;
            }
            a[i] = mp(used1[s], used2[t]);
        }
        for(int i=1; i<=n; i++) now.a[i] = a[i];
        random_shuffle(now.a+1, now.a + n + 1);
        now.calc();
        double T = 30;
        int ans = -now.res;
        for(int i=1; i <= 200000; i++){
            nxt = now;
            int f = rand()%n+1, s = rand()%n+1;
            swap(nxt.a[f], nxt.a[s]);
            nxt.calc();
            ans = max(ans, -nxt.res);
            double d = nxt.res - now.res;
            if (d < 0 || exp(-d / T) > double(rand() % 1024) / double(1024)) {
                now = nxt;
            }
            T *= 0.98;
        }
        cout<<ans<<"\n";
        cerr<<test<<"\n";
    }

    
    return 0;
}
