#include <bits/stdc++.h>
using namespace std;

int tt;
long long s1, s2, rs1 ,rs2, d;
string a, b;

void update(long long s1, long long s2)
{
	if(abs(s1 - s2) < d)
		{
			d = abs(s1 - s2);
			rs1 = s1; rs2 = s2;
			//cout << d << " " << s1 << " " << s2 << "\n";
		}
		else
		if(abs(s1 - s2) == d)
		{
			if(s1 < rs1)
			{
				rs1 = s1; rs2 = s2;
			}
			else
				if(s1 == rs1 && s2 < rs2)
				{
					rs1 = s1; rs2 = s2;
				}
		}
}

void process(int i, int x, long long s1, long long s2)
{
	if(x == 1)
	{
		for(int j = i; j < a.length(); j++)
		{
			char ch1 = a[j];
			char ch2 = b[j];
			if(a[j] == '?') ch1 = '9';
			if(b[j] == '?') ch2 = '0';
			s1 = s1*10 + ch1 - '0';
			s2 = s2*10 + ch2 - '0';
		}
		update(s1, s2);
	}
	else
	{
		for(int j = i; j < a.length(); j++)
		{
			char ch1 = a[j];
			char ch2 = b[j];
			if(a[j] == '?') ch1 = '0';
			if(b[j] == '?') ch2 = '9';
			s1 = s1*10 + ch1 - '0';
			s2 = s2*10 + ch2 - '0';
		}
		update(s1, s2);
	}
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> tt;
	for(int t = 1; t <= tt; t++)
	{
		cin >> a >> b;
		//cout << a << " " << b << "\n";
		s1 = 0; s2 = 0; d = 1000000000000000000;
		int i = 0;
		while(i < a.length() && (a[i] == '?' || b[i] == '?' || a[i] == b[i]))
		{
			//cout <<i << " " << s1 << " " << s2 << "dd\n";
			if(a[i] == '?' || b[i] == '?')
			{
				if(a[i] == '?' && b[i] == '?')
				{
					process(i + 1, 1, s1*10, s2*10 + 1);
					process(i + 1, 0, s1*10 + 1, s2*10);
				}
				else
				if(a[i] == '?')
				{
					if(b[i] != '0')
						process(i + 1, 1, s1*10 + b[i] - '1', s2*10 + b[i] - '0');
					if(b[i] != '9')
						process(i + 1, 0, s1*10 + b[i] - '0' + 1, s2*10 + b[i] - '0');
				}
				else
				{
					if(a[i] != '9')
						process(i + 1, 1, s1*10 + a[i] - '0', s2*10 + a[i] - '0' + 1);
					if(a[i] != '0')
						process(i + 1, 0, s1*10 + a[i] - '0', s2*10 + a[i] - '1');
				}
			}
			else
				if(a[i] != b[i])
					process(i + 1, b[i] > a[i], s1*10 + a[i] - '0', s2*10 + b[i] - '0');
				if(a[i] == '?' && b[i] == '?') 
					{
						a[i] = '0'; b[i] = '0';
					}
				else
				{
					if(b[i] == '?') b[i] = a[i];
					if(a[i] == '?') a[i] = b[i];
				}
				s1 = s1*10 + a[i] - '0';
				s2 = s2*10 + b[i] - '0';
			i++;
		}
		//cout << i;
		if(i >= a.length())
			update(s1, s2);
		else process(i + 1, b[i] > a[i], s1*10 + a[i] - '0', s2*10 + b[i] - '0');
		cout << "Case #" << t << ": " << setw(a.length()) << setfill('0') << rs1 << " " << setw(a.length()) << setfill('0') << rs2 << "\n";
	}
	return 0;
}