
#include <iostream>
#include <iomanip>

using namespace std;

double gettime(double rate, double fc, double fp, double target)
{
	double time = 0;
	while ((rate + fp) * fc < target * fp)
	{
		time += fc / rate;
		rate += fp;
	}
	return time + target / rate;
}

int main()
{
	int T;
	cin >> T;

	cout << fixed << setprecision(7);
	for (int t = 0; t < T; t++)
	{
		double C, F, X;
		cin >> C >> F >> X;
		double time = gettime(2.0, C, F, X);
		cout << "Case #" << (t+1) << ": " << time << endl;
	}

	return 0;
}
