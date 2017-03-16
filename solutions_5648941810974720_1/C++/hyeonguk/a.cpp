#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <cctype>
#include <functional>
#include <future>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

string nums[] = {"ZERO", "ONE", "TWO", "THREE",
	"FOUR", "FIVE", "SIX", "SEVEN",
	"EIGHT", "NINE"};

struct TestCase
{
	string data;
	vector<int> answer;

	void input()
	{
		cin >> data;
	}
	void process()
	{
		vector<int> cnt(128);
		for (int i = 0; i < data.size(); i++)
		{
			cnt[data[i]]++;
		}
		auto check = [&](char feature, int num)
		{
			while (cnt[feature] > 0)
			{
				for (int i = 0; i < nums[num].size(); i++)
				{
					cnt[nums[num][i]]--;
				}
				answer.push_back(num);
			}
		};
		check('Z', 0);
		check('W', 2);
		check('G', 8);
		check('T', 3);
		check('X', 6);
		check('S', 7);
		check('V', 5);
		check('F', 4);
		check('O', 1);
		check('N', 9);

		sort(answer.begin(), answer.end());
	}
	void output()
	{
		for (const auto &i : answer)
		{
			cout << i;
		}
	}
};

int main()
{
	int t;
	cin >> t;

	vector<TestCase> tc(t);
	vector<future<void>> f;
	for (int i = 0; i < t; i++) tc[i].input();
	for (int i = 0; i < t; i++)
		f.push_back(async(launch::async,
			[&](int p){ tc[p].process(); }, i));
	// for (int i = 0; i < t; i++) f[i].wait();
	for (int i = 0; i < t; i++)
	{
		f[i].wait();
		cout << "Case #" << i + 1 << ": ";
		tc[i].output();
		cout << endl;
	}
	return 0;
}
