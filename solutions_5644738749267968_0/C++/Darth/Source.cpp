#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


int main()
{
	int t;

	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int n;
	int i, r;
	float ken1[1001];
	float naomi1[1001];
	float ken2[1001];
	float naomi2[1001];
	int score1, score2;

	fin >> t;
	for (int test = 0; test < t; test++)
	{
		fin >> n;
		for (i = 0; i < n; i++)
			fin >> naomi1[i];
		for (i = 0; i < n; i++)
			fin >> ken1[i];

		sort(naomi1, naomi1 + n);
		sort(ken1, ken1 + n);

		for (i = 0; i < n; i++)
		{
			naomi2[i] = naomi1[i];
			ken2[i] = ken1[i];
		}

		score1 = 0;
		score2 = 0;
		
		for (i = n - 1; i >= 0; i--)
		{
			for (r = 0; r < n; r++)
			{
				if (ken1[r] == -1)
					continue;
				if (ken1[r] > naomi1[i])
				{
					naomi1[i] = -1;
					ken1[r] = -1;
					break;
				}
			}
			if (naomi1[i] != -1)
			{
				score1++;
				for (r = 0; r < n; r++)
					if (ken1[r] != -1)
					{
						ken1[r] = -1;
						break;
					}

				naomi1[i] = -1;
			}
		}

		for (i = 0; i < n; i++)
		{
			if (naomi2[i] != -1)
			{
				for (r = n - 1; r >= 0; r--)
				{
					if (ken2[r] == -1) continue;
					if (ken2[r] < naomi2[i])
					{
						score2++;
						ken2[r] = -1;
						naomi2[i] = -1;
						break;
					}
				}
			}
		}
		
		fout << "Case #" << (test + 1) << ": " << score2 << " " << score1 << endl;
	}
	return 0;
}