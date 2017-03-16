#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>

#define INF 2147483647
#define PI acos(-1.0)

using namespace std;

int main(int argc, const char ** argv)
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int t;
	cin >> t;

	for(auto tt = 1; tt <= t; ++tt)
	{
		int n;
		cin >> n;
		vector < pair <long long, long long> > A;
		for(int i = 0; i < n; ++i)
		{
			long long a, b, c;
			cin >> a >> b >> c;
			for(long long j = 0; j < b; ++j)
				A.push_back(make_pair(a, c + j));
		}

		int ans;
		if(A.size() == 1)
			ans = 0;
		else
		{
			if(A[0].second > A[1].second)
				swap(A[0], A[1]);

			if( (2l * A[0].second - A[1].second) * 360l + A[1].first * A[1].second - A[0].first * A[0].second > 0)
				ans = 0;
			else
				ans = 1;
		}

		cout << "Case #" << tt << ": " << ans << endl;
	}


	return 0;
}
