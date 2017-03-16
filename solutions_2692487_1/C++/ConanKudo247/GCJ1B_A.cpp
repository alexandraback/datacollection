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

#define maxn 200
int n,A;
int a[maxn];
int get_solution(int last) {
    if (last == 0) return 0;
    long long Now = A;
    int res = 0;
    FOR(i,1,last) {
        if (Now > a[i]) Now += a[i];
        else {
            while (Now <= a[i]) {
                if (Now == 1) return -1;
                Now = Now + (Now-1);
                res++;
            }
            Now += a[i];
        }
    }
    return res;
}
void solve() {
    int res = oo;
    sort(a+1,a+n+1);
    DOWN(last_mote,n,0) {
        int n_step = get_solution(last_mote);
        if (n_step == -1) continue;
        res = min(res, n_step + n - last_mote);
    }
    cout << res << endl;
}
int main() {
    freopen("A-large.in","r",stdin);
    freopen("test.out","w",stdout);
    int ntest;
    scanf("%d",&ntest);
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> A >> n;
        FOR(i,1,n) cin >> a[i];
        solve();
    }
    return 0;
}
