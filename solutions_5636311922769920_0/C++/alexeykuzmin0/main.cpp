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

using namespace std;

struct Input
{
	int k, c, s;

	friend istream& operator >> (istream& lhs, Input& rhs)
	{
		return lhs >> rhs.k >> rhs.c >> rhs.s;
	}
};

struct Output
{
	vector<int> ans;

	friend ostream& operator << (ostream& lhs, const Output& rhs)
	{
		static int case_number = 0;
		lhs << "Case #" << ++case_number << ":";
		for (auto& x : rhs.ans)
		{
			lhs << ' ' << x;
		}
		return lhs << endl;
	}
};

Output solve(Input input)
{
	vector<int> ans;
	for (int i = 0; i < input.k; ++i)
	{
		ans.push_back(i + 1);
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