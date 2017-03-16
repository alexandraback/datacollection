#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

typedef long long ll;

const ll mod = 1000 * 1000 * 1000 + 7;
const int nmax = 1000 * 100;

int n, top, answ = 0, ans[nmax], was[nmax];
bool used[nmax];
string s1, s[nmax];

void gen(int i)
{
	if (i == top)
	{
		bool f = true;
		string s2 = "";
		for (int j = 0; j < top; j++)
			s2 += s[ans[j]];
		for (int j = 0; j < 26; j++)
			was[j] = -1;
		for (int j = 0; j < s2.length(); j++)
			if (was[s2[j] - 'a'] == -1)
				was[s2[j] - 'a'] = j;
			else if (was[s2[j] - 'a'] != j - 1)
				f = false;
			else
				was[s2[j] - 'a'] = j;
		if (f)
		{
			answ++;
		}
	}
	else
	{
		for (int j = 0; j < top; j++)
		{
			if (!used[j])
			{
				used[j] = true;
				ans[i] = j;
				gen(i + 1);
				used[j] = false;
			}
		}
	}
}

int main()
{
	cin >> n;
	getline(cin, s1);
	for (int q = 0; q < n; q++)
	{
		int zz;
		cin >> zz;
		for (int i = 0; i < zz; i++)
			cin >> s[i];
		answ = 0;
		top = zz;
		cout << "Case #" << q + 1 << ": ";
		gen(0);
		cout << answ << endl;
	}
}
