#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int TT;
	cin>>TT;
	double ans;
	double c,f,x;
	double t;
	double t2;
	double r;
	double t1;
	double et;
	for(int T=1;T<=TT;++T){
		cin>>c>>f>>x;
		t=x/2;	
		t2=0;
		r=2;
		et=0;
		for(int i=0;i<=1000000;++i){
			et+=c/r;
			r+=f;	
			if(et+x/r<t)
				t=et+x/r;
		}
		ans=t;
		printf("Case #%d: %.7f\n",T,ans);
	}
	return 0;
}
