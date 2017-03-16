#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <assert.h>
using namespace std;

int main()
{
	ifstream file;
	ofstream output;
	file.open("A-large.in");
	output.open("data.out");
	int T;
	file >> T;
	for (int i = 1; i <= T; ++i)
	{
		int n;
		file >> n;
		string str;
		file >> str;

		int friends = 0;
		int count = 0;
		for (int j = 0; j < str.size(); ++j)
		{
			int val = str[j] - '0';
			if (count < j)
			{
				friends++;
				count++;
			}
			count += val;
		}
		output << "Case #" << i << ": " << friends;
		if (i < T)
			output << endl;
	}
	file.close();
	output.close();
	return 0;
}