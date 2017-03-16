/*==================================================*\
 |Author: ziki
 |Created Time: 2013/4/13 9:39:48
 |File Name: A.cpp
 |Description: 
\*==================================================*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;
using namespace rel_ops;

typedef long long int64;
typedef unsigned long long uint64;
const double pi=acos(-1.0);
const double eps=1e-11;
const int inf=0x7FFFFFFF;
template<class T> inline bool checkmin(T &a,T b){return b<a?a=b,1:0;}
template<class T> inline bool checkmax(T &a,T b){return b>a?a=b,1:0;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define mem(a,b) memset(a, b, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define rep(i,n) for(int i=0; i<n; i++)
#define repit(i,v) for(typeof(v.begin()) i=v.begin(); i!=v.end(); i++)
#define iter(v) typeof(v.begin())
#define ff first
#define ss second
#define out(x) (cout<<#x<<": "<<x<<endl)
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}

char s[5][5];
bool win(char ch) {
    int j;
    rep(i,4) {
        for(j=0; j<4; j++) if(s[i][j]!=ch && s[i][j]!='T') break;
        if(j==4) return true;
        for(j=0; j<4; j++) if(s[j][i]!=ch && s[j][i]!='T') break;
        if(j==4) return true;
    }
    for(j=0; j<4; j++) if(s[j][j]!=ch && s[j][j]!='T') break;
    if(j==4) return true;
    for(j=0; j<4; j++) if(s[3-j][j]!=ch && s[3-j][j]!='T') break;
    if(j==4) return true;
    return false;
}
int C() {
    int r=0;
    rep(i,4) rep(j,4) r+=s[i][j]=='.';
    return r;
}
int main() {
    int T;
    cin>>T;
    rep(cas,T) {
        rep(i,4) scanf("%s",s[i]);
        printf("Case #%d: ",cas+1);
        if(win('X')) puts("X won");
        else if(win('O')) puts("O won");
        else if(C()==0) puts("Draw");
        else puts("Game has not completed");
    }
    return 0;
}

