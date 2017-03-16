#include <iostream>
#include <string>
using namespace std;

double c, f, x;

double min_sec(){
	double rate = 2;
	double ans = x/rate;
	double current_time = 0;
	while(true){
		//cout << "_> " << current_time << '\t' << ans << endl;
		double new_ans = current_time;
		current_time += c/rate;
		new_ans += c/rate; // buy new
		rate += f;
		new_ans += x/rate; // pay all
		if(ans < new_ans - 0.0000000001){
			break;
			//if(ans < current_time) break;
		}
		else ans = new_ans;
	}
	return ans;
}

void main(){
	//*
	freopen("bb.in", "r", stdin);
	freopen("bb.out", "w", stdout);
	//*/
	
	cout.setf(ios::fixed);
	cout.precision(8);
	
	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++){
		cin >> c >> f >> x;
		cout << "Case #" << tc << ": " << min_sec();
		cout << endl;	
	}
}