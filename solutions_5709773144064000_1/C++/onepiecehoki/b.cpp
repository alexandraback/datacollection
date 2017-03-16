#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	int T;
	cin >> T;
	for (int t=1;t<=T;++t){
		//Read input
		double C, F, X;
		cin >> C >> F >> X;
		
		//Start simulating
		double prod_rate = 2;
		double cur_time = 0;
		while (true){
			//Compare 2 time: (1)If we make the next farm and (2)If we don't make one
			//If we don't make farm:
			double time1 = cur_time + X/prod_rate;
			
			//If we make a farm:
			double time2 = cur_time + C/prod_rate + X/(prod_rate + F);
			
			
			if (time1 <= time2){
				//We don't make the farm and exit in this case
				cur_time = time1;
				break;
			}
			else{
				//We make 1 farm and continue loop
				cur_time += C/prod_rate;
				prod_rate += F;
				continue;
			}
		
		}
		
		//Output the solution
		cout << fixed << setprecision(7) << "Case #" << t << ": " << cur_time << endl;
	}
	
	return 0;
}