#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("file.in");
ofstream fout("file.out");

inline bool isConsonant(char ch)
{
	return (ch != 'a' && ch!= 'e' && ch!='i' && ch!= 'o' && ch != 'u');
}

int main()
{
	int t;
	int n;

	int i,r, k, j;
	int result = 0;
	int consecutive;
	int maxConsecutive;
	char str[100005];
	fin >> t;
	bool good;

	for (i =0 ; i < t; i++)
	{
		fin >> str >> n;

		result = 0;
		int len = strlen(str);

		for (r = n; r <= len; r++)
		{
			for (k = 0; k <= len-r; k++)
			{
				consecutive = 0;
				maxConsecutive = -1;
				for (j = k; j < k+r;j++)
				{
					if (isConsonant(str[j]))
					{
						consecutive++;
					} else {
						if (maxConsecutive < consecutive)
							maxConsecutive = consecutive;
						consecutive = 0;
					}
				}
				if (maxConsecutive < consecutive)
					maxConsecutive = consecutive;
				
				if (maxConsecutive >= n)
				{
					result++;
				}
			}
		}

		fout << "Case #" << (i+1) << ": " << result << endl;
		/*for (r = 0; r < len; r++)
			flag[r] = 0;
		
		consecutive = 0;
		for (r = 0; r < len; r++)
		{
			if (r+n <= len)
			{
				good = true;
				for (int k = r; k < r+n; k++)
				{
					if (!isConsonant(str[k])
					{
						good = false;
						break;
					}
				}
				if (good)
		}	*/
	}
}