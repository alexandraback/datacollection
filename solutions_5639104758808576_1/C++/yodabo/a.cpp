// a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int Smax;
		cin >> Smax;
		
		cin.get(); // skip the space (yeah, its horrible, but easy, assuming the format of one space is continued)
		
		
		int standing = 0;
		int numfriends = 0;
		for (int j = 0; j <= Smax; ++j)
		{
			
			int audienceAtLevelj = (cin.get() - '0');
			
			if (audienceAtLevelj > 0)
			{
				int numNewFriends = 0;
				// do we have enough for everyone at shynesslevel of j to stand?
				if (standing < j)
				{
					numNewFriends = j - standing;
				}

				numfriends += numNewFriends;
				standing += (audienceAtLevelj + numNewFriends);
			}
		}

		cout << "Case #" << (1 + i) << ": " << numfriends << endl;
	}

	return 0;
}

