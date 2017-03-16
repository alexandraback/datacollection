#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int calcE(vector<int> v, int n)
{
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int c = 0;
	for(size_t i = 0; i < v.size(); i++)
	{
		c += (v[i] - 1) / n;
	}

	return c + n;
}

int calc(vector<int> v)
{
	sort(v.begin(), v.end());
	int max = v[v.size() - 1];
	vector<int> result;
	for(int i = 1; i <= max; i++)
	{
		result.push_back(calcE(v, i));
	}
	sort(result.begin(), result.end());
	return result[0];
}

int main()
{
	int totalcase = 0;
	cin >> totalcase;
	int output[totalcase];
	
	for(int i = 0; i < totalcase; i++)
	{
		int total = 0;
		cin >> total;

		int temp = 0;
		vector<int> v;
		for(int i = 0; i < total; i++)
		{
			cin >> temp;
			v.push_back(temp);
		}
		output[i] = calc(v);
	}
	
	for(int i = 0; i < totalcase; i++)
	{
		cout << "Case #" << (i + 1) << ": " << output[i] << endl;
	}
	return 0;
}