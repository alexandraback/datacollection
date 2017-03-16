#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#define abs(x) ((x)<0?-(x):(x))
#define _max(x,y) ((x)<(y)?(y):(x))
#define _min(x,y) ((x)<(y)?(x):(y))
#define sqr(x) ((x)*(x))
#define getar(m,n) for(int _=0;_<n;++_) cin>>(m)[_];
#define forc(it,c) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define fill(m,v) memset(m,v,sizeof(m))
#define random(x) ((rand()<<15^rand())%(x))
#define y1 stupid_cmath
#define y0 stupid_cmath_make_me_cry
#define tm stupid_ctime
typedef long long ll;
using namespace std;

int n,m;
int i,j,k,l;


bool ispal(ll x){
	ll y=0, t=x;
	while(t) y=y*10+t%10, t/=10;
	return x==y;
}

int main(){
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	int tn,ti;
	scanf("%d",&tn);
	for(ti=1;ti<=tn;++ti){
		ll a, b;
		cin>>a>>b;
		ll res=0;
		for(ll j=sqrt(a);j*j<=b;++j) if(j*j>=a){
			ll i=j*j;
			if(ispal(j) && ispal(i)) ++res;//;, cout<<j<<' '<<i<<endl;
		}
		cout<<"Case #"<<ti<<": "<<(res)<<endl;
	}
		
	
	
	return 0;
}
