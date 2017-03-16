#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define fin cin
#define fout cout
//ifstream fin("B.in");
//ofstream fout("B.out");

int main()
{
	int nCase;
	fin >> nCase;
	for(int i = 0; i < nCase; ++ i){
		double c, f, x, ans;
		fin >> c >> f >>x;
		if(x <= c){
			ans = x/2;
		}
		else{
			double n = floor((f*(x-c) -2*c)/f/c), s = 2;
			ans = 0; 
			for(int i = 0; i <= n; ++ i){
				ans += c/s;
				s += f;
			}
			ans += x/s;
		}
		fout.precision(7);
		fout<<"Case #"<<i+1<<": "<<std::fixed<<ans<<endl;
	}
	return 0;
}