#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	int N, T,H, H2;
	double  D, M, D2,  M2;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		cin >> D >> H >> M;
		if (N == 2)
			cin >> D2 >> H2 >> M2;
		if (H == 2)
		{
			D2 = D;
			M2 = M + 1;
		}
		int res = 0;
		if (N == 1 && H == 1)
			res = 0;
		else
		{
			if (D > D2)
			{
				swap(D, D2);
				swap(M, M2);
			}
			if (M > M2 && D < D2)
			{
				double tim = (D2-D) / (M - M2);
				if (tim * M < (360 - D))
				{
					D = D + tim * M;
					D2 = D2 + tim * M2;
				}
				cerr << D << ' '<< D2 << endl;
			}
			double t1 = (360.0 - D) * M;
			double t2 = (360.0 - D2) * M2;
			double t3;
			if (t1 < t2)
			{
				t3 = t1 + 360.0 * M;
				if (t3 < t2)
					res = 1;
				else
					res = 0;
			}else
			{
				t3 = t2 + 360.0 * M2;
				if (t3 < t1)
					res = 1;
				else
					res = 0;
			}
		}
		cout << "Case #" << t << ": " << res << endl;		
	}
}