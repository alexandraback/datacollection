#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define mp make_pair

const int MAX = (int)1e6 + 5;
int dp[MAX+5];

int main()
{
	ios::sync_with_stdio(false);


	dp[1] = 1;
	for (int i = 2; i < MAX; i++)
	{
		string s = to_string(i);
		reverse(s.begin(), s.end());
	
		int rN = atoi(s.c_str());

		if(s[0] != '0' && rN < i)
			dp[i] = min(dp[i-1] + 1, dp[rN] + 1);
		else
			dp[i] = dp[i-1] + 1;
	}

	int TC;
	cin >> TC;

	for (int cases = 1; cases <= TC; cases++)
	{
		int N;
		cin >> N;

		cout << "Case #" << cases << ": ";
		cout << dp[N] << "\n";
	}
	
	return 0;
}