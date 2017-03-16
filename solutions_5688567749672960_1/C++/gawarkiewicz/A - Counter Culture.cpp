#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
#include <string>
#include <sstream>
#include <algorithm>

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
		if (get<1>(p) > 100) //10000)
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

int b2(long long search)
{
	map<long long, int> m;
	queue<tuple<long long, int>> q;
	q.push(make_tuple(1, 1));
	m[1] = 1;
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		auto n = get<0>(p);
		auto c = get<1>(p);
		if (n == search) return c;
		if (n == m.begin()->first)
		{
			long long k = -1;
			for (auto& p : q._Get_container())
			{
				if (k == -1 || k > get<0>(p)) k = get<0>(p);
			}
			if (k > m.begin()->first)
				m.erase(m.begin(), m.lower_bound(k - 1));
		}
		//		if (get<1>(p) > 100) //10000)
		//			continue;
		auto n1 = n + 1;
		auto n2 = rev(n);
		if (n1 <= search && m[n1] == 0)
		{
			m[n1] = c + 1;
			q.push(make_tuple(n1, c + 1));
		}
		if (n2 <= search && n2 > n && m[n2] == 0)
		{
			m[n2] = c + 1;
			q.push(make_tuple(n2, c + 1));
		}
	}
}

string s(long long l)
{
	stringstream ss;
	ss << l;
	return ss.str();
}

long long l(string s)
{
	long long ret;
	stringstream ss(s);
	ss >> ret;
	return ret;
}

long long b3(long long search)
{
	if (search < 20) return search;
	if (search < 1000) return b2(search);
	long long t = 10;
	long long ret = 10;
	long long a = 1, b = 9;
	while (t*10 <= search)
	{
		if (a < b * 10 + 9) a *= 10;
		else b = b * 10 + 9;
		t *= 10;
		ret += a + b;
		//cout << t << " " << ret << endl;
	}
	if (search == t) return ret;

	int len = s(search).length();
	if (len % 2 == 0)
	{
		auto r1 = s(search).substr(0, len / 2);
		auto r2 = s(search).substr(len / 2);
		int a = 0;
		if (r2.back() == '0')
		{
			a = 1;
			--search;
			r1 = s(search).substr(0, len / 2);
			r2 = s(search).substr(len / 2);
		}
		reverse(r1.begin(), r1.end());
		ret = ret + a + min(search - t, l(r1) + 1 + l(r2) - 1);
	}
	else
	{
		auto r1 = s(search).substr(0, len / 2);
		auto r2 = s(search).substr(len / 2);
		auto r1b = s(search).substr(0, len / 2+1);
		auto r2b = s(search).substr(len / 2 + 1);
		int a = 0;
		if (r2.back() == '0')
		{
			a = 1;
			--search;
			r1 = s(search).substr(0, len / 2);
			r2 = s(search).substr(len / 2);
			++search;
		}
		reverse(r1.begin(), r1.end());

		long long ret1 = ret + a + min(search-a - t, l(r1) + 1 + l(r2) - 1);

		int ab = 0;
		if (r2b.back() == '0')
		{
			ab = 1;
			--search;
			r1b = s(search).substr(0, len / 2+1);
			r2b = s(search).substr(len / 2+1);
		}
		reverse(r1b.begin(), r1b.end());
		long long ret2 = ret + ab + min(search - t, l(r1b) + 1 + l(r2b) - 1);

		ret = min(ret1, ret2);
	}

	return ret;
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
	
	vector<pair<int, long long>> m2;
	for (auto& p : m)
	{
		m2.push_back(make_pair(p.second, p.first));
	}
	sort(m2.begin(), m2.end());

	for (auto& p : m2)
	{
		cout << p.first << " " << p.second << endl;
	}
}

int main()
{
//	learn();
//	auto m = brute();

	int N;
	cin >> N;
	for (int q = 1; q <= N; ++q)
	{
		long long T;
		cin >> T;
		cout << "Case #" << q << ": " << b3(T) << endl;
	}
	return 0;
}