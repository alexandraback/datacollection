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
using namespace std;

int n,m;
int i,j,k,l;



int main(){
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	char d[256];
	fill(d,0);
	
	d['a'] = 'y';
	d['b'] = 'h';
	d['c'] = 'e';
	d['d'] = 's';
	d['e'] = 'o';
	d['f'] = 'c';
	d['g'] = 'v';
	d['h'] = 'x';
	d['i'] = 'd';
	d['j'] = 'u';
	d['k'] = 'i';
	d['l'] = 'g';
	d['m'] = 'l';
	d['n'] = 'b';
	d['o'] = 'k';
	d['p'] = 'r';
	d['q'] = 'z';
	d['r'] = 't';
	d['s'] = 'n';
	d['t'] = 'w';
	d['u'] = 'j';
	d['v'] = 'p';
	d['w'] = 'f';
	d['x'] = 'm';
	d['y'] = 'a';
	d['z'] = 'q';

	char s[1111];
	
	int tn,ti;
	scanf("%d\n",&tn);
	for(ti=1;ti<=tn;++ti){
		
		gets(s);
		for(i=0;s[i];++i) if(s[i]>='a' && s[i]<='z') s[i]=d[s[i]];
		
		cout<<"Case #"<<ti<<": "<<s<<endl;
		
	}
	
	return 0;
}
