#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define foreach(u, o) \
    for (typeof((o).begin()) u = (o).begin(); u != (o).end(); ++u)
const int INF = 2147483647;
const double EPS = 1e-9;
const double pi = acos(-1);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T mod(T a, T b) { return (a % b + b) % b; }
template <class T> int size(const T &x) { return x.size(); }

int mem[3][8][10000];
int L, X, LX;
string st;

int quaternions[4][4] =
{
    {1, 2, 3, 4},
    {2, -1, 4, -3},
    {3, -4, -1, 2},
    {4, 3, -2, -1}
};

int mul(int a, int b){
    //if(a < 0 && b < 0){
        //return quaternions[abs(a)-1][abs(b)-1];
    //} else if(a < 0 || b < 0){
        //return -quaternions[abs(a)-1][abs(b)-1];
    //} else {
        //return quaternions[abs(a)-1][abs(b)-1];
    //}
    //int bla = a*b < 0 ? -quaternions[abs(a)-1][abs(b)-1] : quaternions[abs(a)-1][abs(b)-1];
    ////printf("%d %d %d\n", a, b, bla);
    //return bla;
    return a*b < 0 ? -quaternions[abs(a)-1][abs(b)-1] : quaternions[abs(a)-1][abs(b)-1];
}

//int div(int a, int b){
    //if(abs(a) == 1){
        //return mul(1, b);
    //} else {
        //return mul(-a, b);
    //}
//}

int toint(int q){
    return q > 0 ? q + 3 : -q - 1;
}

int ch(int i){
    return st[i % L] - 'i' + 2;
}

bool dp(int spl, int x, int at){
    if(at >= LX){
        //printf("dp: %d %d %d = %d\n", at, spl, x, (spl == 0 && x == 4));
        return (spl == 0 && x == 4);
    }
    if(mem[spl][toint(x)][at] != -1){
        return mem[spl][toint(x)][at];
    }
    mem[spl][toint(x)][at] = dp(spl, mul(x, ch(at)), at+1);
        //mem[spl][toint(mul(x, ch(at)))][at+1];

    if(spl == 2 && mul(x, ch(at)) == 2){
        mem[spl][toint(x)][at] = mem[spl][toint(x)][at] || dp(spl-1, 1, at + 1);
    } else if(spl == 1 && mul(x, ch(at)) == 3){
        mem[spl][toint(x)][at] = mem[spl][toint(x)][at] || dp(spl-1, 1, at + 1);
    }

    //printf("dp: %d %d %d = %d\n", at, spl, x, mem[spl][toint(x)][at]);
    return mem[spl][toint(x)][at];
}


int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t){
        cin >> L >> X;
        cin >> st;
        LX = L*X;

        memset(mem, -1, sizeof mem);
        if(dp(2, 1, 0)){
            printf("Case #%d: YES\n", t + 1);
        } else {
            printf("Case #%d: NO\n", t + 1);
        }
        //cout << dp(2, 1, 0) << endl;
    }
    return 0;
}

