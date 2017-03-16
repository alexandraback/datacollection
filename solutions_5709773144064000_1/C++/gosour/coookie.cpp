#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int T,c=1;
	cin>>T;
	double C,F,X;
	double total=0, base=2,time = 0;
	double full, buy;
	double ans;

	while(T--){
		cin>>C>>F>>X;
		total = 0;
		base = 2;
		time = 0;

		while(1){
			full = time + X/base;
			buy = time + (C/base) + X/(base+F);
			if (buy >= full){
				ans = full;
				break;
			}
			else{
				time += C/base;
				base += F;
			}
		}
		cout<<fixed;
		cout<<"Case #"<<c++<<": "<<setprecision(7)<<ans<<endl;

	}
}
