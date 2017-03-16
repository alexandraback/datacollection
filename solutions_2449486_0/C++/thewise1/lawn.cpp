#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bitset>
#include <utility>

using namespace std;

int main()
{
	ofstream cout ("lawnS.out");
        ifstream cin ("B-small-attempt0.in");

	int trials;
	cin >> trials;

	for (int c = 0; c < trials; c++)
	{
		int N, M;
		cin >> N >> M;

		int farm[100][100];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> farm[i][j];
			}
		}
		
		bool possible = true;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				bool vert = true;
				bool horiz = true;
				for (int k = 0; k < M; k++)
				{
					if (farm[i][j] < farm[i][k])
						vert = false;
				}
				for (int k = 0; k < N; k++)
				{
					if (farm[i][j] < farm[k][j])
						horiz = false;
				}
				if (!horiz && !vert)
					possible = false;
			}
		}
		if (possible)
			cout << "Case #" << c+1 << ": YES" << endl;
		else
			cout << "Case #" << c+1 << ": NO" << endl;
	}

	return 0;	
}
