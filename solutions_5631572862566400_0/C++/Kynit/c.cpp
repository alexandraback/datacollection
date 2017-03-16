#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(void)
{
	vector< vector<int> > permutations;
	vector<int> base;
	for(int j = 1; j <= 10; j++)
	{
		base.push_back(j);
	}

	vector<int> dist;
	dist.push_back(1);
	for(int j = 1; j <= 10; j++)
	{
		dist.push_back(dist[j-1] * j);
	}

	for(int j = 0; j < dist[10]; j++)
	{
		for(int k = 0; k < 10; k++)
		{
			if(j % dist[k] != 0)
				continue;

			vector<int> newPerm(base.begin(), base.end() - k);
			permutations.push_back(newPerm);
		}

		next_permutation(base.begin(), base.end());
	}


	int t;
	cin >> t;

	for(int i = 1; i <= t; i++)
	{
		int n;
		cin >> n;

		vector<int> f;
		f.push_back(0);
		for(int j = 0; j < n; j++)
		{
			int nextF;
			cin >> nextF;
			f.push_back(nextF);
		}	


		int maxLength = 0;
		for(int j = 0; j < permutations.size(); j++)
		{
			if(permutations[j].size() <= maxLength)
				continue;

			if(permutations[j].size() > n)
				continue;

			if(*max_element(permutations[j].begin(), permutations[j].end()) > n)
				continue;

			bool good = true;
			for(int k = 0; k < permutations[j].size(); k++)
			{
				int length = permutations[j].size();
				int id = permutations[j][k];
				int  leftNeighbour = permutations[j][(k-1 + length) % length];
				int rightNeighbour = permutations[j][(k+1 + length) % length];

				if(leftNeighbour != f[id] && rightNeighbour != f[id])
				{
					good = false;
					break;
				}
			}
			if(good)
			{
				maxLength = permutations[j].size();
			}
			
		}

		cout << "Case #" << i << ": " << maxLength << endl;
	}

	return 0;
}
