#include <bits/stdc++.h>
using namespace std;

struct quat
{
	int typ;
	bool neg;
	quat() : typ(0), neg(false) { }
	quat(char c)
	{
		typ = 0;
		if (c == 'i') typ = 1;
		if (c == 'j') typ = 2;
		if (c == 'k') typ = 3;
		neg = false;
	}
	void operator*= (const quat& oth)
	{
		if (typ == 0)
			typ = oth.typ;
		else if (typ == 1)
		{
			typ = (typ-oth.typ+4)&3;
			if (oth.typ&1)
				neg = !neg;
		} else if (typ == 2)
		{
			typ = (typ+oth.typ)&3;
			if (__builtin_popcount(oth.typ) == 1)
				neg = !neg;
		} else
		{
			typ = (typ-oth.typ+4)&3;
			if (oth.typ&2)
				neg = !neg;
		}
		if (oth.neg)
			neg = !neg;
	}
	bool operator!= (const int x)
	{
		if (typ) return true;
		if (neg) return (x != -1);
		return (x != 1);
	}
	bool operator== (const quat& oth)
	{
		if (typ != oth.typ) return false;
		if (neg) return oth.neg;
		return !oth.neg;
	}
};

quat period[4];
char buf[10005];
int l;
long long x;
int t;

bool attempt(const quat& want, int& from, long long& use, bool pre=true)
{
	quat have;
	for (;from < l;from++)
	{
		if (pre)
			have *= quat(buf[from]);
		else
		{
			quat tmp(have);
			have = quat(buf[from]);
			have *= tmp;
		}
		if (have == want)
			return true;
	}
	for (int i = 0;i < 4;i++)
	{
		use++;
		for (from = 0;from < l;from++)
		{
			if (pre)
				have *= quat(buf[from]);
			else
			{
				quat tmp(have);
				have = quat(buf[from]);
				have *= tmp;
			}
			if (have == want)
				return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		scanf("%d%I64d%s", &l, &x, buf);
		period[1] = quat();
		for (int i = 0;i < l;i++)
			period[1] *= quat(buf[i]);
		for (int i = 2;i < 5;i++)
		{
			period[i&3] = period[(i+3)&3];
			period[i&3] *= period[1];
		}
		printf("Case #%d: ", _);
		if (period[x&3ll] != -1)
		{
			printf("NO\n");
			continue;
		}
		int from = 0; long long use = 0;
		bool success = attempt(quat('i'), from, use);
		if (!success)
		{
			printf("NO\n");
			continue;
		}
		reverse(buf, buf+l);
		int from2 = 0;
		success = attempt(quat('k'), from2, use, false);
		from2 = l - from2 - 1;
		use++;
		if (from >= from2)
			use++;
		if (!success)
		{
			printf("NO\n");
			continue;
		}
		if (use > x)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
