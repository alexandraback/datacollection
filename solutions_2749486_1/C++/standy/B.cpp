#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <sstream>
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <LL> VL;

const int MAXN = 100010;

char path[MAXN];
string dir;
int x, y, n;

bool dfs(int S, int idx)
{
	if(S == 0)	return 1;
	
	if(idx == 0)	return 0;
	
	if(path[idx - 1] == 'o' && idx <= S && dfs(S - idx, idx - 1))
	{
		path[idx - 1] = dir[1];
		return 1;
	}	
	
	return dfs(S, idx - 1);
}

bool solve(int S, int idx)
{
	if(S == 0)	
	{
		int sum = 0;
		for(int i = 1; i <= n; ++ i)
			if(path[i - 1] == 'o')
				sum += i;
		
		if(dfs((sum - x) / 2, n))
		{
			for(int i = n; i > 0; -- i)
				if(path[i - 1] == 'o')	
					path[i - 1] = dir[0];
			
			puts(path);	
			
			return 1;
		}	
		
		return 0;
	}
	
	if(idx == 0)	return 0;
	
	if(path[idx - 1] == 'o' && idx <= S)
	{
		path[idx - 1] = dir[2];
		if(solve(S - idx, idx - 1))	return 1;
		path[idx - 1] = 'o';
	}	
	
	return solve(S, idx - 1);	
}

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	
	int T;	cin >> T;
	
	for(int cas = 1; cas <= T; ++ cas)
	{
		cin >> x >> y;
		
		dir = "EWNS";
		if(x < 0)	swap(dir[0], dir[1]), x = -x;
		if(y < 0)	swap(dir[2], dir[3]), y = -y;
//		if(x < y)	swap(x, y), swap(dir[0], dir[2]), swap(dir[1], dir[3]);
		
		printf("Case #%d: ", cas);
		
		int sum = 0;
		for(int i = 1; sum < x + y || (sum - x - y) % 2; ++ i)
		{
			sum += i;
			n = i;	
		}
		
		for(int i = 0; i < n; ++ i)	path[i] = 'o';
		path[n] = '\0';
		
		if(!solve(y, n))
		{
			swap(x, y);
			swap(dir[0], dir[2]);
			swap(dir[1], dir[3]);
			
			if(!solve(y, n))	while(1);	
		}

	}

	
	return 0;	
}
