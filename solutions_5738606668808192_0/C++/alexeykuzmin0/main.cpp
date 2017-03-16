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
	int n, j;

	friend istream& operator >> (istream& lhs, Input& rhs)
	{
		return lhs >> rhs.n >> rhs.j;
	}
};

struct Output
{
	vector<pair<string, vector<int>>> coins;

	friend ostream& operator << (ostream& lhs, const Output& rhs)
	{
		static int case_number = 0;
		lhs << "Case #" << ++case_number << ":" << endl;
		for (auto& coin : rhs.coins)
		{
			lhs << coin.first;
			for (auto d : coin.second)
			{
				lhs << ' ' << d;
			}
			lhs << endl;
		}
		return lhs;
	}
};

Output solve(Input input)
{
	Output ans;
	mutex ans_mutex;
	long long baseline = 1LL << (input.n - 1);
	queue<future<void>> tasks;
	long long cur = baseline + 1;
	while ((int)ans.coins.size() < input.j)
	{
		if (tasks.size() > 20)
		{
			tasks.front().get();
			tasks.pop();
		}
		tasks.push(async([&ans_mutex, &ans, &input, cur]()
		{
			string s;
			long long c = cur;
			while (c > 0)
			{
				s.push_back('0' + c % 2);
				c /= 2;
			}
			reverse(s.begin(), s.end());
			vector<int> div;
			for (int base = 2; base < 11; ++base)
			{
				int i;
				for (i = 2; i < 10 * 1000; ++i)
				{
					int mod = 0;
					for (char c : s)
					{
						mod = (mod * base + (c - '0')) % i;
					}
					if (mod == 0)
					{
						div.push_back(i);
						break;
					}
				}
				if (i == 10000)
				{
					return;
				}
			}
			ans_mutex.lock();
			if ((int)ans.coins.size() < input.j)
			{
				ans.coins.emplace_back(s, div);
			}
			ans_mutex.unlock();
		}));
		cur += 2;
	}
	return ans;
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