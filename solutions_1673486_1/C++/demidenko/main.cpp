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


double p[111111];
double f(){
	int a,b;
	cin>>a>>b;
	
	for(i=0;i<a;++i) cin>>p[i];
	
	double mn = 9e18;
	
	//1
	double pr = 1.;
	for(i=0;i<a;++i) pr*=p[i];
	double e1 = (b-a+1)*pr + (b-a+1+b+1)*(1.-pr);
	
	mn = min(mn, e1);
	
	//2
	double e2;
	pr = 1;
	for(k=0;k<a;++k){
		double e21, e22;
		
		
		e2 = pr*(a-k + b-k + 1) + (1-pr)*(a-k + b-k + 1 + b + 1);
		mn = min(mn, e2);
		
		pr*=p[k];
	}
	
	//3
	
	mn = min(mn, 1+b+1);
	
	
	return mn;
}


int main(){
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	int tn,ti;
	scanf("%d",&tn);
	for(ti=1;ti<=tn;++ti){
		
		
		
		printf("Case #%d: %.6lf\n",ti,f());
		
	}
	
	return 0;
}
