#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define rep(k, a, b) for (int k = (a); k < int(b); k++)
#define rrep(k, a, b) for (int k = (a); k >= int(b); k--)
#define irep(it, xs) for (auto it = xs.begin(); it!=xs.end(); it++)
#define rirep(it, xs) for (auto it = xs.rbegin(); it!=xs.rend(); it++)
#define erep(e, xs) for (auto& e : (xs))
#define rint(x) scanf("%d", &(x))
#define rfloat(x) scanf("%lf", &(x))

typedef long long LL;
typedef pair<int,int> II;

int N;
int dp[10000011];

int reverse(int i)
{
	int r=0;
	while(i!=0)
	{
		r *=10;
		r +=i%10;
		i/=10;
	}
	return r;
}

int main()
{
	dp[1]=1;
	queue<int> qi;
	qi.push(1);
	while(!qi.empty())
	{
		int i = qi.front();qi.pop();
		//cout << i << endl;
		if(i > 10000010) continue;

		int r = i+1;

		if(dp[r]==0 || dp[r] > dp[i]+1)
		{
			dp[r] = dp[i]+1;
			qi.push(r);
		}

		r = reverse(i);
		if(r > 10000010) continue;
		if(dp[r]==0 || dp[r] > dp[i]+1)
		{
			dp[r] = dp[i]+1;
			qi.push(r);
		}
	}

	int T;
	rint(T);
	rep(t, 0, T)
	{
		rint(N);
		printf("Case #%d: %d\n",t+1, dp[N]);
	}
	return 0;
}