#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	ifstream in("E:\\GoogleCodeJam2012\\Round1A\\A-small-attempt0.in");
	ofstream out("E:\\GoogleCodeJam2012\\Round1A\\A-small-attempt0.out");

	if (in.is_open())
	{
		int cases;

	    in >> cases;

		for (int c = 1;c <= cases;++c)
		{
			int typed, whole;
			in >> typed >> whole;

			double* originP = new double[typed];
			double currentP = 1.0;

			for (int i = 0;i < typed;++i)
			{
				in >> originP[i];
			}

			double* p = new double[typed + 1];
			p[0] = 1 - originP[0];

			for (int i = 1;i <= typed;++i)
			{
				double mul = 1.0;

				for (int j = 0;j < i;++j)
				{
					mul *= originP[j];
				}

				if (i == typed)
				{
					p[i] = mul;
				}
				else
				{
					p[i] = mul * (1 - originP[i]);
				}
			}

			double min = 500000000;
			int remains = whole - typed;

			// Backspace press n times
			for (int i = 0;i <= typed;++i)
			{				
				double exp = 0.0;

				//打了幾個字才錯
				for (int j = 0;j <= typed;++j)
				{
					int keys = 0;

					// back + key字 + 剩下字 + Enter
					keys += i * 2 + remains + 1;

					//若對, 則結束, 錯則重打
					if (typed - i > j)
					{
						keys += whole + 1;
					}

					exp += (p[j] * keys);
				}

				if (exp < min)
				{
					min = exp;
				}
			}

			// Enter right away, enter + whole + enter
			double enterRightAway = 1.0 + whole + 1.0;

			if (enterRightAway < min)
			{
				min = enterRightAway;
			}

			out << "Case #" << c << ": " << fixed << setprecision(6) << min << endl;

			delete [] p;
		}
	}

	return 0;
}
