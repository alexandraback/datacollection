#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <limits>
using namespace std;
int main(){
	ifstream fin;
	fin.open("cookie.in", std::ifstream::in);
	ofstream fout;
	fout.open("cookie.out", std::ofstream::out);
	int count;
	double c, f, x;
	vector<double> cost(200000);
	fin>>count;
	for(int i = 0; i <count; i++){
		fin>>c>>f>>x;
		double speed = 2;
		cost[0] = 0;
		double p, q;
		double result;
		double min = x/2;
		for(int j = 1; j < 200000-1; j++){
			cost[j] = c/speed+cost[j-1];
			speed += f;
			p = (x)/((j-1)*f + 2) + cost[j-1];
			q = (x)/(j*f + 2) + cost[j];
			if(q < p)
			{

				result = q;
				if(result < min)
					min = result;
			}
		}
		fout<<"Case #"<<i+1<<": "<<setiosflags(ios::fixed | ios::showpoint)<<std::setprecision(7)<<min<<endl;
		
	}
	fin.close();
	fout.close();
	return 0;
}
