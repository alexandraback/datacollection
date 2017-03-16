#include<iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<sstream>
#include<algorithm>
#include<map>
#include<complex>
#include<ctime>
#include<set>
using namespace std;


#define li			long long int
#define rep(i,to)	for(li i=0;i<((li)(to));i++)
#define repp(i,start,to)	for(li i=(li)(start);i<((li)(to));i++)
#define pb			push_back
#define sz(v)		((li)(v).size())
#define bgn(v)		((v).begin())
#define eend(v)		((v).end())
#define allof(v)	(v).begin(), (v).end()
#define dodp(v,n)		memset(v,(li)n,sizeof(v))
#define bit(n)		(1ll<<(li)(n))
#define mp(a,b)		make_pair(a,b)
#define rin	rep(i,n)
#define EPS 1e-10
#define ETOL 1e-8
#define MOD 100000000
#define F first
#define S second
#define p2(a,b)		cout<<a<<"\t"<<b<<endl
#define p3(a,b,c)		cout<<a<<"\t"<<b<<"\t"<<c<<endl

li gcd(li a, li b){
	if(a<b)swap(a,b);
	if(a%b==0)return b;
	else return gcd(b,a%b);
}

void yakubun(li &a, li &b){
	li ab=gcd(a,b);
	a/=ab;
	b/=ab;
}

li keta(li x){
	rep(i,41){
		if(x==(1ll<<i))return i;
	}
	return -1;
}

li max_keta(li x){
	for(li i=40; i>=0; i--){
		if((bit(i)&x)>0)return i;
	}
}

li solve(li a, li b){
	yakubun(a,b);
	li keta_b=keta(b);
	if(keta_b<0)return -1;
	li keta_a=max_keta(a);
	return max(keta_b-keta_a,1ll);
}

int main(){
	li cases;
	cin>>cases;
	repp(caseNum,1,cases+1){
		li a,b;
		scanf(" %I64d/%I64d", &a, &b);
		li res=solve(a,b);
		cout<<"Case #"<<caseNum<<": ";
		if(res>=0)cout<<res<<endl;
		else cout<<"impossible"<<endl;
	}

	return 0;
}