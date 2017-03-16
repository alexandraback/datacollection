#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	unsigned int count = 0;
	double temp = 0.0;
	
	cin >> count;
	
	for (unsigned int i = 0; i < count; ++i)
	{
		unsigned int blocks = 0;
		
		cin >> blocks;
		
		vector<double>
			naomi,
			ken;
		
		for (unsigned int j = 0; j < blocks; ++j)
		{
			cin >> temp;
			naomi.push_back(temp);
		}
		
		for (unsigned int j = 0; j < blocks; ++j)
		{
			cin >> temp;
			ken.push_back(temp);
		}
		
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());
		
		unsigned int
			regular = 0,
			deceit = 0;
		
		vector<double> ktemp = ken;
		
		for (unsigned int n = 0; n < naomi.size(); ++n)
		{
			unsigned int k = 0;
			for (k = 0; k < ktemp.size(); ++k)
				if (ktemp[k] > naomi[n])
					break;
			
			if (k == ktemp.size())
			{
				++regular;
				k = 0;
			}
			
			ktemp.erase(ktemp.begin() + k);
		}
		
		ktemp = ken;
		
		while (naomi.size())
		{
			if (naomi.front() > ktemp.front())
			{
				naomi.erase(naomi.begin());
				ktemp.erase(ktemp.begin());
				++deceit;
			}
			else
			{
				naomi.erase(naomi.begin());
				ktemp.erase(ktemp.end() - 1);
			}
		}
		
		cout << "Case #" << (i + 1) << ": " << deceit << " " << regular << endl;
	}
	
	return 0;
}
