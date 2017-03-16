#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
 
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output31.txt", "w", stdout);

	int nTestCase = 0;
	cin >> nTestCase;
 
	for (int iTestCase = 0; iTestCase < nTestCase; iTestCase++)
	{

		long long setLimit = 0;
		long long answer = 0;
		long long C, D, V, t;
		long long tCoin = 0;
		priority_queue<long long> coinSet;
		cin >> C >> D >> V;
		for (int i = 0; i < D; i++){
			cin >> t;
			for (int j = 0; j < C; j++)
				coinSet.push(-t);
		}
		for (;;){
			if (setLimit >= V) break;

			if (coinSet.empty())
			{
				answer++;
				for (int j = 0; j < C; j++)
					coinSet.push(-(setLimit + 1));
			}

			tCoin = -coinSet.top();
			if (setLimit + 1 >= tCoin)
			{
				setLimit += tCoin;
				coinSet.pop();
			}
			else{
				answer++;
				for (int j = 0; j < C; j++)
					coinSet.push(-(setLimit + 1));
			}
		}
		cout << "Case #" << iTestCase + 1 << ": " << answer << endl;
	}
	return 0;
}