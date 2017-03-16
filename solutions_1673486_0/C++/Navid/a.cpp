#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		int a,b;
		cin>>a>>b;
		long double ans = b+2;
		long double cor = 0;
		for(int i=0;i<a;i++) {
			double p;
			cin>>p;
			cor+=log(p);
			ans = min(ans,a-(i+1)+(b-(i+1))+1+(1-exp(cor))*(b+1));
		}
		cout<<"Case #"<<tn+1<<": "<<fixed<<setprecision(6)<<ans<<endl;
	}
}

