#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int,int> pii;

ll otoc(ll a) {
    vector<ll> A;
    while(a>0) {A.push_back(a%10); a/=10;}
    ll res=0;
    For(i,A.size()) {res*=10; res+=A[i];}
    return res;
}

void solve(int p1) {
    ll n;
    scanf("%lld",&n);
    set<ll> S;
    queue<ll> Q;
    Q.push(1); Q.push(1); S.insert(1);
    ll maxi=1;
    while(1) {
        ll x=Q.front(); Q.pop();
        ll k=Q.front(); Q.pop();
        maxi=max(maxi,x);
        if(x==n) {printf("Case #%d: %lld\n",p1,k); return;}
        ll y=x+1;
        //if(maxi<11*y) {
            if(S.find(y)==S.end()) {S.insert(y); Q.push(y); Q.push(k+1);}
        //}
        y=otoc(x);
        //if(maxi<11*y) {
        if(S.find(y)==S.end()) {S.insert(y); Q.push(y); Q.push(k+1);}
        //}
    }
}

int main() {
    int t;
    scanf("%d",&t);
    For(i,t) solve(i+1);
}
