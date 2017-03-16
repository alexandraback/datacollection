#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>
#include <ctime>
#include <complex>

#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define LL long long
#define co complex<double>

#define MAX 100005
#define AMAX 1500
#define MOD 1000000007

#define f(c,d) ((1<<(c))*(d))

using namespace std;

int t,n,tt;
char x[25],y[25],xx[25],yy[25],xxx[25],yyy[25];
unsigned LL tc,ba,bb,bc;

void go(int a,int b,unsigned LL ta,unsigned LL tb){
	if(a==n){
		if(ta>tb)tc=ta-tb;
		else tc=tb-ta;
		if(tc<bc||(tc==bc&&ta<ba)||(tc==bc&&ta==ba&&tb<bb)){
			ba=ta;
			bb=tb;
			bc=tc;
			F1(c,0,n)xxx[c]=xx[c],yyy[c]=yy[c];
		}
	}else{
		if(x[a]=='?'&&y[a]=='?'){
			if(b==0){
				xx[a]=0;
				yy[a]=9;
				go(a+1,b,ta*10,tb*10+9);
			}else if(b==1){
				xx[a]=9;
				yy[a]=0;
				go(a+1,b,ta*10+9,tb*10);
			}else F1(c,0,10)F1(d,0,10){
				xx[a]=c;
				yy[a]=d;
				if(c>d)go(a+1,0,ta*10+c,tb*10+d);
				else if(c<d)go(a+1,1,ta*10+c,tb*10+d);
				else if(c==0)go(a+1,2,ta*10+c,tb*10+d);
			}
		}else if(x[a]=='?'){
			if(b==0){
				xx[a]=0;
				yy[a]=y[a];
				go(a+1,b,ta*10,tb*10+y[a]);
			}else if(b==1){
				xx[a]=9;
				yy[a]=y[a];
				go(a+1,b,ta*10+9,tb*10+y[a]);
			}else F1(c,0,10){
				xx[a]=c;
				yy[a]=y[a];
				if(c>y[a])go(a+1,0,ta*10+c,tb*10+y[a]);
				else if(c<y[a])go(a+1,1,ta*10+c,tb*10+y[a]);
				else go(a+1,2,ta*10+c,tb*10+y[a]);
			}
		}else if(y[a]=='?'){
			if(b==0){
				xx[a]=x[a];
				yy[a]=9;
				go(a+1,b,ta*10+x[a],tb*10+9);
			}else if(b==1){
				xx[a]=x[a];
				yy[a]=0;
				go(a+1,b,ta*10+x[a],tb*10);
			}else F1(c,0,10){
				xx[a]=x[a];
				yy[a]=c;
				if(c>x[a])go(a+1,1,ta*10+x[a],tb*10+c);
				else if(c<x[a])go(a+1,0,ta*10+x[a],tb*10+c);
				else go(a+1,2,ta*10+x[a],tb*10+c);
			}
		}else{
			xx[a]=x[a];
			yy[a]=y[a];
			if(b!=2||x[a]==y[a])go(a+1,b,ta*10+x[a],tb*10+y[a]);
			else if(x[a]>y[a])go(a+1,0,ta*10+x[a],tb*10+y[a]);
			else go(a+1,1,ta*10+x[a],tb*10+y[a]);
		}
	}
}

int main(){
	scanf("%d",&t);
	F2(a,1,t){
		tt=a;
		n=0;
		bc=ULLONG_MAX;
		scanf("%s%s",x,y);
		while(x[n])n++;
		F1(b,0,n)if(x[b]!='?')x[b]-='0';
		F1(b,0,n)if(y[b]!='?')y[b]-='0';
		go(0,2,0,0);
		printf("Case #%d: ",a);
		F1(b,0,n)printf("%d",xxx[b]);
		printf(" ");
		F1(b,0,n)printf("%d",yyy[b]);
		printf("\n");
		F1(b,0,n)x[b]=y[b]=0;
	}
	//system("pause");
	return 0;
}
