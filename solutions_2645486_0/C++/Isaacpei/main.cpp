#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

const int INF=0x3f3f3f3f;
typedef long long ll;
const int M=1001;
const int mod=7340033;
const double eps=1e-6;
const double Pi=2*acos(0.0);

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline int bit(int x){return 1<<x;}
inline double dabs(double x){return x>0?x:(-x);}
inline int abs(int x){return x>0?x:(-x);}
inline int lowbit(int x){return x&(-x);}

int cas=1,T;
ll r,t;

int main(){
    //ios::sync_with_stdio(0);
    freopen("A-small-attempt3.in","r",stdin);
    freopen("out.txt","w",stdout);
    for(scanf("%d",&T);cas<=T;cas++){
    	cin>>r>>t;
    	long double tmp=r;
    	cout<<"Case #"<<cas<<": ";
    	cout<<(ll)(((1-2*r)+sqrt((2*tmp-1)*(2*tmp-1)+8*t))/4)<<endl;
    }
    return 0;
}