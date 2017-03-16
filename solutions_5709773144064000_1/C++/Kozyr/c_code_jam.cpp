#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int N;
	double C, F, X;

	vector<double> res;

	cin >> N;

	int n;
	for (n=1; n<=N; n++) {

		cin >> C >> F >> X;

		double t, t1, t2, S = 2.0;

		t = 0.0;
		t1 = X/S;
		t2 = C/S + X/(S+F);

		while (t1 > t2) {
			t += C/S;
			S += F;

			t1 = X/S;
			t2 = C/S + X/(S+F);
		}
		t += X/S;
		res.push_back(t);
	}

	vector<double>::iterator iter;
	n=1;

	for(iter=res.begin(); iter!=res.end(); iter++)
	{
		cout << "Case #" << n++ << ": " << fixed << setprecision(7) << (*iter) << endl;
	}

	return 0;
}

