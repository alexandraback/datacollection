#include<cstdio>
#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;
int x[64],s,n;
double handle(int i){
	double l=0,r=1,m,o,t;
	for(int tm=0;tm<80;++tm){
		m=(l+r)*0.5;
		o= m*s+x[i];
		t=0;
		for(int j=0;j<n;++j)if(j!=i)
			t+=max(0.0,o-x[j]);
		if(t+m*s>s) r=m;
			else l=m;
	}
	return l*100;
}
void solve(){
	scanf("%d",&n);
	for(int i=s=0;i<n;++i){scanf("%d",x+i);s+=x[i];}
	for(int i=0;i<n;++i)printf(" %.9lf",handle(i));
}
int main(){
	int T,ti;
	for(scanf("%d",&T),ti=1;ti<=T;++ti){
		printf("Case #%d:",ti);
		solve();
		puts("");
	}
}