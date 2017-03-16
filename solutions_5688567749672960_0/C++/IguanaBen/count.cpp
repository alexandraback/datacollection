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
// const ll prime = 1000000007;

int dp[1000033];

ll rev(ll x)
{
   ll r = 0;
   while(x)
   {
   	r *=10;
   	r += x%10;
   	x/=10;
   }
   return r;
}

void fill()
{
	dp[1] = 1;
	for(int i=2; i<=1000001; ++i)
	{
		ll xx;
		

		if(i % 10)
		{
			xx = rev(i);
			// cout<<i<<" "<<xx<<"\n";
		}
		else
		{
			xx = i-1;
		}

		if(xx >= i)
			xx = i-1;
		dp[i] = min(dp[i-1], dp[xx]) + 1;

		// if( i % 10000 == 0)
			// cout<<i<<" \n";
	}
}

void solve(int c)
{
	int n;
	// string str;
	cin>>n;
	// int res = 0;


	cout<<"Case #"<<c<<": "<<dp[n]<<"\n";
}

int main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(NULL);
	// cout<<rev(11)<<"\n";
	fill();
	int t;
	cin>>t;
	for(int i=1; i<=t; i++)
		solve(i);

	return 0;
}