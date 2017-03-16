#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
#include <iomanip>
using namespace std;

double tst()
{
	int A, B;
	cin >> A >> B;

	double lp[100000];
	double sum=0;
	for (int i=0; i<A; i++) {
		double p;
		cin >> p;
		sum += log(p);
		lp[i] = sum;
	}

	double min=B+2;
	double E;
	for (int j=0; j<A; j++) {
		double ps = exp(lp[A-1-j]);
		E = (B-A+1+2*j)+(1.0-ps)*(B+1);
		if (E<min)
			min = E;
	}
	


	return min;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
		cout << "Case #" << i+1 << ": " << fixed << setprecision(6) << tst() << endl;
	}
}



