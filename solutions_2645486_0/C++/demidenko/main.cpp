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
#define y1 stupid_cmath
#define y0 stupid_cmath_make_me_cry
#define tm stupid_ctime
inline int random(int x){ if(RAND_MAX==32767) return (rand()<<15^rand())%x; else return rand()%x; }
typedef long long ll;
using namespace std;

int n,m;
int i,j,k,l;
int v[11111];

ll d[1111][6];

int main(){
	FILE*_fin=freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	int tn,ti;
	cin>>tn;
	for(ti=1; ti<=tn; ++ti){
		int E,R;
		cin>>E>>R>>n;
		getar(v+1,n);
		
		
		ll ans=0;
		
		fill(d,192);
		d[1][E] = 0;
		
		for(i=1;i<=n;++i){
			for(j=0;j<=E;++j){
				for(k=0;k<=j;++k)
				{
					d[i+1][min(j-k+R,E)] = max(d[i+1][min(j-k+R,E)], d[i][j]+k*v[i]);
				}
			}
		}
		
		for(i=0;i<=E;++i) ans=max(ans, d[n+1][i]);
		
		cout<<"Case #"<<ti<<": ";
		cout<<ans<<endl;
	}
	
	return 0;
}
