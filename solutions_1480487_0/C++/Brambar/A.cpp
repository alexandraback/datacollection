#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> points;

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; test++)
	{
		int n;
		cin >> n;
		
		points.clear();
		points.resize(n);

		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> points[i];
			sum += points[i];
		}
		
		vector<double> temp(n);
		vector<double> result(n);
		double all = (double)200 / n;
		double tempsum = 0;
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			double fr = ((double)points[i] / sum) * 100;
			temp[i] = fr;
			if(fr > all)
			{
				tempsum += fr;
				cnt++;
			}
			//result[i] = max(0.0, all - fr);
		}

		double needed = ((double)200 - tempsum) / (n - cnt);
		for(int i = 0; i < n; i++)
		{
			if(temp[i] > all)
				result[i] = 0;
			else
				result[i] = needed - temp[i];
		}

		cout << "Case #" << test << ":";
		//double alres = 0;
		for(int i = 0; i < (int)result.size(); i++)
		{
			//alres += result[i];
			printf(" %.6f", result[i]);
		}
		cout << endl;
		//cout << alres << endl;

	}
	return 0;
}