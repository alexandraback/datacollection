#include <iostream>
#include <vector>
using namespace std;

int C, D, V;
vector<int> d;

bool test_cover()
{
	vector<bool> covered(V + 1, false);
	for (int i = 0; i < (1 << d.size()); ++i)
	{
		int sum = 0;
		for (int j = 0; j < d.size(); ++j)
			if (i & (1 << j))
				sum += d[j];
		if (sum <= V)
			covered[sum] = true;
	}
	/*
	for (int i = 1; i <+ V; ++i)
		cerr << (covered[i] ? '+' : '.');
	cerr << endl;
	*/

	bool all_covered = true;
	for (int i = 1; i <= V; ++i)
		if (!covered[i])
			all_covered = false;
	return all_covered;
}

bool d_unique()
{
	for (int i = D; i < d.size(); ++i)
		for (int j = 0; j < i; ++j)
			if (d[i] == d[j])
				return false;
	return true;
}

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		cerr << case_num << endl;
		cin >> C >> D >> V;
		d.resize(D);
		for (int i = 0; i < D; ++ i)
			cin >> d[i];

		int count = 0;
		bool found = false;
		for (count = 0; !found; ++count)
		{
			//cerr << "count = " << count << endl;
			d.resize(D);
			d.resize(D + count, 1);
			bool all_done = false;
			while (!all_done)
			{
				/*
				cerr << "Trying:";
				for (int i = 0; i < d.size(); ++i)
					cerr << " " << d[i];
				cerr << endl;
				*/
				if (d_unique() && test_cover())
				{
					//cerr << "FOUND" << endl;
					found = true;
					break;
				}

				int i;
				for (i = D; i < d.size(); ++i)
				{
					++d[i];
					if (d[i] > V)
						d[i] = 1;
					else
						break;
				}
				if (i >= d.size())
					all_done = true;
			}
			if (found)
				break;
		}
		cout << "Case #" << case_num << ": " << count << endl;
	}
	return 0;
}