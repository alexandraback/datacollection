#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int T;
	cin >> T;
	
	int i, j, k;

	for (i=1;i<=T;i++){
		int X, Y;
		cin >> X >> Y;

		cout <<"Case #"<<i<<": " ;
		int cur_X = 0;
		int cur_Y = 0;
		int next_step = 1;
		while ( cur_X != X || cur_Y != Y){
			if (abs(X-cur_X) < abs(Y-cur_Y)){
				if (abs(Y-cur_Y) >= next_step){
			
				if (Y-cur_Y > 0){
					cout << "N";
					cur_Y += next_step;
					next_step ++;
				}else{
					cout << "S";
					cur_Y -= next_step;
					next_step ++;
				}

				}else{

				if (Y-cur_Y > 0){
					cout << "S";
					cur_Y -= next_step;
					next_step ++;
				}else{
					cout << "N";
					cur_Y += next_step;
					next_step ++;
				}

				}
			}else{
				if (abs(X-cur_X) >= next_step){

				if (X-cur_X > 0){
					cout << "E";
					cur_X += next_step;
					next_step++;
				}else{
					cout << "W";
					cur_X -= next_step;
					next_step++;
				}

				}else{

				if (X-cur_X > 0){
					cout << "W";
					cur_X -= next_step;
					next_step++;
				}else{
					cout << "E";
					cur_X += next_step;
					next_step++;
				}

				}
			}

		}
		cout <<endl;

	}



	return 0;
}
