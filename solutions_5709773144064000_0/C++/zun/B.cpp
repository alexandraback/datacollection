#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  ifstream fin("B.in");
	ofstream fout("B.out");
	int t;
	fin>>t;
	for( int p=1; p<=t; p++) {
		double a,b,c;
		fin>>a>>b>>c;
		double time = 0;
		double earnings = 2;
		double ans = 0;
		while(c!=0) {
		  if(c/earnings > c/(earnings+b)+a/earnings) {
			  time += (a/earnings);
				earnings += b;
			}
			else {
				time+=c/earnings;
				break;
			}
		}
		fout<<fixed;
		fout<<setprecision(7)<<"Case #"<<p<<": "<<time<<endl;
	}
}
			  