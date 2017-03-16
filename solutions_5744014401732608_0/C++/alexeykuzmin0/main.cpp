#define _CRT_SECURE_NO_WARNINGS
#include <ios>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <future>
#include <numeric>
#include <functional>
#include <iterator>

using namespace std;

struct Input
{
	int b;
	long long m;

	friend istream& operator >> (istream& lhs, Input& rhs)
	{
		return lhs >> rhs.b >> rhs.m;
	}
};

struct Output
{
	int b;
	long long m;
	vector<vector<bool>> matrix;

	friend ostream& operator << (ostream& lhs, const Output& rhs)
	{
		static int case_number = 0;
		lhs << "Case #" << ++case_number << ": ";
		if (rhs.matrix.empty())
		{
			lhs << "IMPOSSIBLE" << endl;
		}
		else
		{
			lhs << "POSSIBLE\n";
			for (auto& v : rhs.matrix)
			{
				for (auto x : v)
				{
					lhs << char('0' + x);
				}
				lhs << endl;
			}
		}
		return lhs;
	}
};

Output solve(Input input)
{
	if (input.m > (1LL << (input.b - 2)))
	{
		return{};
	}
	vector<vector<bool>> ans(input.b, vector<bool>(input.b, false));
	vector<long long> q(input.b, 0);
	q[0] = 1;
	for (int i = 1; i < input.b - 1; ++i)
	{
		for (int j = i - 1; j > -1; --j)
		{
			ans[j][i] = true;
			q[i] += q[j];
		}
	}
	for (int j = input.b - 2; j > -1; --j)
	{
		if (q[input.b - 1] + q[j] <= input.m)
		{
			q[input.b - 1] += q[j];
			ans[j][input.b - 1] = true;
		}
	}
	return{ input.b, input.m, ans };
}

int main(int argc, char* argv[])
{
	auto start = chrono::system_clock::now();
	ios_base::sync_with_stdio(false);
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	int t;
	fin >> t;
	int ready = 0;
	vector<future<Output>> tasks;
	mutex cout_mutex;
	for (int i = 0; i < t; ++i)
	{
		Input input;
		fin >> input;
		tasks.push_back(async([&ready, &t, &cout_mutex](Input input)
		{
			auto ans = solve(input);
			cout_mutex.lock();
			system("cls");
			cout << ++ready << "/" << t << endl;
			cout_mutex.unlock();
			return ans;
		}, input));
	}
	for (auto& task : tasks)
	{
		fout << task.get();
	}
	auto finish = chrono::system_clock::now();
	auto elapsed = chrono::duration_cast<chrono::duration<float, std::ratio<1, 1>>>(finish - start);
	cout << "Done!" << endl;
	cout << "Time elapsed: " << elapsed.count() << " s" << endl;
	string s;
	getline(cin, s);
	return 0;
}