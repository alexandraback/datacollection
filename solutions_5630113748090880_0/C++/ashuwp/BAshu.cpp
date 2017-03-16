#include <bits/stdc++.h>

using namespace std;

struct Input
{
	int n;
	vector<vector<int>> pp;

	friend istream& operator >> (istream& lhs, Input& rhs)
	{
		lhs >> rhs.n;
		for (int i = 0; i < 2 * rhs.n - 1; ++i)
		{
			rhs.pp.emplace_back();
			for (int j = 0; j < rhs.n; ++j)
			{
				int x;
				lhs >> x;
				rhs.pp.back().push_back(x);
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
	vector<int> counts(5500, 0);
	vector<int> ans;
	for (auto& piece : input.pp)
	{
		for (auto& x : piece)
		{
			++counts[x];
		}
	}
	for (int i = 0; i < 5500; ++i)
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
			return ans;
		}, input));
	}
	for (auto& task : tasks)
	{
		fout << task.get();
	}
	return 0;
}