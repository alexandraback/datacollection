#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <utility>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <bitset>
#define  pb push_back
#define mp make_pair
#define pii pair< pair<int,int> , pair<int,int> >
#define rep(i,s,n) for(int i=s;i<n;++i)

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int buf_i;
int in(){
    scanf("%d", &buf_i);
    return buf_i;
}
const int INF=~(1<<31);
const ll LINF=~(1LL<<63);

const double eps=1e-6;
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
    freopen("in3.txt","r", stdin);
    freopen("outcj3.txt", "w", stdout);
#else
    //  freopen("g.in","r", stdin);
    // freopen("g.out", "w", stdout);
#endif

    int T=in();
    for(int t=0;t<T;++t){
        printf("Case #%d: ",t+1);
        int a=in(), b=in();
        int k=in();
        int res=0;
        for(int i=0;i<a;++i){
            for(int j=0;j<b;++j){
                if((i&j)<k){
                    ++res;
                   // cout<<i<<' '<<j<<' '<<(i&j)<<endl;
                }
            }
        }
        printf("%d\n",res);

    }











    return 0;
}
