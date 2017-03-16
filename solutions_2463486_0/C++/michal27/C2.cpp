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

#define For(i,n) for(ll i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;

bool palindrome(ll a) {
    vector<int> A;
    if(a==0) A.push_back(0);
    while(a>0) {A.push_back(a%10); a/=10;}
    bool t=true;
    For(i,A.size()) if(A[i]!=A[A.size()-i-1]) t=false;
    return t;
}

ll solve(ll h) {
    ll vys=0;
    //parne palindromy
    For(i,h+1) {
        if(i==0) continue;
        ll pom=i;
        ll p=i;
        while(p>0) {pom*=10; pom+=p%10; p/=10;}
        if(pom*pom>h) break;
        if(palindrome(pom) && palindrome(pom*pom)) vys++;
    }
    //neparne palindromy
    For(i,h+1) {
        if(i==0) continue;
        ll pom=i;
        ll p=i; p/=10;
        while(p>0) {pom*=10; pom+=p%10; p/=10;}
        if(pom*pom>h) break;
        if(palindrome(pom) && palindrome(pom*pom)) vys++;
    }
    return vys;
}

int main() {
    int t;
    scanf("%d ",&t);
    For(i,t) {
        ll a,b;
        scanf("%lld %lld ",&a,&b);
        printf("Case #%d: ",(int)i+1);
        printf("%lld\n",solve(b)-solve(a-1));
    }
return 0;
}
