//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <string>
#include <queue>
#include <fstream>

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DR(i,a) for(int i = (a)-1; i >=0; i--)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)
#define FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define PB push_back
#define MP make_pair

#define F first
#define S second
#define RESET(c,x) memset(c,x,sizeof(c))
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()

#define REP(i,a) for(int i = 0; i < (a); i++)

#define sqr(x) ((x)*(x))
#define oo 1000000009
using namespace std;
/*************************TEMPLATE**********************************/
long long convertToNum(string s)
{
    long long val = 0; FR(i,s.size()) val = val * 10 + s[i] - '0';
    return val;
}
char bu[50];
string convertToString(int a) {
    sprintf(bu,"%d",a);
    return string(bu);
}
long long GCD(long long x,long long y)  {
    if (!x) return y; if (!y) return x;
    if (x == y) return x; if (x < y) return GCD(x,y%x); else return GCD(x%y,y);
}
long long POW(long long x,long long y,long long Base){
    if (!y) return 1; long long u = POW(x,y/2,Base);
    u = (u * u) % Base;
    if (y & 1) return (u * x) % Base; else return u;
}
void extended_euclid(long long A, long long B, long long &x,long long &y) {
    if (A == 1 && B == 0) {
        x = 1;
        y = 0;
        return;
    }
    if (A < B) extended_euclid(B,A,y,x);
    else {
        long long xx,yy;
        extended_euclid(A%B,B,xx,yy);
        x = xx;
        y = yy - (A/B)*xx;
        
    }
}
//newstate = (newstate-1) & oldstate
/**************************CODE HERE*****************************/
#define maxn 140
int n,S,p;
int a[maxn],b[maxn],c[maxn];
int f[maxn][maxn];
void OPEN() {
    freopen("b0.in","r",stdin);
    freopen("output.txt","w",stdout);
}
int main() {
    OPEN();
    FOR(t,0,30) {
        a[t] = b[t] = -1;
        //tinh a[i]
        FOR(j,0,10) {
            int d = t - j * 3;
            if (0 <= d && d <= 2) {
                if (d == 0) a[t] = j;
                else a[t] = j + 1;
                break;
            }
        }
        // tinh b[i]
        FOR(j,0,8) {
            int d = t - j * 3 - 2;
            if (0 <= d && d <= 2) {
                b[t] = j + 2;
                break;
            }
        }
    }
    
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> n >> S >> p;
        FOR(i,1,n) cin >> c[i];
        FOR(i,0,n) FOR(j,0,S) f[i][j] = -oo;
        f[0][0] = 0;
        FOR(i,1,n) FOR(j,0,S) {
            if (a[c[i]] != -1) f[i][j] = f[i-1][j] + (a[c[i]] >= p ? 1:0);
            if (j && b[c[i]] != -1) f[i][j] = max(f[i][j],
                                               f[i-1][j-1] + (b[c[i]] >= p ? 1:0));
        }
        cout << f[n][S] << endl;
    }
    return 0;
}
    
