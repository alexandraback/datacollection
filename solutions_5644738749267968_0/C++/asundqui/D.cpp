#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		int N;
		cin >> N;

		set<double> naomi, ken;
		double dummy;
		for (int i = 0; i < N; ++i)
		{
			cin >> dummy;
			naomi.insert(dummy);
		}
		for (int i = 0; i < N; ++i)
		{
			cin >> dummy;
			ken.insert(dummy);
		}

		int honest = 0;
		{
			set<double> temp(ken);
			for (set<double>::iterator iter = naomi.end(); iter != naomi.begin(); )
			{
				--iter;
				set<double>::iterator find = temp.lower_bound(*iter);
				if (find != temp.end())
					temp.erase(find);
				else
				{
					temp.erase(temp.begin());
					++honest;
				}
			}
		}

		int deceiptful = 0;
		while (!naomi.empty())
		{
			set<double>::iterator nfirst = naomi.begin(), kfirst = ken.begin();
			set<double>::iterator nlast = naomi.end(), klast = ken.end();
			--nlast, --klast;
			if ((*nfirst < *kfirst) || (*klast > *nlast))
			{
				naomi.erase(nfirst);
				ken.erase(klast);
			}
			else
			{
				naomi.erase(nfirst);
				ken.erase(kfirst);
				++deceiptful;
			}
		}

		cout << "Case #" << case_num << ": " << deceiptful << " " << honest << endl;
	}
	return 0;
}