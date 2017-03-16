#include<fstream>
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double c, f, x;

int main(){
	ifstream fin("2.in");
	ofstream fout("2.out");
	int testSum;
	fin >> testSum;
	for (int test = 1; test <= testSum; test++){
		fout << "Case #" << test << ":" << ' ';
		fin >> c >> f >> x;
		double v = 2;
		double tmp = 0;
		double ans = 10000000;
		for (int i = 1; i <= 1000000; i++){
			if (x/v + tmp< ans)
				ans = x/v + tmp;
			tmp = tmp + c/v;
			v = v + f;
		}
		fout << setprecision(10) << ans << endl;
	}

}
