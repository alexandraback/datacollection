#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(i,a,b) for(int i=a; i>=b; i--)
#define FORAD(i,u) for(int i=0; i < (int)u.size(),i++)
#define BUG(x) cout << x << endl
#define ll long long
#define fi first
#define sd second
#define pb push_back
#define two(i) 1 << i
#define sz(x) (int)x.size()
#define e 1e-12
#define bit(s,i) ((s >> (i-1)) & 1)
#define Nmax 100100
const double pi = acos(-1);
typedef vector<int> vi ;
typedef pair<int,int> pii ;

int A, B, K, n, tmp;
string SA, SB, SK;
long long f[50][2][2][2];
int dd[50][2][2][2];


string convert(int x) {
    string res = "";
    while (x) {
        res = (char)(x % 2 + '0') + res;
        x /= 2;
    }
    return res;
}

long long cal(int i, int ok1, int ok2, int ok3) {
    if (i == n) return 1;
    if (dd[i][ok1][ok2][ok3] == tmp) return f[i][ok1][ok2][ok3];
    dd[i][ok1][ok2][ok3] = tmp;
    long long res = 0;
    int last1, last2, last3, ok1_, ok2_, ok3_;
    if (ok1 == 1) last1 = (int)(SA[i] - '0'); else last1 = 1;
    if (ok2 == 1) last2 = (int)(SB[i] - '0'); else last2 = 1;
    if (ok3 == 1) last3 = (int)(SK[i] - '0'); else last3 = 1;
    FOR(x1, 0, last1) FOR(x2, 0, last2) {
        int x3 = (x1 & x2);
        if (ok3 == 1 && last3 < x3) continue;
        if (x1 == last1) ok1_ = ok1; else ok1_ = 0;
        if (x2 == last2) ok2_ = ok2; else ok2_ = 0;
        if (x3 == last3) ok3_ = ok3; else ok3_ = 0;
        res += cal(i+1, ok1_, ok2_, ok3_);
    }
    f[i][ok1][ok2][ok3] = res;
    return res;
}

int main() {
     freopen("B-large.in","r",stdin);
     freopen("ans.out","w",stdout);


     int test;
     cin >> test;
     FOR(t, 1, test) {
         cin >> A >> B >> K;
         A -= 1; B -= 1; K -= 1;
         SA = convert(A);
         SB = convert(B);
         SK = convert(K);
         n = max(sz(SA), max(sz(SB), sz(SK)));
         while (sz(SA) < n) SA = '0' + SA;
         while (sz(SB) < n) SB = '0' + SB;
         while (sz(SK) < n) SK = '0' + SK;
         //cout << SA << ' ' << SB << ' ' << SK << ' ' << n << endl;
         tmp++;
         cout << "Case #" << t << ": " << cal(0, 1, 1, 1) << endl;
     }

     return 0;
}




