#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int n, max_E, rec;
int arr[5050];
int memo[11][10][899];

int dp(int id, int energy, int accum)
{
	if( id >= n )
		return accum;
	
	if( memo[id][energy][accum] != -1 )
		return memo[id][energy][accum];

	int res = -1;
	for(int i = 0; i <= energy; ++i)
	{
		//if spent i
		res = max(res, dp( id + 1, ((energy - i + rec) >= max_E ? max_E : (energy - i + rec)), accum + (arr[id] * i) ));
	}
	
	return memo[id][energy][accum] = res;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("outB.txt", "w", stdout);
	
	int TC;
	cin >> TC;
	
	for(int i = 1; i <= TC; ++i)
	{
		int E, R, N;
		cin >> E >> R >> N;
		
		n = N; 
		max_E = E;
		rec = R;
		memset( memo, -1, sizeof(memo));
		
		for(int j = 0; j < N; ++j)
			cin >> arr[j];

		cout << "Case #" << i << ": " << dp( 0, max_E, 0 ) << endl;
	}
	
	return 0;
}
