#include <bits/stdc++.h>

using namespace std;

struct UserA
{
	int n;
	vector<int> arr;

	friend istream& operator >> (istream& kk, UserA& tt)
	{
		kk >> tt.n;
		for (int i = 0; i < tt.n; ++i)
		{
			int x;
			kk >> x;
			tt.arr.push_back(x - 1);
		}
		return kk;
	}
};

struct UserB
{
	int solution;

	friend ostream& operator << (ostream& kk, const UserB& tt)
	{
		static int tcc = 0;
		return kk << "Case #" << ++tcc << ": " << tt.solution << endl;
	}
};

bool check(vector<int> arr, vector<int> carr)
{
	for (int i = 0; i < (int)carr.size(); ++i)
	{
		int before = (i + carr.size() - 1) % carr.size();
		int next = (i + 1) % carr.size();
		if (arr[carr[i]] != carr[next] &&
			arr[carr[i]] != carr[before])
		{
			return false;
		}
	}
	return true;
}

class CCa
{
public:
	int operator()(const vector<int> & kk, const vector<int> & tt)
	{
		return kk.size() > tt.size();
	}
};

UserB solve(UserA input)
{
	int solution = 0;
	vector<set<vector<int>, CCa>> vs(input.n, set<vector<int>, CCa>());
	for (int i = 0; i < input.n; ++i)
	{
		int swqq = i;
		int before = -1;
		vector<bool> used(input.n, false);
		used[swqq] = true;
		int sizeL = 1;
		vector<int> c;
		c.push_back(swqq);
		while (!used[input.arr[swqq]])
		{
			++sizeL;
			before = swqq;
			swqq = input.arr[swqq];
			c.push_back(swqq);
			used[swqq] = true;
		}
		if (before == input.arr[swqq])
		{
			vs[before].insert(c);
		}
		else
		{
			sizeL = 1;
			for (int cc = input.arr[swqq]; cc != swqq; cc = input.arr[cc])
			{
				++sizeL;
			}
		}
		solution = max(solution, sizeL);
	}
	int sizeL = 0;
	vector<bool> used(input.n, false);
	for (int i = 0; i < input.n; ++i)
	{
		if (!used[i] && !vs[i].empty())
		{
			sizeL += vs[i].begin()->size();
			if (!vs[input.arr[i]].empty())
			{
				used[input.arr[i]] = true;
				sizeL += vs[input.arr[i]].begin()->size() - 2;
			}
		}
	}
	solution = max(solution, sizeL);
	return{ solution };
}

int main(int argc, char* argv[])
{
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	int t;
	fin >> t;
	int ready = 0;
	vector<xsystem<UserB>> tasks;
	mutex cout_mutex;
	for (int i = 0; i < t; ++i)
	{
		UserA input;
		fin >> input;
		tasks.push_back(async([&ready, &t, &cout_mutex](UserA input)
		{
			auto solution = solve(input);
			return solution;
		}, input));
	}
	for (auto& task : tasks)
	{
		fout << task.get();
	}
	return 0;
}