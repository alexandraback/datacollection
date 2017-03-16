#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int n, t;

	cin >> t;
	for(int tt=1; tt<=t; ++tt)
	{
		string s;
		cin >> n >> s;
		int has = 0, res = 0;
		for(int i=0; i<=n; ++i)
		{
			int curr = s[i] - '0';
			has += curr;
			--has;
			if(has < 0)
			{
				++has;
				++res;
			}
		}
		
		cout << "Case #" << tt << ": " << res << "\n";
	}

	return 0;
}
