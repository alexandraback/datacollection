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

long double C(int k, int n) {
    long double res = 1;
    FOR(i,k+1,n) res = res * (double)i / (i - k);
    return res;
}
long long N,X,Y;
long double res = 0;
int dist;
int aim;
void attempt(int cur, long double prob, int L, int R) {
    if (R == aim) {
        res += prob;
        return;
    }
    if (cur == N+1) return;

    double cur_prob = 0.5;
    if (L == 2 * dist-1) cur_prob = 1;
    if (R == 2 * dist-1) cur_prob = 1;

    if (L < 2*dist-1) {
        attempt(cur+1,prob*cur_prob,L+1,R);
    }
    if (R < 2 * dist-1) {
        attempt(cur+1,prob*cur_prob,L,R+1);
    }
}
void solve() {
    dist = 0;
    int total = 1;
    while (N > total) {
        N -= total;
        dist++;
        total = dist * 2 * 2 + 1;
    }
    int my_dist = (abs(X) + abs(Y))/2;
    if (my_dist < dist) {
        cout << "1.0" << endl;
        return;
    }
    if (my_dist > dist) {
        cout << "0.0" << endl;
        return;
    }
    if (N == total) {
        cout << "1.0" << endl;
        return;
    }
    res = 0;
    aim = abs(Y);
    if (aim == dist * 2) {
        if (N == total) {
            cout << "1.0" << endl;
            return;
        } else {
            cout << "0.0" << endl;
            return;
        }
    }

    attempt(1,1,-1,-1);
    /*
    long double val = 1;
    long double val2 = 1;
    FOR(i,1,N) val *= 2;
    FOR(i,1,dist*2) val2 *= 2;
    int threshold = min((int)N-1,dist*2-1);
    FOR(i,aim,threshold) {
        int selected = i + 1; //select ra i cai o ben nay
        if (i != dist * 2 - 1)
        res = res + C(selected,N) / val;
        else res = res + C(selected,N) / val2;
        cout <<res << " " << val2 << " " << C(selected,N) << endl;
    }*/
    printf("%.9lf\n",(double)res);
}
int main() {
    freopen("test.in","r",stdin);
   freopen("test.out","w",stdout);
    int ntest;
    scanf("%d",&ntest);
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> N >> X >> Y;
        solve();
    }
    return 0;
}
