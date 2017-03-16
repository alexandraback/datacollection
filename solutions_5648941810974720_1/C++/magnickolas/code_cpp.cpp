#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, N) for (decltype(N) i = 0; i < N; i++)
#define dep(i, N) for (decltype(N) i = N - 1; i >= 0; i--)
#define FOR(i, A, B) for (decltype(B) i = A; i <= B; i++)
#define FORD(i, A, B) for (decltype(A) i = A; i >= B; i--)
#define len(A) (int)A.size()
#define all(A) A.begin(), A.end()

typedef long long int64;
typedef unsigned long long uint64;
typedef long double ld;


using namespace std;

template<typename T>
T sqr(const T &a)
{
	return a * a;
}
map<string, string> m;
vector<string> cur;
string nm;
vector<string> q = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

int main()
{
	ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	rep(t, T)
	{
		cout << "Case #" << t + 1 << ": ";
		string s;
		cin >> s;
		multiset<char> v;
		for (auto &c : s)
			v.insert(c);
		string res = "";
		while (v.count('Z'))
		{
			for (auto &c : q[0])
				v.erase(v.find(c));
			res += '0';
		}
		while (v.count('W'))
		{
			for (auto &c : q[2])
				v.erase(v.find(c));
			res += '2';
		}
		while (v.count('X'))
		{
			for (auto &c : q[6])
				v.erase(v.find(c));
			res += '6';
		}
		while (v.count('S'))
		{
			for (auto &c : q[7])
				v.erase(v.find(c));
			res += '7';
		}
		while (v.count('G'))
		{
			for (auto &c : q[8])
				v.erase(v.find(c));
			res += '8';
		}
		while (v.count('V'))
		{
			for (auto &c : q[5])
				v.erase(v.find(c));
			res += '5';
		}
		while (v.count('T'))
		{
			for (auto &c : q[3])
				v.erase(v.find(c));
			res += '3';
		}
		while (v.count('R'))
		{
			for (auto &c : q[4])
				v.erase(v.find(c));
			res += '4';
		}
		while (v.count('I'))
		{
			for (auto &c : q[9])
				v.erase(v.find(c));
			res += '9';
		}
		while (!v.empty())
		{
			for (auto &c : q[1])
				v.erase(v.find(c));
			res += '1';
		}
		sort(all(res));
		cout << res << endl;
	}
	return 0;
}