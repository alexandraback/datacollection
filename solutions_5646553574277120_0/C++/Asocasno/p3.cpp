#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	int tests;
	cin >> tests;

	for(int a=0; a<tests; a++)
	{
		int num, existing, goal;
		cin >> num >> existing >> goal;

		vector<int> exist;
		for(int i=0; i<existing; i++)
		{
			int temp;
			cin >> temp;
			exist.push_back(temp);
		}
		sort(exist.begin(), exist.end());


		vector<int> poss(goal+1, 0);
		poss[0] = 1;

		for(int i=0; i<exist.size(); i++)
		{
			int at = exist[i];

			vector<int> newPoss(poss);

			for(int j=0; j<poss.size(); j++)
			{
				if(poss[j])
				{
					int cur = at + j;
					while(cur <= ((num * at) + j))
					{
						if(cur > goal)
						{
							break;
						}
						newPoss[cur] = 1;
						cur += at;
					}
				}
			}
			poss = newPoss;
		}


		int retval = 0;
		while(accumulate(poss.begin(), poss.end(), 0) != (goal+1))
		{
			cerr << accumulate(poss.begin(), poss.end(), 0) << endl;
			retval++;

			int found = 0;
			for(int i=1; !found && (i<=goal); i++)
			{
				if(poss[i] == 0)
				{
					found = i;
				}
			}
			cerr << "Found " << found << endl;


			int at = found;
			vector<int> newPoss(poss);

			for(int j=0; j<poss.size(); j++)
			{
				if(poss[j])
				{
					int cur = at + j;
					while(cur <= ((num * at) + j))
					{
						if(cur > goal)
						{
							break;
						}
						newPoss[cur] = 1;
						cur += at;
					}
				}
			}
			poss = newPoss;

		}


		cout << "Case #" << (a+1) << ": " << retval << endl;
	}

	return 0;
}
