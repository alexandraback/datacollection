#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

struct City
{
	string code;
	set<int> flightsFrom;
};

void solveCase()
{
	int n, m;
	cin >> n >> m;

	vector<City> cities(n);

	for(City& c : cities)
	{
		cin >> c.code;
	}

	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;

		cities[a].flightsFrom.insert(b);
		cities[b].flightsFrom.insert(a);
	}

	auto cityComp = [&](int a, int b) { return cities[a].code < cities[b].code; };

	vector<int> cityPer(n);
	for(int i = 0; i < n; i++)
	{
		cityPer[i] = i;
	}

	sort(cityPer.begin(), cityPer.end(), cityComp);

	do
	{
		vector<int> cityStack;
		cityStack.push_back(cityPer.front());

		for(int i = 1; i < cityPer.size(); i++)
		{
			int cityNow = cityPer[i];

			for(int j = cityStack.size() - 1; j >= 0; j--)
			{
				if(cities[cityNow].flightsFrom.count(cityStack[j]))
				{
					cityStack.resize(j + 1);
					cityStack.push_back(cityNow);
					break;
				}

				if(j == 0) goto skip;
			}
		}

		for(int i : cityPer)
		{
			cout << cities[i].code;
		}
		return;

	skip:;
	} while(next_permutation(cityPer.begin(), cityPer.end(), cityComp));

	assert(false);
}

int main()
{
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cout << "Case #" << i << ": ";
		solveCase();
		cout << endl;
	}

	return 0;
}