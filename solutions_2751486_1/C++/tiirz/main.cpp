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
#define rep(i,n) for(int i=0;i<n;++i)
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


bool iscon(char c){
    if(c=='a' || c=='o' || c=='e' || c=='u' || c=='i') return 0;
    return 1;
}

int main(){
#ifdef SSU
    freopen("aa3.in", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
    int T=in();
    for(int t=0;t<T;++t){
        string s;
        cin>>s;
        vector<int> v(s.size(),0);
        int n=in();
        for(int i=0;i<s.size();++i){
            if(iscon(s[i])) v[i]=1;
        }
        vector<int> d(s.size(),0);
        d[0]=v[0];
        for(int i=1;i<s.size();++i){
            if(v[i]){
                d[i]=d[i-1]+1;
            }
        }
        for(int i=0;i<d.size();++i){
            if(d[i]<n) d[i]=0;
            else{
                d[i]=0;
                d[i-n+1]=1;
            }
        }
        vector<int> a;
        for(int i=0;i<d.size();++i){
            if(d[i]) a.pb(i);
        }
        ll ans=0;
        for(int i=0;i<s.size();++i){
            vector<int>::iterator to=lower_bound(a.begin(), a.end(), i);
            if(to!=a.end())
            ans+=s.size()-(*to+n-1);
        }
        printf("Case #%d: %lld\n", t+1, ans);


    }




    return 0;
}
