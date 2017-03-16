#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main () {
	
	ifstream in ("B-large.in");
	ofstream cout("large.out");
	cout.setf( std::ios::fixed, std:: ios::floatfield );
	cout.precision(7);
	int T;
	in>>T;
	
	for (int t=0; t<T; t++) {
		const double rate=2.0d;
		int farms = 1;

		double C, F, X;
		in>>C>>F>>X;
		
		double t_elapsed1 = 0.0d;
		double t_to_target1 = X/rate;
		double t_elapsed2 = C/rate;
		double t_to_target2 = t_elapsed2 + X/(rate + F * farms);
		
		while (t_to_target2 <  t_to_target1) {
			t_elapsed1 = t_elapsed2;
			t_to_target1 = t_to_target2;
			
			t_elapsed2 += C/(rate+F*farms);
			farms++;
			t_to_target2 = t_elapsed2 + X/(rate+F*farms);
		}
		
		cout<<"Case #"<<t+1<<": "<<t_to_target1<<"\n";
	}
	
	return 0;
}
