#include <iostream>
#include <vector>
using namespace std;

int C, D, V;
vector<int> d;

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		//cerr << case_num << endl;
		cin >> C >> D >> V;
		//cerr << C << " " << D << " " << V << endl;
		d.resize(D);
		for (int i = 0; i < D; ++ i)
		{
			cin >> d[i];
			//cerr << " " << d[i];
		}
		//cerr << endl;

		int max_possible = 0;
		int cur_d = 0;
		int new_d_count = 0;
		while (max_possible < V)
		{
			if ((cur_d == d.size()) || (d[cur_d] > (max_possible + 1)))
			{
				//cerr << "Adding " << (max_possible + 1) << endl;
				d.insert(d.begin() + cur_d, max_possible + 1);
				++new_d_count;
			}
			max_possible = max_possible + C*d[cur_d];
			++cur_d;
		}

		cout << "Case #" << case_num << ": " << new_d_count << endl;
	}
	return 0;
}