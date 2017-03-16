#include<iostream>
#include<stdio.h>
#include<fstream>
#include <iomanip>
using namespace std;


int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	in.open("A-large.in");
	out.open("out.txt");
	in>>CaseNum;

	int A,B;
	double ans,temp,curans;
	double p;

	for(int Case=0;Case<CaseNum;Case++){

	in>>A>>B;
	ans=A+B+1;
	curans=A+B+1;
	temp=B+1;
	for(int i=0;i<A;i++){
		in>>p;
		curans=curans-2+temp-temp*p;
		temp=temp*p;
		if(curans<ans)
			ans=curans;

	}
	if(ans>B+2)
		ans=B+2;


	out<<"Case #"<<Case+1<<": "<<fixed <<setprecision(6)<<ans<<endl;
	}
	return 0;
}
          