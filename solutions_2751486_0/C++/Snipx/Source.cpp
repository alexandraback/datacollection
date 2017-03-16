# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <math.h>
# include <algorithm>
# include <string.h>
# include <stack>
# include <queue>
# include <sstream>
# include <set>
# include <map>
# include <assert.h>
using namespace std;

bool is1(char ch)
{
	return ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u';
}

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");

	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++)
	{
		string s;
		cin >> s;
		int n;
		cin >> n;
		int l = s.length();
		vector<int> f(l, 0);
		if (is1(s[l - 1]))
			f[l - 1] = 1;
		for (int i = l - 2; i >= 0; i--)
			if (is1(s[i]))
				f[i] = f[i + 1] + 1;
			else
				f[i] = 0;

		deque<int> ok;
		for (int i = 0; i < l; i++)
			if (f[i] >= n)
				ok.push_back(i);
		long long ans = 0;
		for (int i = 0; i < l; i++)
		{
			while (ok.size() > 0 && ok[0] < i)
				ok.pop_front();
			if (f[i] >= n)
				ans += (l - 1) - (i + n - 1) + 1;
			else
				if (ok.size() > 0)
				{
					int ind = ok[0] + n - 1;
					ans += (l - 1) - ind + 1;
				}
		}

		cout << "Case #" << test + 1 << ": " << ans << endl;
	}
    
    //system("pause");
    return 0;
}
