#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int repeat;
	vector<double> naomi;
	vector<double> ken;
	cin >> repeat;
	for (int i = 0; i < repeat; i++)
	{
		int num, warCount = 0, dWarCount = 0, kenMaxIdx, kenMinIdx;
		double tmpValue;

		naomi.clear();
		ken.clear();
		
		cin >> num;

		int warFlags[num];
		
		for (int j = 0; j < num; j++)
		{
			warFlags[j] = 0;
			cin >> tmpValue;
			naomi.push_back(tmpValue); 
		}

		for (int j = 0; j < num; j++)
                {
                        cin >> tmpValue;
                        ken.push_back(tmpValue);
                }

		std::sort(naomi.begin(), naomi.end());
		std::sort(ken.begin(), ken.end());
		kenMaxIdx = num - 1;
		kenMinIdx = 0;
		
		for (int j = num - 1; j >= 0; j--)
		{
			if (ken[kenMaxIdx] < naomi[j] || ken[kenMinIdx] > naomi[j])
			{
				int idx = kenMinIdx;
				if (ken[kenMaxIdx] < naomi[j]) warCount++;
				warFlags[kenMinIdx] = 1;
				kenMinIdx = -1; // If it does not get value means that all the blocks have been played
				for (int k = idx + 1; k <= kenMaxIdx; k++)
					if (!warFlags[k])
					{
						kenMinIdx = k;
						break;
					}
				continue;
			}
			for (int k = kenMinIdx + 1; k <= kenMaxIdx; k++)
			{
				if (warFlags[k]) continue;
				if (ken[k] > naomi[j])
				{
					warFlags[k] = 1;
					if (k == kenMaxIdx)
					{
						int idx = kenMaxIdx;
						kenMaxIdx = -1; // If it does not get value means that all the blocks have been played
						for (int l = idx - 1; l >= kenMinIdx; l--)
                                        	if (!warFlags[l])
                                        	{
                                                	kenMaxIdx = l;
                                                	break;
                                        	}
					}
					break;
				}
			}
		}

		while(num > 0)
		{
			if (naomi[num - 1] < ken[num - 1] || naomi[0] < ken[0])
			{
				ken.erase(ken.begin() + num - 1);
				naomi.erase(naomi.begin());
			}
			else dWarCount++;
			num--;
		}

		cout << "Case #" << (i + 1) << ": " << dWarCount << " " << warCount << endl;
	}
	return 0;
}
