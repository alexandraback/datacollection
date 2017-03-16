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

li n;
li a,b,k;


li solve(){

}

int main(){
	//vector<pair<char,li> >pp=decom("aaabbcddddaa");
	//rep(i,sz(pp))p2(pp[i].F, pp[i].S);
	li cases;
	cin>>cases;
	rep(caseNum,cases){
		cin>>a>>b>>k;
		li res=0;
		rep(i,a){
			rep(j,b)res+=((i&j)<k ? 1 : 0);
		}

		cout<<"Case #"<<caseNum+1<<": ";
		cout<<res<<endl;
	}

	return 0;
}