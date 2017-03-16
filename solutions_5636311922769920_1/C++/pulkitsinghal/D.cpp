#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int test=1;test<=t;++test)
	{
		int k,c,s;
		cin >> k >> c >> s;
		cout << "Case #" << test << ": ";
		if(s<k)
			cout << "IMPOSSIBLE";
		else
			for(int i=1;i<=s;++i)
				cout << i << " ";
		cout << endl;
	}
	return 0;
}
