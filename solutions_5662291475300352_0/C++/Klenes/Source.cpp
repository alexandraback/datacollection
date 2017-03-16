#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<cmath>

using namespace std;


int main(){
	int T;
	cin >> T;
	long long int n;
	for (int ti = 1; ti <= T; ti++){
		int res;
		double mySpeed, myDeg;
		double deg1, deg2;
		double speed1, speed2;
		int num;
		cin >> n;
	    cin >> deg1 >> num >> speed1;
		if (n == 1)
		{
			deg2 = deg1;
			speed2 = speed1 + 1;
		}
		else
			cin >> deg2 >> num >> speed2;
		myDeg = min(deg1-1, deg2-1);
		speed1 = 1 / speed1;
		speed2 = 1 / speed2;
		if (myDeg == deg1 - 1)
			mySpeed = speed1;
		else
			mySpeed = speed2;
		res = 0;
		// ak ideme za rychlejsim
		if (mySpeed == max(speed1, speed2))
		{
			if (speed1 > speed2){
				//zistime ci ho dobehneme
				double t_dob = (deg2 - deg1) / (speed2 - speed1);
				if (t_dob < (360 - deg1) / speed1)
				{
					// ak ho dobehneme tak pojdeme na nim
					myDeg = deg1 + t_dob*speed1 - 1;
					deg1 += t_dob*speed1;
					deg2 += t_dob*speed2;
					mySpeed = speed2;
				}
			}
			if (speed1 < speed2){
				//zistime ci ho dobehneme
				double t_dob = (deg1 - deg2) / (speed1 - speed2);
				if (t_dob < (360 - deg2) / speed2)
				{
					// ak ho dobehneme tak pojdeme na nim
					myDeg = deg2 + t_dob*speed2 - 1;
					deg1 += t_dob*speed1;
					deg2 += t_dob*speed2;
					mySpeed = speed1;
				}
			}

		}
		// ideme uz za pomalsim
		// overime ci nas dobehne rychlejsi
		if (speed2 > speed1){
			int t_dob = (360 - deg2 + deg1) / (speed2 - speed1);
			if (t_dob < (360 - deg1) / speed1)
				res = 1;
		}
		if (speed2 < speed1){
			int t_dob = (360 - deg1 + deg2) / (speed1 - speed2);
			if (t_dob < (360 - deg2) / speed2)
				res = 1;
		}

		printf("Case #%d: %d\n", ti, res);
	}
}