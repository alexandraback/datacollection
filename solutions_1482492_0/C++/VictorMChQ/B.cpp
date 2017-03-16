#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <cctype>
#include <sstream>
#include <cmath>
#include <cstring>
#include <list>
using namespace std;
#define oo (1<<31-1)
#define INFI (1e31)
#define ll long long
#define ull unsigned long long
#define PB(x) push_back(x)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,l) for(int i=0;i<l;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
void solve();
double t[2001],x[2001];
double a[251];
double ans[251];
int main(){
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		printf("Case #%d:\n",i);
		solve();
	}
return 0;}
void solve(){
	double D;
	int N,A;
	cin>>D>>N>>A;
	for(int i=0;i<N;i++)
		scanf("%lf %lf",t+i,x+i);
	for(int i=0;i<A;i++)
		scanf("%lf",a+i);

	if(x[1]>D+1e-10){
		double v=(x[1]-x[0])/t[1];
		double t0=(D-x[0])/v;
		t[1]=t0;
		x[1]=D;
	}
	
	for(int i=0;i<A;i++){
		if(x[0]>D+1e-10){
			ans[i]=sqrt((2.0*D)/a[i]);
		}
		else{
			if(0.5*a[i]*t[1]*t[1]>=(D-1e-10))
			ans[i]=t[1];
			else
			ans[i]=sqrt((2.0*D)/a[i]);
		}
	}
	for(int i=0;i<A;i++){
		printf("%.7lf\n",ans[i]);
	}
	
}
