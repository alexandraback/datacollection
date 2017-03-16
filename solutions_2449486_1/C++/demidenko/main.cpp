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
int a[111][111];
bool u[111][111];

int main(){
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	int tn,ti;
	scanf("%d",&tn);
	for(ti=1;ti<=tn;++ti){
		
		
		cin>>n>>m;
		for(i=0;i<n;++i) getar(a[i],m);
		
		bool ok=1;
		for(k=1;ok&&k<=100;++k){
			fill(u,0);
			for(i=0;i<n;++i){
				for(j=0;j<m;++j) if(a[i][j]!=k) break;
				if(j==m) for(j=0;j<m;++j) u[i][j]=1;
			}
			for(j=0;j<m;++j){
				for(i=0;i<n;++i) if(a[i][j]!=k) break;
				if(i==n) for(i=0;i<n;++i) u[i][j]=1;
			}
			for(i=0;i<n;++i)for(j=0;j<m;++j)if(u[i][j]) a[i][j]=k+1;
			for(i=0;i<n;++i)for(j=0;j<m;++j)if(a[i][j]==k) ok=0;
		}
		cout<<"Case #"<<ti<<": "<<(((ok)?"YES":"NO"))<<endl;
	}
		
	
	
	return 0;
}
