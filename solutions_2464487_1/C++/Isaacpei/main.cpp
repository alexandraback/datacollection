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
ll R,t;

void get(){
	ll l=1,r=min(t/(2*R-1ll),ll(sqrt(t*1.0)));
	while(l<r){
		ll m=l+(r-l)/2;
		if(2*m*m+m*(2*R-1)>=t) r=m;
		else l=m+1;
	}
	if(2*l*l+l*(2*R-1)>t) l--;
	cout<<l<<endl;
}
int main(){
    //ios::sync_with_stdio(0);
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    for(cin>>T;cas<=T;cas++){
    	cin>>R>>t;
    	cout<<"Case #"<<cas<<": ";
    	get();
    }
    return 0;
}
