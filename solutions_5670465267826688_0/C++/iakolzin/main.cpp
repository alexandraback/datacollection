#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

struct Q
{
	char let;
	int sgn;
	Q(char let = '1', int sgn = 1) : let(let), sgn(sgn) {}
	Q(const Q& x)
	{
		let = x.let;
		sgn = x.sgn;
	}
};

map <string, Q> table;

void fill()
{
	table["11"] = Q('1', 1);
	table["1i"] = Q('i', 1);
	table["1j"] = Q('j', 1);
	table["1k"] = Q('k', 1);
	table["i1"] = Q('i', 1);
	table["ii"] = Q('1', -1);
	table["ij"] = Q('k', 1);
	table["ik"] = Q('j', -1);
	table["j1"] = Q('j', 1);
	table["ji"] = Q('k', -1);
	table["jj"] = Q('1', -1);
	table["jk"] = Q('i', 1);
	table["k1"] = Q('k', 1);
	table["ki"] = Q('j', 1);
	table["kj"] = Q('i', -1);
	table["kk"] = Q('1', -1);
}

Q find_match(char a, char b)
{
	string s;
	s.push_back(a);
	s.push_back(b);
	return table[s];
}

Q operator *(const Q& left, const Q& right)
{
	Q res = find_match(left.let, right.let);
	res.sgn = res.sgn * left.sgn * right.sgn;
	return res;
}

bool operator != (const Q& left, const Q& right)
{
	return left.let != right.let || left.sgn != right.sgn;
}

bool operator == (const Q& left, const Q& right)
{
	return !(left != right);
}

bool operator < (const Q& left, const Q& right)
{
	return (left.let < right.let ? 1 : (left.let == right.let ? left.sgn < right.sgn : 0));
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	fill();
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		long long n, x;
		string s;
		cin >> n >> x >> s;
		Q now('1');
		for (int i = 0; i < n; i++)
			now = now * Q(s[i]);
		vector <Q> found(1, now);
		set <Q> was;
		was.insert(now);
		while (1)
		{
			Q cur = found.back() * now;
			if (was.count(cur))
				break;
			was.insert(cur);
			found.push_back(cur);
		}
		Q total = found[(x - 1) % found.size()];
		if (total != Q('1', -1))
		{
			cout << "Case #" << (t + 1) << ": NO" << endl;
			continue;
		}
		string str = s;
		for (int i = 0; i < 10; i++)
			str += s;
		int ipos = -1, kpos = -1;
		now = Q('1');
		for (int i = 0; i < str.length(); i++)
		{
			now = now * Q(str[i]);
			if (now == Q('i'))
			{
				ipos = i;
				break;
			}
		}

		now = Q('1');
		for (int i = str.length() - 1; i >= 0; i--)
		{
			now = Q(str[i]) * now;
			if (now == Q('k'))
			{
				kpos = str.length() - i;
				break;
			}
		}

		if (ipos == -1 || kpos == -1)
		{
			cout << "Case #" << (t + 1) << ": NO" << endl;
			continue;
		}

		if (ipos + 1 + kpos >= n * x)
		{
			cout << "Case #" << (t + 1) << ": NO" << endl;
			continue;
		}

		cout << "Case #" << (t + 1) << ": YES" << endl;
	}
}