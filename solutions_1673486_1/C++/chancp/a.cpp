
//Problem A. 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <cmath>

using namespace std;

int n,a,b;
double p[100000];
double pc[100001];
double pw[100001];
double pcw[100001];


double compute(){
	int i,j,k;
	double res=2+b;
	double t1,t2;
	pw[0]=1-p[0];
	pc[0]=p[0];
	pcw[0]=pw[0];
	for (i=1;i<a;i++){
		pc[i]=pc[i-1]*p[i];
		pw[i]=pc[i-1]*(1-p[i]);
		pcw[i]=pcw[i-1]+pw[i];
	}
	pc[a]=pc[a-1];
	pw[a]=pc[a-1];
	//pcw[a]=

	//cout<<endl;
	//for (i=0;i<a;i++) cout<<"pw:"<<i<<" "<<pw[i]<<endl;
	//cout<<res<<endl;
	for (i=0;i<a;i++){ //# of backspace
		//cout<<"bs"<<i<<":";
		t1=0;
		t2=0;
		for (j=0;j<a-i;j++){
			t2+= pw[j]*(i+2+b-a+i+b);
			//cout<<" "<<t2;
		}
		t2+= pc[a-i-1]*(i+1+b-a+i);
		if (t2<res) res=t2;
		//cout<<endl;
		//cout<<i<<" "<<t2<<" "<<res<<endl;
	}
	return res;
}

int main(){
	int t;
	int i,j,k;
	
	cin>>t;
	for (i=0;i<t;i++){
		cin>>a>>b;
		for (j=0;j<a;j++) cin>>p[j];

			
		//compute();
		cout<<"Case #"<<(i+1)<<": ";
		//for (j=0;j<n;j++) cout<<rpi[j]<<endl;
		//cout<<compute();
		printf("%.7f",compute());
		cout<<endl;
		//for (j=0;j<n;j++) printf("%f %f %f %.10f\n",wp[j],owp[j],oowp[j],rpi[j]);
	}
}
