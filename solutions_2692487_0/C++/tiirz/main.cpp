#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <ctime>
#include <map>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <list>
#include <vector>
#include <iomanip>
#include <cctype>
#include <complex>
#include <iterator>
#include <ostream>
#include <bitset>
#define all(a) a.begin(),a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define clx complex<long double>
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;
int _bufint;
inline int in(){
    scanf("%d", &_bufint);
    return _bufint;
}
const ll LINF=~((1ll)<<63);
const int INF=~(1<<31);
ll gcd(ll a, ll b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}


ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}

int main(){
#ifdef SSU
    freopen("a.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T=in();
    for(int t=1;t<=T;++t){
        int cur=in(), n=in();
        multiset<int> s;
        for(int j=0;j<n;++j){
            s.insert(in());
        }
        int res=s.size();
        int cura=0;
        while(!s.empty() && cur>1){
            int c=*s.begin();
            if(c<cur){
                cur+=c;
                s.erase(s.begin());
                continue;
            }
            res=min(res, cura+(int)s.size());
            if(cur!=0){
                cura++;
                cur+=(cur-1);
            }
        }
        if(cur>1)
        res=min(res, cura);
        printf("Case #%d: %d\n",t, res);

    }

    return 0;
}
