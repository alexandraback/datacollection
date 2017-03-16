#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

typedef     long long       LL;
typedef     pair<int, int>  pii;
typedef     pair<LL, LL>    pll;
typedef     pair<pii,pii>   ppi;
typedef     vector<int>     vi;
typedef     vector<vi>      vvi;
typedef     vector<LL>      vl;
typedef     vector<vl>      vvl;
typedef     vector<string>  vs;
typedef     vector<pii>     vii;

double      EPS = 1e-9;
int         INF = 2000000000;
long long   INFF = 8000000000000000000LL;
double      PI = acos(-1);
int         dx[8] = {-1,0,0,1,-1,-1,1,1};
int         dy[8] = {0,1,-1,0,-1,1,-1,1};

#define     fi      first
#define     se      second
#define     mp      make_pair
#define     pb      push_back
#define     SIZE(v)         (int)v.size()
#define     ALL(v)          v.begin(),v.end()
#define     ALLA(arr,sz)    arr,arr+sz
#define     SORT(v)         sort(ALL(v))
#define     SORTA(arr,sz)   sort(ALLA(arr,sz))
#define     SQR(x)          ((x) * (x))
#define     FOR(i,s,e)      for(int (i) = (s); (i) <  (e); ++(i))
#define     FORE(i,s,e)     for(int (i) = (s); (i) <= (e); ++(i))
#define     FORD(i,e,s)     for(int (i) = (e); (i) >= (s); --(i))
#define     REP(i,n)        FOR(i,0,n)
#define     REPE(i,n)       FORE(i,1,n)
#define     REPD(i,n)       FORD(i,n,1)


inline string IntToString(int a){
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int StringToInt(string a){
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}
//===End of template===

int solve(int R, int C, int W){
    if (W == C) return R*C;
    if (W == 1) return R*C;
    if (C%W == 0) return R*(C/W + W-1);

    int ans = R* (C/W + W);

    return ans;
}


int main()
{
    int T,t=0;
    int R,C,W;
    cin >>T;
    while(t<T){
        t++;
        cin >>R>>C>>W;

        cout <<"Case #"<<t<<": "<<solve(R,C,W)<<endl;
    }

    return 0;
}
