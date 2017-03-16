
#include <iostream>
#include <string>

using namespace std;

bool vow(const char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool is(const string &s, int start, int end)
{
	for (int i = start; i < end; i++) if (vow(s[i])) return false;
	return true;
}

struct res
{
	long long cnt;
	int starts, ends;

	res(long long c, int s, int e)
	{
		cnt = c;
		starts = s;
		ends = e;
	}
};

res count(const string &s, int n, int len)
{
	if (len < n) return res(0, 0, 0);
	if (len == n) return is(s, 0, n) ? res(1,1,1) : res(0,0,0);

	res r = count(s, n, len-1);
	r.cnt += r.ends;

	if (is(s, len-n, len))
	{
		r.cnt += len - n + 1 - r.ends;
		r.ends += len - n + 1 - r.ends;
		r.starts++;
	}

	//cout << "for len = " << len << ", count = " << r.cnt << " and s/e = " << r.starts << ' ' << r.ends << endl;

	return r;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		string s;
		int n;
		cin >> s >> n;

		cout << "Case #" << t << ": " << count(s, n, s.length()).cnt << endl;
	}

	return 0;
}

