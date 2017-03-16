#include <iostream>
#include <cmath>
#include <iomanip>

#define FOR(i,n) for(int i = 0, _n = (n); i < _n; i++)


using namespace  std;

int main(){
	int T;
	cin >> T;
	double C, F, X, time;
	int n;
	
	FOR(caseid, T){
		cin>>C>>F>>X;
		int n = ceil(X/C - 1 - 2/F);
		if(n<0) n = 0;
		double time = 0;
		FOR(i, n) time += C/(i*F+2);
		time += X/(n*F+2);
		cout<<"Case #"<<caseid+1<<": "<<setprecision(11)<<time<<endl;
	}
}