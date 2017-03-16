#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
	int T; cin >> T;

	for(int t=0; t<T; t++){
		cout << "Case #" << t+1 << ": ";

		double C,F,X;
		cin >> C >> F >> X;

		double cps = 2.0;
		double base_time = 0.0;
		double min_time = X / cps;

		while(true){
			double time_until_next_farm = C / cps;

			base_time += time_until_next_farm;
			cps += F;
			
			double time = X / cps;

			if(base_time + time > min_time) break;
			min_time = base_time + time;
		}

		cout << fixed << setprecision(7) << min_time << endl;
	}

	return 0;
}
