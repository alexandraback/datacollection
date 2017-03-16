#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int DP[12][12];
int values[12] = {0};
int max_E = 0;

int find_max(int E, int R, int i);

int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("problemB-small.in");
	cout.open("problemB-small-out.txt");

	int T;
	cin >> T;
	for(int test = 1; test <= T; test++)
	{
		for(int i = 0; i < 12; i++)
		{
			values[i] = 0;
			for(int j = 0; j < 12; j++)
				DP[i][j] = -1;
		}
		int E, R, N;
		cin >> E >> R >> N;
		max_E = E;
		for(int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			values[i] = temp;
		}
		R = min(R,E);
		cout << "Case #" << test << ": " << find_max(E,R,0) << endl;
	}

	cin.close();
	cout.close();

	return 0;
}

int find_max(int E, int R, int index)
{
	if(values[index] == 0) return 0;
	if(DP[E][index] != -1) return DP[E][index];
	int maximum = 0;
	for(int i = 0; i <= E; i++)
	{
		int res = i*values[index] + find_max(min(E - i + R, max_E), R, index+1);
		maximum = max(maximum, res);
	}
	DP[E][index] = maximum;
	return maximum;
}
