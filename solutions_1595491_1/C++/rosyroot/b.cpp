#include <iostream>

using namespace std;


int main()
{
	int ncase;
	int T;
	int ngoog;
	int nsup;
	int p;
	int out;
	int num;
	int avg;
	int rest;
	int trysup;
	int i;

	cin >> ncase;
	for (T = 0; T < ncase; T++)
	{
		out = 0;
		cin >> ngoog >> nsup >> p;
		for (i = 0; i < ngoog; i++)
		{
			cin >> num;
			if (num == 0 && p != 0)
				continue;

			avg = num / 3;
			rest = num % 3;
			trysup = 0;
			if (avg >= p)
				out++;
			else if (p >= 1 && avg == p - 1)
			{
				if (rest == 2)
					out++;
				else if (rest == 1)
					out++;
				else if (rest == 0)
					trysup = 1;
			}
			else if (p >= 2 && avg == p - 2 && rest == 2)
			{
				trysup = 1;
			}

			if (nsup > 0 && trysup)
			{
				out++;
				nsup--;
			}
		}

		cout << "Case #" << T + 1 << ": " << out << endl;
	}
	return 0;
}
