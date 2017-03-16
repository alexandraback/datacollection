#include<iostream>
#include<math.h>
#include <iomanip> 

using namespace std;

double numberOfFarms( double farmCost, double farmProd, double goal );
double totalTime( double nFarms, double farmCost, double farmProd, double goal ); 

int main() {

	int nInputs;
	cin >> nInputs;

	double farmProd;
	double farmCost;
	double goal;

	for (int i=0; i < nInputs; i++) {
		cin >> farmCost >> farmProd >> goal;

		double nFarms = numberOfFarms( farmCost, farmProd, goal );
		double time = totalTime( nFarms, farmCost, farmProd, goal );

		cout << "Case #"  << i + 1 << ": "  << setprecision(7) << fixed << time <<"\n";
	}
}

double numberOfFarms( double farmCost, double farmProd, double goal ) {

	double k = 1.0 * goal/farmCost - 2.0/farmProd - 1;	
	if (k < 0) k = 0;

	return ceil(k);
};


double totalTime( double nFarms, double farmCost, double farmProd, double goal ) {

	double total =  goal/(2.0 + 1.0*nFarms*farmProd);
	for (int i = 0; i < nFarms; i++) {
		double dt = farmCost / (2.0 + 1.0*i*farmProd);
		total += dt;
	}
	return total;
};
