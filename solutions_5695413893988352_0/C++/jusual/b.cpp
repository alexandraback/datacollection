#include <bits/stdc++.h>

using namespace std;

int i, j, t, k, n, a, b;
string s[2];

int match(int x, int f)
{
	for (int i = s[f].length() - 1; i >= 0; i--) {
		if (s[f][i] - '0' != x % 10 && s[f][i] != '?')
			return 0;
		x /= 10;
	}
	return 1;
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.ans", "w", stdout);
	
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
	
		cin >> s[0] >> s[1];
		
		a = 10000;
		b = 0;
		
		n = 10;
		if (s[0].length() == 2)
			n = 100;
		else if (s[0].length() == 3)
			n = 1000;
		
		for (j = 0; j < n; j++) {
			if (match(j, 0))
				for (k = 0; k < n; k++)
					if (match(k, 1))
						if (abs(j - k) < abs(a - b)) {
							a = j;
							b = k;
						}
		}
		
		cout.width(0);
		cout << "Case #" << i + 1 << ": ";
		cout.width(s[0].length());
		cout.fill('0');
		cout << a << " ";
		cout.width(s[0].length());
		cout.fill('0');
		cout << b << endl;
	}
	
	return 0;
}