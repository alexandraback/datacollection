#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int dp[1000005];
int main()
{
	int t;
	cin >> t;
	fill(dp,dp+1000005,INF);
	dp[0] = 0;
	for(int i=1;i<=1000000;i++)
	{
		dp[i] = min(dp[i],dp[i-1]+1);
		if(i%10==0) continue;
		string x="";
		int j=i;
		while(j)
		{
			x.pb('0'+j%10); j/=10;
		}
		int r=0,t=1;
		for(int i=x.size()-1;i>=0;i--)
		{
			r += (x[i]-'0')*t; t*=10;
		}
		if(r<i) dp[i] = min(dp[i],dp[r]+1);
	}
	for(int e=1;e<=t;e++)
	{
		int n; cin >> n;
		printf("Case #%d: %d\n",e,dp[n]);
	}
}