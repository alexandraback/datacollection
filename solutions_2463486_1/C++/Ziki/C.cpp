/*==================================================*\
 |Author: ziki
 |Created Time: 2013/4/13 10:26:44
 |File Name: C.cpp
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

bool pd(int64 a) {
    static int tmp[30];
    int l = 0;
    while(a) {
        tmp[l++] = a%10; a/=10;
    }
    rep(i,l/2) if(tmp[i] != tmp[l-1-i]) return false;
    return true;
}
int64 ans[100005], q[10005];
int sz;
int main() {
    for(int64 i=1; i<=10000000; i++) if(pd(i) && pd(i*i)) {
        q[sz] = i;
        ans[sz++] = i*i;
    }
    //rep(i,sz)  cout<<q[i]<<'\t'<<ans[i]<<endl;
    //out(sz);
    int T;
    cin>>T;
    rep(cas,T) {
        int64 l,r;
        cin>>l>>r;
        int an = 0;
        rep(i,sz) if(ans[i]>=l && ans[i]<=r) an++;
        printf("Case #%d: %d\n",cas+1,an);
    }
	return 0;
}

