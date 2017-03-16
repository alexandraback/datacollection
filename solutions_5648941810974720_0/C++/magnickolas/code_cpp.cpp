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
void gen(int l)
{
	if (len(cur) > 0)
	{
		string t = "";
		for (auto &c : cur)
			t += c;
		sort(all(t));
		string nnm = nm;
		sort(all(nnm));
		m[t] = nnm;
	}
	rep(i, 10)
	{
		if (l + len(q[i]) <= 20)
		{
			cur.push_back(q[i]);
			nm += char('0' + i);
			gen(l + len(q[i]));
			cur.pop_back();
			nm.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	gen(0);
	int T;
	cin >> T;
	rep(t, T)
	{
		cout << "Case #" << t + 1 << ": ";
		string s;
		cin >> s;
		sort(all(s));
		cout << m[s] << endl;
	}
	return 0;
}