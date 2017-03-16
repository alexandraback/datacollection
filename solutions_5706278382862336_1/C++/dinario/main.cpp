#pragma comment(linker, "/STACK:64000000")
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define mp make_pair
#define __int64 long long
#define LL unsigned long long
#define re return
#define N 550000
#define double long double

typedef struct{int len;char c;}tp;
typedef struct{tp p[200];int len;}ts;

LL pow2[100];

LL gcd (LL a, LL b) {
	return b ? gcd (b, a % b) : a;
}

bool check(LL P,LL Q,LL c){
	LL tmp=gcd(Q,P);
	Q/=tmp;
	P/=tmp;
	
	LL pw2=pow2[40];
	tmp=gcd(Q,pw2);
	Q/=tmp;
	pw2/=tmp;

	tmp=gcd(c,P);
	c/=tmp;
	P/=tmp;
	
	tmp=gcd(c,pw2);
	c/=tmp;
	pw2/=tmp;

	if(c*Q>=P*pw2)
		re true;
	re false;
}

bool equals(LL P,LL Q,LL c){
	LL tmp=gcd(Q,P);
	Q/=tmp;
	P/=tmp;
	
	LL pw2=pow2[40];
	tmp=gcd(Q,pw2);
	Q/=tmp;
	pw2/=tmp;

	tmp=gcd(c,P);
	c/=tmp;
	P/=tmp;
	
	tmp=gcd(c,pw2);
	c/=tmp;
	pw2/=tmp;

	if(c*Q==P*pw2)
		re true;
	
	re false;
}

LL doit(LL P,LL Q){
	int i;

	LL ost=pow2[40]/Q;
	if(Q*ost==pow2[40])re ost;
	re -1;
}

void solve(){
	LL i,j,n,k,p,q,h;
	scanf("%lld/%lld",&p,&q);

	LL tmp=gcd(p,q);
	p/=tmp;
	q/=tmp;
	
	/*LL r=pow2[40],l=0,c;
	for(;r-l>1;){
		c=(r+l)/2;
		
		if(check(p,q,c))r=c;
		else l=c;
	}
	LL rs=l,res;
	if(equals(p,q,r))rs=r;
	else if(!equals(p,q,l)){
		cout<<"impossible";re;
	}
	for(i=0;i<=40;++i)if(pow2[i]<=rs)res=i;
	cout<<40-res;
	*/
	LL ost = doit(p,q);
	if(ost==-1){
		cout<<"impossible";re;
	}
	LL rs=ost*p,res;
	for(i=0;i<=40;++i)if(pow2[i]<=rs)res=i;
	cout<<40-res;
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);

	LL T,t,i,j,k;
	
	pow2[0]=1;for(i=1;i<100;++i)pow2[i]=pow2[i-1]*2;

	cin>>T;
	for(t=0;t<T;++t){
		cout<<"Case #"<<t+1<<": ";
		solve();
		cout<<endl;
	}
	return 0;
}