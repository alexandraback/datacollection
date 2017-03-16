// QR1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool heights[2500];
int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		for (int i = 0; i < 2500; i++)
		{
			heights[i] = false;
		}
		int N;
		cin >> N;
		vector<int> result;
		for (int i = 0; i < (2*N - 1)*N; i++)
		{
			int a;
			cin >> a;
			heights[a] = !heights[a];
		}
		for (int i = 0; i < 2500; i++)
		{
			if (heights[i])
			{
				result.push_back(i);
			}
		}
		sort(result.begin(), result.end());
		cout << "Case #" << i << ":";
		for (int i = 0; i < result.size(); i++)
		{
			cout << " " << result[i];
		}
		cout << endl;
	}
	return 0;
}

