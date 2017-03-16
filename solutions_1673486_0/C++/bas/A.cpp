#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main(){
	int C, A, B;
	vector<double> p = vector<double>(100001);
	vector<double> Pp = vector<double>(100001);
	
	cin>>C; 
	cout.precision(8);
	for(int j=0; j<C; j++){
		cin>>A>>B;
		for(int i=1; i<=A; i++)cin>>p[i];
		Pp[1] = p[1];

		for(int i=2; i<=A; i++)Pp[i]=Pp[i-1]*p[i];
		double res=1000000000;
		for(int i=0; i<=A; i++){
			double tmp = Pp[A-i]*(B-A+i+1)+(1.0 - Pp[A-i])*(2*B-A+i+2)+i;
			if(tmp<res)res=tmp;
		}
		res=min(res, (double)B+2);

		cout<<"Case #"<<j+1<<": " <<res<<"\n";
	}
	
}
