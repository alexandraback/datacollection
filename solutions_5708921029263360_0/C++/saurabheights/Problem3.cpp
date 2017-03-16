#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void findMaximumIndex(int arr2D[10][10], int m, int n, int maxLocationRow, int maxLocationCol)
{
	maxLocationRow = 0;
	maxLocationCol = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr2D[i][j] > arr2D[maxLocationRow][maxLocationCol])
			{
				maxLocationRow = i;
				maxLocationCol = j;
			}
		}
	}
}

int main() {
	int testCases;
	long long int N, J, P, S, K; //Starting variables
	string a, b; //Starting variables
	cin >> testCases;

	for (int t = 1; t <= testCases; t++)
	{
		cin >> J >> P >> S >> K;

		cout << "Case #" << t << ": ";
		if (J == P == S)
		{
			cout << "1\n1 1 1\n";
			continue;
		}

		int JP[10][10], JPCopy[10][10];
		int PS[10][10], PSCopy[10][10];
		int JS[10][10], JSCopy[10][10];
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				JP[i][j] = PS[i][j] = JS[i][j] = K;
				JPCopy[i][j] = PSCopy[i][j] = JSCopy[i][j] = K;
			}
		}

		int count = 0;
		int prevOutputI = -1;
		int prevOutputJ = -1;
		int prevOutputK = -1;
		bool RepeatableOutfitFound = false;
		int repeatableOutfitFoundI = -1;
		int repeatableOutfitFoundJ = -1;
		int repeatableOutfitFoundK = -1;

		while (true)
		{
			int prevCount = count;	
			for (int i = 0; i < J; i++)
			{
				for (int j = 0; j < P; j++)
				{
					for (int k = 0; k < S && JP[i][j] > 0; k++)
					{
						if (PS[j][k] > 0 && JS[i][k] > 0)
						{
							if (i == prevOutputI && j == prevOutputJ && k == prevOutputK)
							{
								RepeatableOutfitFound = true;
								continue;
							}
							JP[i][j]--;
							PS[j][k]--;
							JS[i][k]--;
							prevOutputI = i;
							prevOutputJ = j;
							prevOutputK = k;
							count++;
							RepeatableOutfitFound = false;
						}
					}
				}
			}

			if (prevCount == count)
			{
				if (RepeatableOutfitFound)
				{
					repeatableOutfitFoundI = prevOutputI;
					repeatableOutfitFoundJ = prevOutputJ;
					repeatableOutfitFoundK = prevOutputK;
					count += min(JP[repeatableOutfitFoundI][repeatableOutfitFoundJ], min(PS[repeatableOutfitFoundJ][repeatableOutfitFoundK], JS[repeatableOutfitFoundI][repeatableOutfitFoundK]));
				}
				break;
			}
		}

		cout << count << endl;
		//Print all outfits
		count = 0;
		prevOutputI = -1;
		prevOutputJ = -1;
		prevOutputK = -1;
		while (true)
		{
			int prevCount = count;
			if (RepeatableOutfitFound && JP[repeatableOutfitFoundI][repeatableOutfitFoundJ] > 0 && PS[repeatableOutfitFoundJ][repeatableOutfitFoundK] > 0 && JS[repeatableOutfitFoundI][repeatableOutfitFoundK] > 0)
			{
				if (prevOutputI != repeatableOutfitFoundI || prevOutputJ != repeatableOutfitFoundJ || prevOutputK != repeatableOutfitFoundK)
				{
					cout << repeatableOutfitFoundI + 1 << " " << repeatableOutfitFoundJ + 1 << " " << repeatableOutfitFoundK + 1 << endl;
					prevOutputI = repeatableOutfitFoundI;
					prevOutputJ = repeatableOutfitFoundJ;
					prevOutputK = repeatableOutfitFoundK;
					JP[repeatableOutfitFoundI][repeatableOutfitFoundJ]--;
					PS[repeatableOutfitFoundJ][repeatableOutfitFoundK]--;
					JS[repeatableOutfitFoundI][repeatableOutfitFoundK]--;
					count++;
				}
			}
			for (int i = 0; i < J; i++)
			{
				for (int j = 0; j < P; j++)
				{
					for (int k = 0; k < S && JPCopy[i][j] > 0; k++)
					{
						if (PSCopy[j][k] > 0 && JSCopy[i][k] > 0)
						{
							if (i == prevOutputI && j == prevOutputJ && k == prevOutputK)
							{
								continue;
							}
							JPCopy[i][j]--;
							PSCopy[j][k]--;
							JSCopy[i][k]--;
							cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
							prevOutputI = i;
							prevOutputJ = j;
							prevOutputK = k;
							count++;
							if (RepeatableOutfitFound && JP[repeatableOutfitFoundI][repeatableOutfitFoundJ] > 0 && PS[repeatableOutfitFoundJ][repeatableOutfitFoundK] > 0 && JS[repeatableOutfitFoundI][repeatableOutfitFoundK] > 0)
							{
								if (prevOutputI != repeatableOutfitFoundI || prevOutputJ != repeatableOutfitFoundJ || prevOutputK != repeatableOutfitFoundK)
								{
									cout << repeatableOutfitFoundI + 1 << " " << repeatableOutfitFoundJ + 1 << " " << repeatableOutfitFoundK + 1 << endl;
									prevOutputI = repeatableOutfitFoundI;
									prevOutputJ = repeatableOutfitFoundJ;
									prevOutputK = repeatableOutfitFoundK;
									JP[repeatableOutfitFoundI][repeatableOutfitFoundJ]--;
									PS[repeatableOutfitFoundJ][repeatableOutfitFoundK]--;
									JS[repeatableOutfitFoundI][repeatableOutfitFoundK]--;
									count++;
								}
							}
						}
					}
				}
			}

			if (prevCount == count)
				break;
		}
	}

	return 0;
}