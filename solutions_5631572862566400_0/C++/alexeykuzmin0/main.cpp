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
	vector<int> bff;

	friend istream& operator >> (istream& lhs, Input& rhs)
	{
		lhs >> rhs.n;
		for (int i = 0; i < rhs.n; ++i)
		{
			int x;
			lhs >> x;
			rhs.bff.push_back(x - 1);
		}
		return lhs;
	}
};

struct Output
{
	int ans;

	friend ostream& operator << (ostream& lhs, const Output& rhs)
	{
		static int case_number = 0;
		return lhs << "Case #" << ++case_number << ": " << rhs.ans << endl;
	}
};

bool check(vector<int> bff, vector<int> circle)
{
	for (int i = 0; i < (int)circle.size(); ++i)
	{
		int prev = (i + circle.size() - 1) % circle.size();
		int next = (i + 1) % circle.size();
		if (bff[circle[i]] != circle[next] &&
			bff[circle[i]] != circle[prev])
		{
			return false;
		}
	}
	return true;
}

int solve(vector<int> bff, vector<int> circle)
{
	int ans = 0;
	if (check(bff, circle))
	{
		ans = (int)circle.size();
	}
	for (int x = 0; x < (int)bff.size(); ++x)
	{
		if (find(circle.begin(), circle.end(), x) == circle.end())
		{
			circle.push_back(x);
			ans = max(ans, solve(bff, circle));
			circle.pop_back();
		}
	}
	return ans;
}

Output solve(Input input)
{
	return{ solve(input.bff, vector<int>()) };
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