#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <istream>
#include <unordered_map>

using namespace std;

int main()
{
	int numCases;
	cin >> numCases;

	for (int i = 0; i<numCases; i++)
	{
		string str;
		cin >> str;

		vector<int> count(128, 0);
		for (int j = 0; j < str.size(); j++)
		{
			count[str[j]] ++;
		}

		vector<int> num(10, 0);
		num[0] = count['Z'];
		num[2] = count['W'];
		num[6] = count['X'];
		num[8] = count['G'];

		num[3] = count['T'] - num[2] - num[8];
		num[4] = count['R'] - num[0] - num[3];
		num[5] = count['F'] - num[4];
		num[7] = count['V'] - num[5];
		num[1] = count['O'] - num[0] - num[2] - num[4];
		num[9] = count['I'] - num[5] - num[6] - num[8];

		string res = "";
		for (int j = 0; j < 10; j++){
			if (num[j] == 0) continue;
			while (num[j] != 0){
				res += to_string(j);
				num[j]--;
			}
		}

		cout << "Case #" << i + 1 << ": " << res << endl;
	}

	return 0;
}