#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d:", testCounter + 1);
		int n;
		cin >> n;
		vector<int> v(n);
		int sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> v[i];
			sum += v[i];
		}
		double goal;
		int tmpN = n;
		vector<bool> skipped(n, false);
		int tmpSum = sum;
		while(1) {
			goal = (sum + tmpSum) / (double)tmpN;
			bool b = false;
			for (int i = 0; i < n; i++)
			{
				if (skipped[i])
					continue;
				if ((double)v[i] > goal + epsilon)
				{
					tmpSum -= v[i];
					tmpN--;
					skipped[i] = true;
					b = true;
				}
			}
			if(!b)
				break;
		}
		
		for (int i = 0; i < n; i++)
		{
			if (v[i] + epsilon < goal)
				printf(" %.7lf", 100.0 * ((goal - v[i]) / (double)sum));
			else
				printf(" 0.000000");
		}
		cout << endl;
	}
	return 0;
}
