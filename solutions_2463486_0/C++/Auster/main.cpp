#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

vector<string> S;

int n;

char buf[1 << 7];

void sq(string & s)
{
	reverse(s.begin(), s.end());
	string res(2 * s.size(), '0');
	for(int i = 0; i < s.size(); ++i)
		for(int j = 0; j < s.size(); ++j)
			res[i + j] += (s[i] - '0') * (s[j] - '0');
	reverse(res.begin(), res.end());
	int pos = 0;
	while (res[pos] == '0')
		++pos;
	res = res.substr(pos);
	s = res;
}

void go(int pos, int s)
{
	if (pos >= (n + 1) / 2)
	{
		if (s < 9)
		{
			string ss(buf);
			sq(ss);
			S.push_back(ss);
		}
		return;
	}
	if (n - pos - 1 == pos)
	{
		if (s < 9)
		{
			buf[pos] = '0';
			go(pos + 1, s);
		}
		if (s >= 1)
		{
			buf[pos] = '1';
			go(pos + 1, s - 1);
		}
		if (s >= 4)
		{
			buf[pos] = '2';
			go(pos + 1, s - 4);
		}
		if (s >= 9)
		{
			buf[pos] = '3';
			go(pos + 1, s - 9);
		}
	}
	else
	{
		if (s < 9)
		{
			buf[pos] = '0';
			buf[n - pos - 1] = '0';
			go(pos + 1, s);
		}
		if (s >= 2)
		{
			buf[pos] = '1';
			buf[n - pos - 1] = '1';
			go(pos + 1, s - 2);
		}
		if (s >= 8)
		{
			buf[pos] = '2';
			buf[n - pos - 1] = '2';
			go(pos + 1, s - 8);
		}
	}
}

int ok(LL x)
{
	sprintf(buf, "%lld", x);
	int res = 1;
	for(int i = 0, j = strlen(buf) - 1; i < j; i++, j--)
		res &= buf[i] == buf[j];
	return res;
}

bool cmp(const string & a, const string & b)
{
	if (a.size() != b.size())
		return a.size() < b.size();
	for(int i = 0; i < a.size(); ++i)
		if (a[i] != b[i])
			return a[i] < b[i];
	return 0;
}

void dec(string & s)
{
	int pos = s.size() - 1;
	while (pos >= 0 && s[pos] == '0')
		pos--;
	s[pos]--;
	for(int i = s.size() - 1; i > pos; --i)
		s[i] = '9';
	if (s[0] == '0' && s.size() > 1)
		s = s.substr(1);
}

int pos(const string & A)
{
	int L = 0, R = S.size();
	while (R - L > 1)
	{
		int M = (L + R) / 2;
		if (cmp(A, S[M]))
			R = M;
		else
			L = M;
	}
	return L;
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	memset(buf, 0, sizeof(buf));
	S.push_back("0");
	for(n = 1; n <= 51; ++n)
		go(0, 9);
	sort(S.begin(), S.end(), cmp);
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		scanf("%s", buf);
		string A(buf);
		scanf("%s", buf);
		string B(buf);
		dec(A);
		printf("%d\n", pos(B) - pos(A));
	}
	return 0;
}