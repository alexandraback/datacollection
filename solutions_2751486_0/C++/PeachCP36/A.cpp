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

#define FOR(i,j,k) for(typeof((j)) i = (j), _LENGTH = (k); i < _LENGTH; ++i)
#define FORE(i,j,k) FOR(i,j,k+1)
#define REP(i,k) FOR(i,0,k)
#define FOREACH(i,j) for(typeof((j.begin())) i = j.begin(); i != (j).end(); ++i)

#define SMAX(var,val) var = max(var,val)
#define SMIN(var,val) var = min(var,val)

#define INIT1D(array,val,n) typeof((val)) _VAL = (val); REP(_ITR,n) array[_ITR] = _VAL
#define INIT2D(array,val,n,m) typeof((val)) _VAL = (val); REP(_ITRN,n) REP(_ITRM,m) array[_ITRN][_ITRM] = _VAL

typedef pair<int,int>   pii;
typedef vector<int>     vi;
typedef map<int,int>    mii;
typedef long long int   ll;

int _gcd(int a,int b) { if(b==0)return a; return _gcd(b,a%b);}
inline int gcd(int a,int b) { return (a>=b)?_gcd(a,b):_gcd(b,a); }
ll modPow(ll a, ll m, ll p){
    ll x = 1;
    while(m > 0){
        if((m&1)==1) x = (x * a) % p;
        a = (a * a) % p;
        m >>= 1;
    }
    return x;
}
inline ll modInverse(ll a, ll p) { return modPow(a,p-2,p);}
ll modnCr(ll n, ll r, ll p){
    ll upper = 1, lower = 1;
    REP(i,r) upper = (upper*(n-i)) % p;
    FORE(i,1,r) lower = (lower*i) % p;
    return (upper * modInverse(lower,p)) % p;
}

string vowel = "aeiou";

void solve(){
    string name;
    int n;
    cin >> name >> n;
    int score = 0;
    REP(i,name.size()){
        FOR(j,i+n-1,name.size()){
            int cnt=0;
            bool isOK = false;
            FORE(k,i,j){
                bool isVowel = false;
                FOR(v,0,5){
                    if(name[k]==vowel[v]){
                        isVowel = true;
                        break;
                    }
                }
                if(isVowel) cnt = 0;
                else {
                    cnt++;
                    if(cnt>=n){isOK=true; break;}
                }
            }
            if(isOK)score++;
        }
    }
    cout << score << endl;
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
