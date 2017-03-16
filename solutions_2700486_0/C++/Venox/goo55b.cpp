#include <iostream>
#include <queue>
#include <string>
#include <iomanip> 
#include <vector>
#include <list>
#include <utility> 
#include <iterator> 
#include <math.h> 
#include <algorithm> 
#include <stdio.h> 
using namespace std;
#define REP(i,T) for(int i=0;i<T;++i)
#define MP make_pair
#define PII pair<int,int>
#define BG begin
#define ND end
#define VI vector<int>
#define VB vector<bool>
#define ALL(i) i.BG(),i.ND()
#define FORI(i,a,b) for(int i=a;i<b;++i)
#define OUT(i) while(!i.empty())
#define GP(a,b) a[b.first][b.second]
#define EX(a,b) (a.find(b)!=a.end())
double ccc(__int64 n,__int64 k){
	double ans=1;
	for(__int64 i=0;i<k;++i){
		ans*=(n-i);
		ans/=(i+1);
	}
	return ans;
}
double judge(){
	__int64 n,x,y;
	scanf("%I64d%I64d%I64d",&n,&x,&y);
	if(x==0&&y==0&&n>=1)return 1.0;
	else if(n==0||(x+y)%2!=0)return 0.0;
	__int64 shell;
	if(x==0){
		__int64 m=(y/2+1);
		return (n>=2*m*m-m)?1.0:0.0;
	}
	if(x>0){
		shell=(x+y)/2;

	}
	else{
		shell=(y-x)/2;
	}
	__int64 no=y+1;
	if(n<=2*shell*shell-shell){
		return 0.0;
	}
	if(n>=2*shell*shell-shell+2*shell+no)return 1.0;
	__int64 t=n-2*shell*shell+shell;
	if(t<no)return 0.0;
	if(t<=2*shell){
		double x=0;
		for(__int64 i=no;i<=t;++i){
			x+=ccc(t,i);
		}
		x/=1<<t;
		return x;
	}
	else{
		t=4*shell-t;
		no=2*shell+1-no;
		double x=0;
		for(__int64 i=no;i<=t;++i){
			x+=ccc(t,i);
		}
		x/=1<<t;
		return 1.0-x;
	}

}


int main(){
	__int64 t;
	scanf("%I64d",&t);
	REP(tt,t){
		double ans=judge();
		printf("Case #%d: %lf\n",tt+1,ans);
	}

	return 1;



}