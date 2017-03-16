#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

int main(){
	int T;
	int a,b;
//	float* p=new float [200000];
//	float* c=new float [200000];
//	float x;
	long double* p=new long double [200000];
	long double* c=new long double [200000];
	long double x;
	long double min;
	int count=0;
	cin>>T;
	while(T--){
		++count;
		cin>>a>>b;
		x=1;
		min=2+b;
		for(int i=0;i<a;++i){
			cin>>p[i];
			x*=p[i];
//			c[i]=x*( a-1+b-i*2 )+(1-x)*(a-1+b-i*2+b+1)
			c[i]=a-1+b-i*2+(1-x)*(b+1);
			if(c[i]<min)
				min=c[i];
//			printf("%.6f\n",c[i]);
//			cout<<setprecision(6)<<fixed;
//			cout<<c[i]<<"\n";
		}
		cout<<"Case #"<<count<<": ";
		cout<<setprecision(6)<<fixed<<min<<"\n";
		

//		printf("%.6f",1.0);

	}
	return 0;
}
