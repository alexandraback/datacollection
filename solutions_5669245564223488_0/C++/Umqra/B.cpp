#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

bool used[100];
string str[1000];
int perm[1000];

int main()
{
	int t;
	scanf("%d", &t);
	for (int x = 0; x < t; x++)
	{
		cerr << x << endl;
		int n;
		scanf("%d", &n);
		for (int s = 0; s < n; s++)
			cin >> str[s];
		
		for (int s = 0; s < n; s++)
			perm[s] = s;
		int ans = 0;
		while (1)
		{
			string res = "";
			for (int s = 0; s < n; s++)
				res += str[perm[s]];
			char lst = -1;
			fill(used, used + 100, 0);
			bool ok = true;
			for (int s = 0; s < (int)res.length(); s++)
			{
				int c = res[s] - 'a';
				if (used[c] && lst != c)
				{
					ok = false;
					break;
				}
				lst = c;
				used[c] = 1;
			}
			if (ok)
				ans++;
			if (!next_permutation(perm, perm + n))
				break;
			
		}
		printf("Case #%d: %d\n", x + 1, ans);
	}
	return 0;
}