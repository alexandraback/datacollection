#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void main()
{
	int l_nCases = 0;
	cin>>l_nCases;

	for (int l_index = 0; l_index < l_nCases; ++l_index)
	{

		int l_numGooglers = 0;
		cin >> l_numGooglers;
		int l_nSurprising = 0;
		cin >> l_nSurprising;
		int l_p = 0;
		cin >> l_p;

		int l_count = 0;

		for (int l_indexGooglers = 0; l_indexGooglers < l_numGooglers; ++ l_indexGooglers)
		{
			int l_totalPoints = 0;
			cin>>l_totalPoints;

			if (!l_totalPoints && l_p)
				continue;

			int  l_maxScore = l_totalPoints / 3;
			int l_rest = l_totalPoints%3;

			if (l_maxScore >= l_p)
			{
				l_count +=1;
				continue;
			}

			if (l_maxScore + 1 >= l_p)
			{
				if (l_rest == 0 && l_nSurprising)
				{
					l_count += 1;		
					l_nSurprising--;
				}
				else if (l_rest == 1 || l_rest == 2)
				{
					l_count += 1;
				}
				continue;
			}

			if (l_maxScore + 2 >= l_p)
			{
				if (l_rest == 2 && l_nSurprising)
				{
					l_count += 1;		
					l_nSurprising--;
				}
				continue;
			}

		}
		cout<<"Case #"<<(l_index+1)<<": "<<l_count<<endl;
	}
}