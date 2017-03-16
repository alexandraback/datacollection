#include <set>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		double C,F,X;
		cin >> C >> F >> X;

		double ans = X/2;
		
		double rate = 2;
		double buytime = 0;
		while(true){
			buytime += C/rate;
			rate += F;
			if(buytime + X/rate<=ans){
				ans = buytime + X/rate;
			} else break;
		}
		cout<<"Case #"<<t+1<<": "<<fixed<<setprecision(7)<<ans<<endl;
	}
}
