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

int a[1111], b[1111];
bool s1[1111];
bool s2[1111];

void f2(){
	int inf = 1e9;
	
	fill(s1,0);
	fill(s2,0);
	int st = 0;
	int res = 0;
	
	
	k = n;
	for(;;){
		if(!k) break;
		for(;;){
			for(i=0;i<n;++i) if(!s2[i] && st>=b[i]){
				s2[i] = true; 
				--k;
				if(s1[i]) ++st; else st+=2;
				++res;//cout<<"earn 2s "<<i<<' '<<st<<endl;
				break;
			}
			
			if(i==n) break;
		}
		
		if(!k) break;
		
		for(i=0;i<n;++i) if(!s2[i] && !s1[i] && st>=a[i]){
			s1[i] = true;
			++st; //cout<<"earn 1s "<<i<<' '<<st<<endl;
			++res;
			break;
		}
		
		if(i==n){
			cout<<"Too Bad";
			return;
		}
	}
	
	cout<<res;
}

void f(){
	int inf = 1e9;
	
	
	fill(s1,0);
	fill(s2,0);
	int st = 0;
	int res = 0;
	
	
	k = n;
	for(;;){
		if(!k) break;
		for(;;){
			for(i=0;i<n;++i) if(!s2[i] && st>=b[i]){
				s2[i] = true; 
				--k;
				if(s1[i]) ++st; else st+=2;
				++res;//cout<<"earn 2s "<<i<<' '<<st<<endl;
				break;
			}
			
			if(i==n) break;
		}
		
		if(!k) break;
		
		j = -1;
		for(i=0;i<n;++i) if(!s2[i] && !s1[i] && st>=a[i]){
			if(j<0 || b[j]<b[i]) j=i;
		}
		
		if(j<0){
			cout<<"Too Bad";
			return;
		}
		
		s1[j] = true;
		++st;// cout<<"earn 1s "<<i<<' '<<st<<endl;
		++res;
	}
	
	cout<<res;
}


int main(){
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	int tn,ti;
	scanf("%d",&tn);
	for(ti=1;ti<=tn;++ti){
		
		cin>>n;
		for(i=0;i<n;++i) cin>>a[i]>>b[i];
		cout<<"Case #"<<ti<<": ";
		f();
		cout<<endl;
		
	}
	
	return 0;
}


