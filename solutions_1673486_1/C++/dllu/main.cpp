#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	ifstream myfile;
	ofstream out;
	myfile.open("input.txt");
	out.open("output.txt");
	int T;
	myfile >> T;
	//cout << T << endl;
	for(int i=0; i<T; i++){
		int A, B;
		long double a1, a2, a3, a4;
		long double ppp = 1.0;
		long double ppp1 = 1.0;
		long double ppp2 = 1.0;
		myfile >> A >> B;
		for(int j=0; j<A; j++){
			long double pp;
			myfile>>setprecision (9)>>pp;
			ppp*=pp;
			if(j<A-1)ppp1*=pp;
			if(j<A-2)ppp2*=pp;
		}
		cout << ppp << ' '<< ppp1 << ' ' << ppp2 << endl;
		a1 = (B+B-A+2)*(1-ppp) + (B-A+1)*ppp;
		a2 = (B+B-A+2+1+1)*(1-ppp1) + (B-A+3)*ppp1;
		a3 = (B+B-A+2+2+2)*(1-ppp2) + (B-A+5)*ppp2;
		a4 = B+2;
		cout << a1 <<' '<< a2<<' ' << a3<<' '<<a4 <<endl;
		long double ans = min(min(a1,a2),min(a3,a4));
		out << fixed;
		out << setprecision (9) << "Case #" << i+1 << ": " << ans << endl;
	}
	return 0;
}