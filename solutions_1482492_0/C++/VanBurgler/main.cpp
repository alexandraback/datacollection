#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

struct P
{
	double t, x;
};

int main()
{
	cout.setf(ios::fixed);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ":" << endl;

		double D;
		int N, A;
		cin >> D >> N >> A;

		vector<P> otherCar;
		vector<double> accels;

		for (int n = 0; n < N; n++)
		{
			double t, x;
			cin >> t >> x;
			otherCar.push_back({t, x});
		}

		for (int a = 0; a < A; a++)
		{
			double a;
			cin >> a;
			accels.push_back(a);
		}

		//cout << D << " " << N << " " << A << endl;

		// Check otherCar cross time
		double crossTime = 0;

		P last = otherCar.back();
		for (int i = N - 2; i >= 0; i--)
		{
			P cur = otherCar[i];

			if (cur.x < D)
			{
				double dist = D - cur.x;
				double ratio = dist / (last.x - cur.x);
				crossTime = cur.t + (last.t - cur.t) * ratio;
				break;
			}

			last = otherCar[i];
		}

		//cout << "Cross Time: " << setprecision(7) << crossTime << endl;

		for (int a = 0; a < A; a++)
		{
			double acceleration = accels[a];
			double fullSpeedTime = sqrt(D / (0.5 * acceleration));

			//cout << "At: " << setprecision(7) << acceleration << " takes " << fullSpeedTime << endl;

			if (fullSpeedTime > crossTime)
				cout << setprecision(7) << fullSpeedTime << endl;
			else
				cout << setprecision(7) << crossTime << endl;
		}
	}
}
