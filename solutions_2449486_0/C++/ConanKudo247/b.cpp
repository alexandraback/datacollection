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
/*******************************CODE HERE***********************************/
#define maxn 104
int m,n;
int H[maxn][maxn];
int a[maxn][maxn];
bool check() {
    // init
    FOR(i,1,m) FOR(j,1,n) a[i][j] = 100;

    // process
    DOWN(height,100,1) {
        //try to go horizontally
        FOR(row,1,m) {
            bool ok = true;
            FOR(col,1,n)
            if (H[row][col] > height) ok = false;
            if (ok) {
                FOR(col,1,n) a[row][col] = height;
            }
        }
        //try to gp vertically
        FOR(col,1,n) {
            bool ok = true;
            FOR(row,1,m)
            if (H[row][col] > height) ok = false;
            if (ok) {
                FOR(row,1,m) a[row][col] = height;
            }
        }
        FOR(i,1,m) FOR(j,1,n)
        if (H[i][j] == height && a[i][j] != height) return false;
    }
    // check
    FOR(i,1,m) FOR(j,1,n) if (H[i][j] != a[i][j]) return false;
    return true;
}
int main() {
    freopen("B_small.in","r",stdin);
    freopen("test.out","w",stdout);
    int nTest;
    cin >> nTest;
    FOR(test,1,nTest) {
        cout << "Case #" << test << ": ";
        cin >> m >> n;
        FOR(i,1,m) FOR(j,1,n) cin >> H[i][j];
        if (check()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
