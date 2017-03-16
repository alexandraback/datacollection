#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<memory.h>
#include<algorithm>
#include<string>
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt((x)*1.)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define getar(m,n) for(int _=0;_<n;++_) cin>>(m)[_];
#define fill(m,v) memset(m,v,sizeof(m))
#define flush {cout.flush();fflush(stdout);}
#define random(x) (((rand()<<15)+rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 stupid_cmath_make_me_cry
#define tm stupid_ctime
#define long long long
#include<map>
#include<set>
#define foreach(c,i) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
using namespace std;

int n,m;
int i,j,k,l;
bool c[999][30][2];
bool u[111];
int t[111], s, p;

int main(){
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	
	for(i=0;i<=10;++i)
	for(j=i;j<=10;++j)
	for(k=j;k<=10;++k){
		if(k-i<2) for(l=0;l<=k;++l) c[i+j+k][l][0] = true;
		if(k-i==2) for(l=0;l<=k;++l) c[i+j+k][l][1] = true;
	}
	
	
	
	int tn,ti;
	scanf("%d\n",&tn);
	for(ti=1;ti<=tn;++ti){
		fill(u,0);
		
		cin>>n>>s>>p;
		getar(t,n);
		
		int res = 0;
		for(i=0;i<n && s;++i) if(c[t[i]][p][1] && !c[t[i]][p][0]){ ++res; --s; u[i]=true; }
		for(i=0;i<n;++i) if(c[t[i]][p][0]){ ++res; }
		
		
		
		
		cout<<"Case #"<<ti<<": "<<res<<endl;
		
		
	}
	
	return 0;
}
