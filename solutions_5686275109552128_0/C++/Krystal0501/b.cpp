#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int t;
	int result[101];

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int d;
		int size, sizetmp;
		int count = 0;
		cin >> d;
		vector<int> pancake;
		vector<int>::const_iterator cit;
		pancake.clear();
		for (int j = 0; j < d; ++j)
		{
			int tmp;
			cin >> tmp;
			pancake.push_back(tmp);
		}

		sort(pancake.begin(), pancake.end());
		size = pancake.size();
		result[i] = pancake[size - 1];
		if (result[i] == 1 || result[i] == 2 || result[i] == 3)
		{
			//result[i] = *cit;
		}
		else
		{
			while(1)
			{
				int thisresult;
				int mycit;
				int half;
				int same = 1;
				// sort(pancake.begin(), pancake.end());

				size = pancake.size();
				mycit = pancake[size - 1];
				half = mycit / 2;

				if (pancake.size() != 1)
				{
					sizetmp = size - 2;
					while(pancake[sizetmp] == mycit)
					{
						same++;
						if (sizetmp == 0)
						{
							break;
						}
						else
						{
							sizetmp--;
						}
					}
				}

				for (int j = 0; j < same; ++j)
				{
					pancake.pop_back();
					count++;
				}
				for (int j = 0; j < same; ++j)
				{
					pancake.push_back(half);
					pancake.push_back(mycit - half);
				}

				sort(pancake.begin(), pancake.end());

				size = pancake.size();
				thisresult = pancake[size - 1] + count;

				if (thisresult < result[i])
				{
					result[i] = thisresult;
				}
				
				if (pancake[size - 1] == 1
					|| pancake[size - 1] == 2
					|| pancake[size - 1] == 3)
				{
					break;
				}

			}
		}	

	}

	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i + 1 << ": " << result[i] << endl;
	}

	return 0;
}