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
	int j, p, s, k;

	friend istream& operator >> (istream& lhs, Input& rhs)
	{
		return lhs >> rhs.j >> rhs.p >> rhs.s >> rhs.k;
	}
};

struct Output
{
	vector<vector<int>> ans;

	friend ostream& operator << (ostream& lhs, const Output& rhs)
	{
		static int case_number = 0;
		lhs << "Case #" << ++case_number << ": " << rhs.ans.size() << endl;
		for (auto& v : rhs.ans)
		{
			lhs << v[0] + 1 << ' ' << v[1] + 1 << ' ' << v[2] + 1 << endl;
		}
		return lhs;
	}
};

struct rek
{
	vector<vector<int>> best;
	vector<vector<int>> cur;
	Input data;

	bool check()
	{
		map<pair<int, int>, int> q0, q1, q2;
		for (size_t i = 0; i < cur.size(); ++i)
		{
			++q2[{cur[i][0], cur[i][1]}];
			++q1[{cur[i][0], cur[i][2]}];
			++q0[{cur[i][1], cur[i][2]}];
		}
		for (auto& m : { q0, q1, q2 })
		{
			for (auto p : m)
			{
				if (p.second > data.k)
				{
					return false;
				}
			}
		}
		return true;
	}

	void solve(int pos = 0)
	{
		if (cur.size() > best.size())
		{
			best = cur;
		}
		if (pos == data.j * data.p * data.s)
		{
			return;
		}
		cur.push_back({ pos / (data.p * data.s), pos / data.s % data.p, pos % data.s });
		bool c = check();
		if (c)
		{
			solve(pos + 1);
		}
		if (!c || (data.p > data.k))
		{
			cur.pop_back();
			solve(pos + 1);
		}
	}
};

Output solve(Input input)
{
	rek r;
	r.data = input;
	r.solve();
	return{ r.best };
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