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

//newstate = (newstate-1) & oldstate
/**************************CODE HERE*****************************/

#define oo 1000000009

void OPEN() {
    freopen("B2.in","r",stdin);
    freopen("test.out","w",stdout);
}
int n,m;
pair<int,int> p[2004];
pair<int,int> a[2004];
int d[2004];
void solve() {
    FOR(i,1,n) p[i].second = -p[i].second;
    sort(p+1,p+n+1);
    FOR(i,1,n) p[i].second = -p[i].second;
    memset(d,0,sizeof(d));
    int score_now = 0, res = 0;
    while (true) {
        bool stop = true;
        FOR(i,1,n)
        if (d[i] < 2 && p[i].second <= score_now) {
            score_now += 2 - d[i];
            d[i] = 2;
            stop = false;
            res++;
            break;
        }
        if (!stop) continue;
        int vt = -1;
        int minB = -oo;
        FOR(i,1,n)
        if (d[i] < 1 && p[i].first <= score_now) {
            if (p[i].second > minB) {
                minB = p[i].second;
                vt = i;
            }
        }
        if (vt == -1) break;
        score_now += 1 - d[vt];
        d[vt] = 1;
        res++;
    }
    bool hasSol = true;
    FOR(i,1,n) if (d[i] < 2) hasSol = false;
    if (!hasSol) cout << "Too Bad" << endl;
    else cout << res << endl;
}
int main() {
    OPEN();
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> n;
        FOR(i,1,n) cin >> p[i].first >> p[i].second;
        solve();
    }
    return 0;
}
