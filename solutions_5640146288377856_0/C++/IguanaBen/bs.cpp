/*
	Michał Gańczorz
	code jam 2015
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <string>
#include <queue>
#include <list>
#include <sstream>
 // #include <unistd.h>
// #include <unordered_map>

#define ll long long

using namespace std;



int sc(int r, int c, bool k)
{
	if(c > r) return 0;

	if(c == r) return c;
	if(!k)
	{
		int x = 1000;
		// int xp = 1000;
		for(int i=c; i<r; ++i)
			x = min(x, 1 + sc(i, c, k) + sc(r-i-1, c, k));

		return x;
	}
	else
	{
		int x = 1000;
		// int xp = c+1;
		for(int i=c; i<r; ++i)
			x = min(x, 1 + sc(i, c, !k) + sc(r-i-1, c,  k));

		return max(x, c+1);
	}

	// return mx;
}

void solve(int z)
{
	int w, r, c;
	cin>>w>>r>>c;
	int res = sc(r,c, 1);
	cout<<"Case #"<<z<<": "<<res<<"\n";
}

int main()
{
	int t;
	cin>>t;
	for(int i=1; i<=t; i++)
		solve(i);
	
	return 0;
}