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
	int n;
	vector<vector<int>> pieces;

	friend istream& operator >> (istream& lhs, Input& rhs)
	{
		lhs >> rhs.n;
		for (int i = 0; i < 2 * rhs.n - 1; ++i)
		{
			rhs.pieces.emplace_back();
			for (int j = 0; j < rhs.n; ++j)
			{
				int x;
				lhs >> x;
				rhs.pieces.back().push_back(x);
			}
		}
		return lhs;
	}
};

struct Output
{
	vector<int> ans;

	friend ostream& operator << (ostream& lhs, const Output& rhs)
	{
		static int case_number = 0;
		lhs << "Case #" << ++case_number << ":";
		for (int x : rhs.ans)
		{
			lhs << ' ' << x;
		}
		return lhs << endl;
	}
};

Output solve(Input input)
{
	vector<int> counts(3500, 0);
	vector<int> ans;
	for (auto& piece : input.pieces)
	{
		for (auto& x : piece)
		{
			++counts[x];
		}
	}
	for (int i = 0; i < 3500; ++i)
	{
		if (counts[i] & 1)
		{
			ans.push_back(i);
		}
	}
	return{ ans };
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