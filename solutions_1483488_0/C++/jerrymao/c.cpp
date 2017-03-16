#include <fstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

void convert(char* temp, const int x)
{
	int z = (int) ceil(log10((double)x));
	if ((double)x == pow(10.0, z)) z++;
	for (int i = z-1;i >= 0;i--)
	{
		int y = x % ((int)pow(10.0, i+1));
		y /= ((int)(pow(10.0, i)));
		temp[i] = y+'0';
	}
	reverse(temp, temp+z);
	temp[z] = '\000';
}

int main()
{
	ifstream in("input3.txt", ios::in);
	ofstream out("output3.txt", ios::out);
	int t; in >> t;
	for (int i = 1;i <= t;i++)
	{
		int a, b, ans = 0;
		in >> a >> b;
		for (int j = a;j <= b;j++)
		{
			vector<int> done;
			char temp[8];
			convert(temp, j);
			int x = strlen(temp);
			for (int k = 1;k < x;k++)
			{lol:
				for (int l = 1;l < x;l++)
					swap(temp[0], temp[l]);
				int y = atoi(temp);
				for (unsigned int l = 0;l < done.size();l++)
					{if (done[l] == y)
						goto lol;}
				if (y > j && y <= b)
				{
					ans++;
					done.push_back(y);
				}
			}
		}
		out << "Case #" << i << ": " << ans << "\n";
	}
	in.close();
	out.close();
	return 0;
}
