#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int K, L, S;
string keys, target;

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		cin >> K >> L >> S;
		cin >> keys >> target;
		cerr << K << " " << L << " " << S << " " << keys << " " << target << endl;

		int max_possible = 0;
		bool keys_exist = true;
		for (int j = 0; j < L; ++j)
		{
			if (keys.find_first_of(target[j]) == string::npos)
				keys_exist = false;
		}

		if (keys_exist)
		{
			string fill(S, ' ');
			for (int i = 0; i <= (S - L); ++i)
			{
				bool okay = true;
				for (int j = 0; j < L; ++j)
					if ((fill[i + j] != ' ') && (fill[i + j] != target[j]))
						okay = false;

				if (okay)
				{
					++max_possible;
					for (int j = 0; j < L; ++j)
						fill[i + j] = target[j];
				}
			}
		}

		cerr << max_possible << endl;

		double Pmatch = 1.0;
		for (int j = 0; j < L; ++j)
		{
			int num_keys = 0;
			for (int i = 0; i < K; ++i)
				if (keys[i] == target[j])
					++num_keys;

			Pmatch *= double(num_keys) / double(K);
		}
		double Ecount = ((S - L) + 1) * Pmatch;

		double Eremaining = double(max_possible) - Ecount;
		cout << "Case #" << case_num << ": " << setprecision(9) << Eremaining << endl;

	}
	return 0;
}

/*

E[payout] = E[match 0] + E[match 1]

*/