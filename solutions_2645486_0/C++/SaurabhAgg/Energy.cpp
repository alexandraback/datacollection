#include<iostream>
using namespace std;

int best_gain[6][11];
int E, R, N;
int values[11];

int findBestGain()
{
	for(int i = 0; i <= E; i++)
		for(int j = 0; j <= N; j++)
			best_gain[i][j] = 0;
	
	for(int task = 1; task <= N; task++)
	{
		for(int used_en = 0; used_en <= E; used_en++)
		{
			for(int j = used_en; j <= E; j++)
			{
				int rem_en = min(R + j - used_en, E);
				best_gain[rem_en][task] = max(best_gain[rem_en][task], best_gain[j][task - 1] + used_en*values[task]);
			}
		}
	}
	
	/*
	for(int i = 0; i <= E; i++)
	{
		for(int j = 0; j <= N; j++)
			cout << best_gain[i][j] << "\t";
		cout << endl;
	}
	*/
	
	int ans = 0;
	for(int i = 0; i <= E; i++)
		ans = max(ans, best_gain[i][N]);
	return ans;
}

int main()
{
	int cases;
	cin >> cases;
	
	for(int t = 1; t <= cases; t++)
	{
		cin >> E >> R >> N;
		for(int i = 0; i < N; i++)
			cin >> values[i + 1];
		int best = findBestGain();
		cout << "Case #" << t << ": " << best << endl;
	}
	
	return 0;
}
