#include <iostream>
#include <iomanip>

using namespace std;
typedef long double f;

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		f C, F, X;
		cin >> C >> F >> X;
		//cout << C << " / " << F << " / " << X << endl;

		double total_time = 0.0;
		double best_time = X / 2.0;
		for (int farm = 0; total_time < best_time; ++farm)
		{
			double X_time = X / (2.0 + farm * F);
			if ((total_time + X_time) < best_time)
				best_time = total_time + X_time;

			double farm_time = C / (2.0 + farm * F);
			//cout << farm << ": " << total_time << " " << X_time << " " << farm_time << " | " << best_time << endl;
			total_time += farm_time;
		}
		cout << "Case #" << case_num << ": " << fixed << setprecision(7) << best_time << endl;
	}

	return 0;
}