#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <complex>
#include <ctime>
#include <iomanip>
#include <cassert>
#include <sstream>
#include <iterator>

using namespace std;

#define file "file"
#define mp make_pair
#define pb push_back
#define xx real()
#define yy imag()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef complex<double> point;

const ll INF = 1e17;
const int MAXN = 1e6 + 5;
const int LIM = 1e4;

ll calc(ll a){
    ll ans = 0;
    while(a){
        ans *= 10;
        ans += a % 10;
        a /= 10;
    }
    return ans;
}
map<ll,ll> list;
ll ans = INF;
ll dp[MAXN];

void rec_sol(ll cur,ll n,ll step){
    if(list.find(cur) != list.end()){
       if(list[cur] < step) return;
    }
    if(step > ans) return;
    if(cur > n) return;
    if(cur == n){
        ans = min(ans, step);
        return;
    }
    list[cur] = step;
    ll to1 = cur + 1;
    ll to2 = calc(cur);
    rec_sol(to2,n,step + 1);
    rec_sol(to1,n,step + 1);
}

void precalc(){
    for(int i = 1;i <= 1002;i++){
        list.clear();
        printf("%d ",i);
        ans = INF;
        rec_sol(1,i,1);
        printf("%I64d\n",ans);
    }
}

void precalc2(){
    dp[1] = 1;
    for(int i = 2;i < MAXN;i++){
        dp[i] = INF;
    }
    for(int i = 1;i < MAXN;i++){
        ll to1 = i + 1;
        ll to2 = calc(i);
        if(to1 < MAXN) dp[to1] = min(dp[to1], dp[i] + 1);
        if(to2 < MAXN) dp[to2] = min(dp[to2], dp[i] + 1);
    }
//    for(int i = 1;i < 10102;i++){
//        printf("%d %I64d\n",i,dp[i]);
//    }
}

ll numlog(ll n){
    if(n == 1) return 0;
    return numlog(n >> 1) + 1;
}

ll calc2(ll n){
    if(n <= LIM) return dp[n];
    ll fi = n - 200;
    ll se = n - 100;
    ll cur = calc2(fi);
    ll cur2 = calc2(se);
    return cur2 + cur2 - cur;
}

void solve(){
    ll n;
    scanf("%I64d",&n);
    printf("%I64d\n",dp[n]);
    return;
    ll cur = 1;
    ll ans = 1;
    if(n <= 20){
        printf("%I64d\n",n);
        return;
    }
    else if(n >= 21 && n <= 100){
        ll k = (n - 21) / 10;
        ll beg = k * 10 + 21;
        ll dt = n - beg;
        ll beg2 = k + 13;
        ans = beg2 + dt;
    }
    else if(n >= 101 && n <= 200){
        ans = 30 + n - 101;
    }
    else if(n >= 201 && n <= 1000){
        ll k = (n - 201) / 100;
        ll beg = k * 100 + 201;
        ll dt = n - beg;
        ll beg2 = k + 32;
        ans = beg2 + dt;
    }
    else if(n >= 1001 && n <= 1100){
        ans = 139 + n - 1001;
    }
    else if(n >= 1101 && n <= 10000){
        ll k = (n - 1101) / 100;
        ll beg = k * 100 + 1101;
        ll dt = n - beg;
        ll beg2 = k * 10 + 150;
        ans = beg2 + dt;
    }
    else if(n >= 10001){
        ans = 338 + n - 1001;
    }
    printf("%I64d\n",ans);
}

int main()
{
	#ifndef ONLINE_JUDGE
    assert(freopen("input.txt","r",stdin));
    assert(freopen("output.txt","w",stdout));
    #else
    //assert(freopen(file".in","r",stdin)); assert(freopen(file".out","w",stdout));
    #endif
    precalc2();//return 0;
	int t = 1;
	int cs = 1;
	scanf("%d",&t);
	while(t--){
       printf("Case #%d: ",cs++);
		solve();
	}
	return 0;
}
