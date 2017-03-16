#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream fff;
	fff.open(argv[1]);
	int T;
	fff >> T;
	for (int ttt=0; ttt<T; ttt++) {
		cout << "Case #" << ttt+1 << ": ";
		int A, B;
		fff >> A >> B;
		double* p = new double[A];
		for (int i=0; i<A; i++)   fff >> p[i];
		
		double mins = B+2;
		double pb = 1.0;
		for (int i=0; i<=A; i++) {
			double st = pb*(A-i+B-i+1)+(1-pb)*(A-i+B-i+1+B+1);
			if (st < mins) mins = st;
			//cout << i << " " << st << endl;
			if (i != A) pb *= p[i];
		}
		printf("%.6f\n", mins);
		//cout << setprecision(6) << mins << endl;		
		delete[] p;
		
	}	
	fff.close();
}
