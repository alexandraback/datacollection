#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <functional>
 
#pragma comment(linker, "/STACK:134217728")
 
using namespace std;

int f(int n)
{
	int res = 0;
	while(n > 0)
	{
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}
int dp[1000100];

int main() {   
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	dp[0] = 0;
	for(int i=1; i<=1000000; i++) {
		dp[i] = dp[i-1] + 1;
		if(i <= 10 || !(i % 10)) dp[i] = dp[i-1] + 1;
		else
		{
			int p = f(i);
			if(p < i)
				dp[i] = min(dp[i-1] + 1, dp[f(i)] + 1);

		}
	}
	for(int t=1; t<=T; t++) {
		int n;
		cin >> n;
		cout << "Case #" << t << ": ";
		cout << dp[n] << endl;
	}
    return 0;
}