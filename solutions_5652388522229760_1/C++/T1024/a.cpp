#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int t;

	cin >> t;
	for(int tt=1; tt<=t; ++tt)
	{
		int n;
		cin >> n;
		map<int,int> m;

		int i = 1;
		for(i=1; i<999; ++i)
		{
			int x = i*n;
			while(x)
			{
				m[x%10]++;
				x/=10;
			}
			if(m.size() == 10)
				break;
		}

		int ans = i*n;

		if(m.size() != 10)
			cout << "Case #" << tt << ": " << "INSOMNIA" << "\n";
		else
			cout << "Case #" << tt << ": " << ans << "\n";
		cout.flush();
	}

	return 0;
}
