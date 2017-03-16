#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
			int N, temp;
			map<int, int> numbers;
			vector<int> arr;

			cin >> N;

			for (int j = 0; j < (N * (2 * N - 1)); ++j)
			{
				cin >> temp;
				if (numbers.find(temp) == numbers.end())
				{
						numbers.insert(pair<int, int>(temp, 1));
				}
				else {
					numbers.at(temp)++;
				}
			}

			for (map<int,int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
			{
				if (it->second % 2 == 1)
				{
					arr.push_back(it->first);
				}
			}

			sort (arr.begin(), arr.end());

			cout << "Case #" << i + 1 << ":";

			for (vector<int>::iterator it = arr.begin() ; it != arr.end(); ++it)
			{
				cout << " " << *it;
			}
			cout << endl;

	}

	return 0;
}