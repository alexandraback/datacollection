#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

string ss[10];
bool used [26];
int a[10];

int main()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	int t;
	scanf ("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		int ans = 0;
		int n;
		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
		{
			cin >> ss[i];
			a[i] = i;
		}
		do {
			string total = "";
			for (int i = 0; i < n; i++)
				total += ss[a[i]];
			for (int i = 0; i < 26; i++)
				used[i] = false;
			bool f = true;
			for (int i = 0; i < total.length(); i++)
			{
				if (!used[total[i] - 'a'])
					used[total[i] - 'a'] = true;
				else
					if (total [i - 1] != total[i])
						f = false;
				if (f == false)
					break;
			}
			if (f)
				ans++;
		} while (next_permutation (a, a + n));
		printf ("Case #%d: %d\n", tt + 1, ans);
	}
	return 0;
}
