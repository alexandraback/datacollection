#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<memory.h>
#include<algorithm>
#include<string>
#include<map>
#include<set>
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
#define foreach(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); i++)
using namespace std;

int n,m;
int i,j,k,l;

set<int> q[2000000];
char s[1111];

void add(int x){
	sprintf(s,"%d",x);
	l = strlen(s);
	int t=1;
	for(k=1;k<l;++k) t*=10;
	
	int y = x;
	for(k=1;k<l;++k){
		y = y/10 + (y%10)*t;
		if(y>x) q[x].insert(y);
	}
}

int main(){
	/*srand(74747);
	freopen("input.txt","w",stdout);
	m = 50;
	for(i=0;i<m;++i) cout<<1<<' '<<2000000<<endl;
	return 0;*/
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	for(i=1;i<=2e6;++i){
		add(i);
	}
	
	int tn,ti;
	scanf("%d\n",&tn);
	for(ti=1;ti<=tn;++ti){
		
		int a,b;
		cin>>a>>b;
		
		long s = 0;
		for(i=a;i<b;++i){
			foreach(q[i],it) if((*it)<=b) ++s; else break;
		}
		
		cout<<"Case #"<<ti<<": "<<s<<endl;
		
	}
	
	return 0;
}
