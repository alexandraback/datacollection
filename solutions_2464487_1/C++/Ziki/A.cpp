/*==================================================*\
 |Author: ziki
 |Created Time: 2013/4/27 9:17:34
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

bool ok(int64 a, int64 R, int64 T) {
    double res = 0;
    double da = a, dr = R, dt = T;
    res = da + (da-1)*da*2+ 2*dr*da;
    //cout<<a<<' '<<res<<endl;
    if(res/T>1.5) return false;
    else {
        if(a+(a-1)*a*2+2*R*a<=T) return true;
        else return false;
    }
}
int main() {
    int T;
    cin>>T;
    rep(cas,T) {
        int64 R,T;
        cin>>R>>T;
        int64 r = (sqrt(T)+1)*2, l = 1;
        while(l<=r) {
            int64 mid = (l+r)/2;
            if(ok(mid,R,T)) l = mid+1;
            else r = mid-1;
        }
        printf("Case #%d: %lld\n",cas+1,r);
    }
	return 0;
}

