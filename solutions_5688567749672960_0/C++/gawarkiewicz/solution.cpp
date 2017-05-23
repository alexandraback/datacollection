#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <tuple>

using namespace std;

long long rev(long long num)
{
	long long ret = 0;
	while (num)
	{
		ret = ret * 10 + (num % 10);
		num /= 10;
	}
	return ret;
}

map<long long, int> brute()
{
	map<long long, int> m;
	queue<tuple<long long, int>> q;
	q.push(make_tuple(1, 1));
	m[1] = 1;
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		if (get<1>(p) > 10000)
			continue;
		auto n = get<0>(p);
		auto c = get<1>(p);
		auto n1 = n + 1;
		auto n2 = rev(n);
		if (m[n1] == 0)
		{
			m[n1] = c + 1;
			q.push(make_tuple(n1, c + 1));
		}
		if (m[n2] == 0)
		{
			m[n2] = c + 1;
			q.push(make_tuple(n2, c + 1));
		}
	}
	return m;
}

void learn()
{
	auto m = brute();
	cout << m.rbegin()->first << endl; // max
	long long allTo = 0;
	for (auto& p : m)
	{
		if (p.first != allTo + 1) break;
		allTo++;
	}
	cout << allTo << endl;
	/*
	vector<pair<int, long long>> m2;
	for (auto& p : m)
	{
		m2.push_back(make_pair(p.second, p.first));
	}
	sort(m2.begin(), m2.end());

	for (auto& p : m2)
	{
		cout << p.first << " " << p.second << endl;
	}*/
}

int main()
{
	//learn();
	auto m = brute();

	int N;
	cin >> N;
	for (int q = 1; q <= N; ++q)
	{
		long long T;
		cin >> T;
		cout << "Case #" << q << ": " << m[T] << endl;
	}
	return 0;
}