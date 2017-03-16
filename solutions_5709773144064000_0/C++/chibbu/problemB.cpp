#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){

	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(7);
	int t;
	cin >> t;

	for(int i=1; i<=t; i++){
		double c, f, x;
		cin>>c>>f>>x;
		double ans = 0.0, curr_rate = 2.0;
		while(true){
			if(x/curr_rate <= c/curr_rate + x/(curr_rate+f)){
				ans += x/curr_rate;
				break;
			}
			ans += c/curr_rate;
			curr_rate += f;
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;

}
