#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

set<string> d;
string x;
int n;
int memo[4001][6];

int calc(int idx, int r)
{
	if (idx >= n) return 0;
	
	if (memo[idx][r] >= 0) return memo[idx][r];
	//printf("Begin calc(%d,%d) %s\n", idx, r, x.substr(idx).c_str() );
	char o = x[idx];
	int ret = n - idx;
	for (char i = 'a'; i <= 'z'; ++i) {
		if (r && i != o) continue;
		x[idx] = i;
		for (int j = min(10, n - idx); j >= 1; --j) {
			if (d.find(x.substr(idx, j) ) != d.end() ) {
				int rr;
				if (i == o) rr = max(0, r - j);
				else rr = max(0, 5 - j);
				ret = min(ret, calc(idx + j, rr) + ( (i == o) ? 0 : 1 ) );
				//printf("  Found(%d,%d) %s = %d\n", idx, r, x.substr(idx, j).c_str(), ret);
			}
		}
	}
	x[idx] = o;
	//printf("End   calc(%d,%d) %s = %d\n", idx, r, x.substr(idx).c_str(), ret);
	memo[idx][r] = ret;
	return ret;
}

int main()
{
	
	fstream f;
	f.open("dic.txt");
	while (f >> x) {
		d.insert(x);
	}
	f.close();
	
	int t;
	cin >> t;
	
	for (int c = 1; c <= t; ++c) {
		memset(memo, 0xFF, sizeof(memo) );
		cin >> x;
		n = x.size();
		
		int z = calc(0, 0);
		printf("Case #%d: %d\n", c, z);
	}
	
	return 0;
}
