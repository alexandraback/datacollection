#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>


using namespace std;

bool flag[101][101][101];

void p1(istream& fs, ostream& ofs)
{
	int t;
	fs >> t;
	for (int j = 1; j <= t; j++)
	{
		long long N;
		fs >> N;
		if (N == 0)
		{
			ofs << "Case #" << j << ": INSOMNIA" << endl;
			continue;
		}
		bool flag[10];
		memset(flag, 0, 10);
		for (long long i = N;; i += N)
		{
			long long temp = i;
			bool a = true;
			while (temp)
			{
				flag[temp % 10] = true;
				temp /= 10;
			}
			for (int i = 0; i < 10; i++)
			{
				a &= flag[i];
			}
			if (a)
			{
				ofs << "Case #" << j << ": " << i << endl;
				break;
			}
		}
	}

}




int main()
{
	int task;
	ifstream ifs;
	ifs.open("A-large.in");
	ofstream ofs;
	ofs.open("output.txt");
	p1(ifs, ofs);

	system("pause");
	return 0;
}
