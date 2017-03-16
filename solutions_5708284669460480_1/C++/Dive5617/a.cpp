#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB              push_back
#define SIZE(x)         (int)x.size()
#define clr(x,y)        memset(x,y,sizeof(x))
#define MP(x,y)         make_pair(x,y)
#define RS(n)           scanf ("%s", n)
#define ALL(t)          (t).begin(),(t).end()
#define FOR(i,n,m)      for (int i = n; i <= m; i ++)
#define ROF(i,n,m)      for (int i = n; i >= m; i --)
#define IT              iterator
#define FF              first
#define SS              second

typedef long long               ll;
typedef unsigned int            uint;
typedef unsigned long long      ull;
typedef vector<int>             vint;
typedef vector<string>          vstring;
typedef pair<int, int>          PII;

void RI (int& x){
    x = 0;
    char c = getchar ();
    while (!(c>='0' && c<='9' || c=='-'))     c = getchar ();
    bool flag = 1;
    if (c == '-'){
        flag = 0;
        c = getchar ();
    }
    while (c >= '0' && c <= '9'){
        x = x * 10 + c - '0';
        c = getchar ();
    }
    if (!flag)      x = -x;
}
void RII (int& x, int& y){RI (x), RI (y);}
void RIII (int& x, int& y, int& z){RI (x), RI (y), RI (z);}
void RC (char& c){
    c = getchar ();
    while (c == ' '||c == '\n')     c = getchar ();
}
char RC (){
    char c = getchar ();
    while (c == ' '||c == '\n')     c = getchar ();
    return c;
}

/**************************************END define***************************************/

const ll mod = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;

ll gcd (ll a, ll b){
    return b == 0 ? a : gcd (b, a%b);
}

ll a[1005];

int main (){
    int T;
    RI (T);
    while (T --){
        FOR (i, 1, 1000){
            a[i] = 1;
        }
        vector<pair<PII, int> > vec;
        int n, q;
        RII (n, q);
        FOR (i, 1, q){
            int x, b, c;
            RIII (x, b, c);
            vec.PB (MP (MP (x, b), c));
            FOR (j, x, b){
                a[j] = a[j]*c / gcd (a[j], c);
            }
        }
        bool flag = true;
        FOR (i, 1, q){
            int x = vec[i-1].FF.FF, b = vec[i-1].FF.SS, c = vec[i-1].SS;
            int tgg = a[x];
            FOR (j, x+1, b){
                tgg = gcd (tgg, a[j]);
            }
            if (tgg != c){
                flag = false;
                break;
            }
        }
        FOR (i, 1, n){
            if (a[i] > 1e9){
                flag = false;
            }
        }

        if (flag){
            printf ("%d", (int)a[1]);
            FOR (i, 2, n){
                printf (" %d", (int)a[i]);
            }
            puts ("");
        }else{
            puts ("Stupid BrotherK!");
        }
    }
}