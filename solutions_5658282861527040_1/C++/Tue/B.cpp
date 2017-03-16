//Written by technolt~h
 
#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>
 
#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))
 
#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()
 
#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define ll long long
using namespace std;
 
const double PI = 2.0 * acos (0.0);
 
typedef long long LL;
typedef pair <int, int> PII;
 
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

#define maxn 
#define X first
#define Y second

int a[4][100];
ll f[111][2][2][2];

void pt(int x,int t) {
    FOR(i,1,32) {
        a[t][i]=x%2;
        x/=2;
    }
    FOR(i,1,16) swap(a[t][i], a[t][33-i]);
}

bool build(int i,int sm[],int c[],int nsm[]) {
    FOR(t,1,3) {
        if(sm[t]==1) nsm[t]=1;
        else {
            nsm[t]=a[t][i]>c[t]?1:0;
            if (c[t]>a[t][i])
                return false;
        }
    }
    return true;
}

ll calc(int i,int sm1,int sm2,int sm3) {
    ll &res=f[i][sm1][sm2][sm3];
    if(res!=-1) return res;
    res=0;
    if (i==33) {
        if (sm1==1 && sm2==1 && sm3==1) {
            res=1;
        }
    } else {
        int sm[4];
        sm[1]=sm1;sm[2]=sm2;sm[3]=sm3;
        REP(c1,2) REP(c2,2) {
            int c3=c1&c2;
            int c[4],nsm[4];
            c[1]=c1;c[2]=c2;c[3]=c3;
            if (!build(i,sm,c,nsm))
                continue;
            res+=calc(i+1,nsm[1],nsm[2],nsm[3]);
        }
    }
    return res;
}

int main() {
    int ntest; cin >> ntest;
    FOR(test,1,ntest) {
        int A,B,K;
        cin >> A >> B >> K;
        pt(A,1);
        pt(B,2);
        pt(K,3);
        RESET(f,-1);
        cout << "Case #" << test << ": " << calc(1,0,0,0) << endl;
    }
}