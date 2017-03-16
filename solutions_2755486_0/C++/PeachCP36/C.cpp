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

const int MAXN = 10;

int day[MAXN];
int nAttack[MAXN];
int west[MAXN];
int east[MAXN];
int strength[MAXN];
int dDay[MAXN];
int dP[MAXN];
int dStrength[MAXN];

int* wall, *wall2;

typedef pair<pii,pii> ppp;
typedef priority_queue<ppp> priorQ;

void solve(){
    int n;
    cin >> n;
    REP(i,n){
        cin >> day[i] >> nAttack[i] >> west[i] >> east[i] >> strength[i] >> dDay[i] >> dP[i] >> dStrength[i];
    }
    int **pWall = new int*[2];
    pWall[0] = (wall + 1000);
    pWall[1] = (wall2 + 1000);
    FORE(i,-400,400) pWall[0][i]=pWall[1][i] = 0;
    priorQ q;
    REP(i,n){
        REP(j,nAttack[i]){
            q.push(ppp(
                    pii(-(day[i] + j*dDay[i]), strength[i] + j*dStrength[i] ),
                    pii(west[i]+j*dP[i], east[i]+j*dP[i])
                    )
                  );
        }
    }
    int sWall = 0;
    int currentDay = 0;
    int cntSuccess = 0;
    while(!q.empty()){
        ppp p = q.top(); q.pop();
        if(p.fi.fi==currentDay){
            bool success = false;
            for(int i = p.se.fi*2; i <= p.se.se*2; ++i){
                if(pWall[sWall][i]<p.fi.se){
                    success = true;
                    pWall[1-sWall][i] = p.fi.se;
                }
            }
            if(success) {
                cntSuccess++;
                //printf("[%d,%d]\n",p.se.fi,p.se.se);
            }
        }
        else{
            currentDay = p.fi.fi;
            sWall=1-sWall;
            FORE(i,-400,400) pWall[1-sWall][i]=pWall[sWall][i];
            bool success = false;
            for(int i = p.se.fi*2; i <= p.se.se*2; ++i){
                if(pWall[sWall][i]<p.fi.se){
                    success = true;
                    pWall[1-sWall][i] = p.fi.se;
                }
            }
            if(success){
                cntSuccess++;
                //printf("[%d,%d]\n",p.se.fi,p.se.se);
            }
        }
    }
    cout << cntSuccess << endl;
}

int main(){
    wall = new int[2000];
    wall2 = new int[2000];
    //freopen("Ctest.in","r",stdin);
    freopen("Csmall.in","r",stdin);
    freopen("Csmall.out","w",stdout);
    int _test;
    scanf("%d",&_test);
    FORE(t,1,_test){
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}
