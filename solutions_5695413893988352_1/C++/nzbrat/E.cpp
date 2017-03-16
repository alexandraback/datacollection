# include <cstdio>
# include <cmath>
# include <cstring>
# include <string>
# include <vector>
# include <queue>
# include <map>
# include <iostream>
# include <algorithm>

using namespace std;

string a, b;
string oa, ob;

long long diff = (1LL << 62), ansA, ansB;

void go (int idx, long long A, long long B)
{
	if (idx == 18)
	{
		long long ab;
		ab = A - B;
		if (ab < 0)
			ab = -ab;
		if (ab > diff)
			return;
		if (ab < diff)
		{
			diff = ab;
			ansA = A;
			ansB = B;
			return;
		}
		if (A < ansA)
		{
			ansA = A;
			ansB = B;
			return;
		}
		if (A == ansA && B < ansB)
		{
			ansA = A;
			ansB = B;
			return;
		}
		return;
	}
	int ca = a[idx] - '0', cb = b[idx] - '0';
	if (A > B)
	{
		A *= 10;
		if (a[idx] != '?')
			A += ca;
		B *= 10;
		if (b[idx] != '?')
			B += cb;
		else
			B += 9;
		go (idx + 1, A, B);
		return;
	}
	if (A < B)
	{
		A *= 10;
		if (a[idx] != '?')
			A += ca;
		else
			A += 9;
		B *= 10;
		if (b[idx] != '?')
			B += cb;
		go (idx + 1, A, B);
		return;
	}
	
	if (a[idx] != '?' && b[idx] != '?')
	{
		A = A * 10 + ca;
		B = B * 10 + cb;
		go (idx + 1, A, B);
		return;
	}
	
	if (a[idx] == b[idx] && a[idx] == '?')
	{
		A *= 10;
		B *= 10;
		go (idx + 1, A, B);
		A ++;
		go (idx + 1, A, B);
		A --;
		B ++;
		go (idx + 1, A, B);
		return;
	}
	if (a[idx] == '?')
	{
		A *= 10;
		B *= 10;
		A += cb;
		B += cb;
		go (idx + 1, A, B);
		if (cb - 1 >= 0)
		{
			A --;
			go (idx + 1, A, B);
			A ++;
		}
		if (cb + 1 <= 9)
		{
			A ++;
			go (idx + 1, A, B);
			A --;
		}
		return;
	}
	if (b[idx] == '?')
	{
		A *= 10;
		B *= 10;
		A += ca;
		B += ca;
		go (idx + 1, A, B);
		if (ca - 1 >= 0)
		{
			B --;
			go (idx + 1, A, B);
			B ++;
		}
		if (ca + 1 <= 9)
		{
			B ++;
			go (idx + 1, A, B);
			B --;
		}
		return;
	}
}

int main ()
{
	int nt, t, as, bs, i;
	cin >> t;
	for (nt = 1; nt <= t; nt ++)
	{
		diff = (1LL << 62);
		cin >> a >> b;
		oa = a;
		ob = b;
		as = a.size ();
		bs = b.size ();
		for (i = 0; i < 18 - as; i ++)
			a = "0" + a;
		for (i = 0; i < 18 - bs; i ++)
			b = "0" + b;
		go (0, 0, 0);
		///cout << ansA << " " << ansB << "\n";
		for (i = as - 1; i >= 0; i --)
		{
			oa[i] = ansA % 10 + '0';
			ansA /= 10;	
		}
		for (i = bs - 1; i >= 0; i --)
		{
			ob[i] = ansB % 10 + '0';
			ansB /= 10;	
		}
		cout << "Case #" << nt << ": " << oa << " " << ob << "\n";
	}
	return 0;
}

