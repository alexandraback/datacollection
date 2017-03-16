// Codejam2014_1C.cpp : Defines the entry point for the console application.
//


#include "vector"
#include "string"
#include "set"
#include "map"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include "numeric"
#include "fstream"
#ifdef __GNUC__
#include  <tr1/unordered_map>
#define unordered_map tr1::unordered_map
#else
#include <unordered_map>
#endif

using namespace std;

#define int64 long long
#define F(vec, index) for (int index = 0; index  < vec.size(); ++index)
#define F_S(vec, index, start) for (int index = start; index  < vec.size(); ++index)

int arr[30];

int64 rec(vector<string>& data, int currI, vector<bool>& selected, string currTrain)
{
	int64 res = 0;
	bool wasRes = false;
	for (int i = 0; i < data.size(); ++i)
	{
		if (!selected[i])
		{
			wasRes = true;
			selected[i] = true;
			res += rec(data, currI, selected, currTrain + data[i]);
			selected[i] = false;
		}
	}
	if (wasRes) return res;

	for (int i = 0; i < 30; ++i) arr[i] = 0;

	auto e = unique(currTrain.begin(), currTrain.end());
	for (auto i = currTrain.begin(); i != e ; ++i)
	{
		arr[*i - 'a']++;
		if (arr[*i - 'a'] > 1)
		{
			return 0;
		}
	}
	return 1;
}

int main(int argc, char* argv[])
{
	ifstream cin("in.txt");
	ofstream cout("out.txt");

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		std::cout << t << endl;
		int N;
		cin >> N;
		vector<string> data(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> data[i];
		}
		
		vector<bool> selected(N, false);
		int64 res = 0; 
		for (int i = 0; i < N; ++i)
		{
				selected[i] = true;
				res += rec(data, i, selected, data[i]);
				selected[i] = false;
		}

		cout << "Case #" << t + 1 << ": "  << res << endl;
	
		
	}

	return 0;
}
