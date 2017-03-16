#define _CRT_SECURE_NO_WARNINGS
#include <ios>
#include <iostream>
#include <sstream>
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
	string s1, s2;

	friend istream& operator >> (istream& lhs, Input& rhs)
	{
		return lhs >> rhs.s1 >> rhs.s2;
	}
};

struct Output
{
	string s1, s2;

	friend ostream& operator << (ostream& lhs, const Output& rhs)
	{
		static int case_number = 0;
		return lhs << "Case #" << ++case_number << ": " << rhs.s1 << ' ' << rhs.s2 << endl;
	}
};

bool match(int x, string p)
{
	for (int i = p.size() - 1; i > -1; --i)
	{
		if ((x % 10) != (p[i] - '0') && p[i] != '?')
		{
			return false;
		}
		x /= 10;
	}
	return true;
}

Output solve(Input input)
{
	int x1 = 0, x2 = 999;
	for (int i = 0; i < 1000; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			if (match(i, input.s1) && match(j, input.s2) && abs(i - j) < abs(x1 - x2))
			{
				x1 = i;
				x2 = j;
			}
		}
	}
	stringstream ss1;
	ss1 << x1;
	stringstream ss2;
	ss2 << x2;
	string s1, s2;
	ss1 >> s1;
	ss2 >> s2;
	while (s1.size() < input.s1.size())
	{
		s1 = '0' + s1;
	}
	while (s2.size() < input.s2.size())
	{
		s2 = '0' + s2;
	}
	return{ s1, s2 };
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