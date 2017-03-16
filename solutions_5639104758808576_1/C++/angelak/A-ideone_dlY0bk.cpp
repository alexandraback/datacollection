#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	for(int i = 0; i<cases; i++)
	{
		int maxShyness;
		string totalPeople;
		cin >> maxShyness >> totalPeople;
		int friends = 0;
		int people = 0;
		for(int i = 0; i<maxShyness; i++)
		{
			people += totalPeople[i] - '0';
			while(people<(i + 1))
			{
				friends++;
				people++;
			}
		}
		cout << "Case #" << (i + 1) << ": " << friends << "\n";
	}
	return 0;
}
