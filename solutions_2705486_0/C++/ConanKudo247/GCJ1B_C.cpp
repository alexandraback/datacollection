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

vector<string> ls;
string s;

    ofstream output;
int n;
int f[52][52];
char a[53];
void solve() {
    memset(f,0,sizeof(f));
    FOR(i,0,50)
    FOR(j,0,50) f[i][j] = oo;
    f[0][0] = 0;
    n = s.size();
    FOR(i,1,n) a[i] = s[i-1];


    FOR(i,0,n-1)
    FOR(j,0,50) if (f[i][j] != oo) {
        FR(t,ls.size())
        if (i + ls[t].size() <= n) {
            int fn = i + ls[t].size();
            int st = i+1,first;
            int cost = 0;
            if (j == 0) first = -oo;
            else first = j;
            bool valid = true;
            FOR(k,st,fn)
            if (a[k] != ls[t][k-st]) {
                if (abs(first - k) <5) {
                    valid = false;
                    break;
                }
                cost++;
                first = k;
            }
            if (!valid) continue;
            if (first == -oo) first = 0;
            f[i+ls[t].size()][first] = min(f[i+ls[t].size()][first], f[i][j] + cost);
        }
    }
    int res = oo;
    FOR(j,0,50) res = min(res,f[n][j]);
    output << res << endl;
}
int main() {
    ifstream dict;
    dict.open("dict.txt");
    int len = 0;
    while (dict >> s) {
        ls.push_back(s);
    }

    ifstream input;
    input.open("test.in");
    output.open("test.out");
    int ntest;
    input >> ntest;
    FOR(test,1,ntest) {
        output << "Case #" << test << ": ";
        input >> s;
        solve();

    }

    input.close();
    output.close();
    dict.close();
    //freopen("test.out","w",stdout);

    return 0;
}
