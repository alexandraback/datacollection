#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <set>

using namespace std;

int main() {
	ofstream fout("cookie.out");
	ifstream fin("cookie.in");

	int t;
	fin >> t;

	for (int caseNo = 1; caseNo <= t; caseNo++){
		double c, f, x,time;
		time = 0;
		fin >> c;//cost of farm
		fin >> f;//farm production
		fin >> x;

		double p = 2;//production per second

		while (true){
			double a = c / p;//time till next farm
			double b = x / p;//time till target

			//cout << a << endl;
			//cout << b << endl;

			//if you bought farm, what is the time to win now?
			p += f;
			double newb = x / p;//new time till target

			if (a + newb <= b){
				//cout << "buying farm to reduce time from " << b << " to " << a + newb << endl;
				time += a;
			}
			else{
				//cout << "END TIME:" << time + b << endl;
				fout.precision(9);
				fout << "Case #" << caseNo << ": " << time + b << endl;
				break;
			}
		}
		cout << endl;
	}
	return 0;
}