#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define fi first
#define se second

#define FOR(i,j,k) for(typeof((j)) i = (j); i < (k); ++i)
#define FORE(i,j,k) for(typeof((j)) i = (j); i <= (k); ++i)
#define FOREACH(i,j) for(typeof((j.begin())) i = j.begin(); i != (j).end(); ++i)

typedef pair<int,int>   pii;
typedef vector<int>     vi;
typedef map<int,int>    mii;
typedef long long int   ll;

int _gcd(int a,int b) { if(b==0)return a; return _gcd(b,a%b);}
inline int gcd(int a,int b) { return (a>=b)?_gcd(a,b):_gcd(b,a); }

void solve(){
    ll r, t;
    cin >> r >> t;
    ll cnt=0;
    while(true){
        t-=(r+1)*(r+1)-r*r;
        if(t<0)break;
        cnt++;
        r+=2;
    }
    cout << cnt << endl;
}

int main(){
    freopen("Asmall.in","r",stdin);
    freopen("Asmall.out","w",stdout);
    int _test;
    scanf("%d",&_test);
    FORE(t,1,_test){
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}
