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

const vector<string> digits{ "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
const vector<pair<char, char>> names{	{'Z', '0'},
										{'W', '2'},
										{'U', '4'},
										{'X', '6'},
										{'G', '8'},
										{'O', '1'},
										{'T', '3'},
										{'F', '5'},
										{'S', '7'},
										{'N', '9'} };

struct Input
{
	string s;

	friend istream& operator >> (istream& lhs, Input& rhs)
	{
		return lhs >> rhs.s;
	}
};

struct Output
{
	string s;

	friend ostream& operator << (ostream& lhs, const Output& rhs)
	{
		static int case_number = 0;
		return lhs << "Case #" << ++case_number << ": " << rhs.s << endl;
	}
};

Output solve(Input input)
{
	string ans;
	vector<int> counts(256, 0);
	for (char c : input.s)
	{
		++counts[c];
	}
	for (auto p : names)
	{
		while (counts[p.first] > 0)
		{
			ans += p.second;
			for (char c : digits[p.second - '0'])
			{
				--counts[c];
			}
		}
	}
	sort(ans.begin(), ans.end());
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