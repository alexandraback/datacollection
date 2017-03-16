//#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

ifstream cin("cin");
ofstream cout("cout");


int T,A,B;
double p[1000000],cum[1000000];

int main(){
	cin>>T;
	for(int k=0;k<T;k++){
		cin>>A>>B;
		for(int i=0;i<A;i++) cin>>p[i];

		//pre-computation
		cum[0]=p[0];
		for(int i=1;i<A;i++) cum[i]=cum[i-1]*p[i];

		double mn=B+2; //restart
		double cont=B-A+1.0+((1-cum[A-1])*(B+1));
		mn=min(mn,cont);

		for(int i=1;i<A;i++){
			double tmp=(2.0*i)+B-A+1.0+((1.0-cum[A-i-1])*(B+1));
			mn=min(mn,tmp);
		}
		
		cout<<"Case #"<<k+1<<": "<<setprecision(15)<<mn<<endl;
	}
	return 0;
}