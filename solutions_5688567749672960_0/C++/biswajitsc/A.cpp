#include <iostream>
#include <fstream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <cstdio>
#include <assert.h>

#define mset(x,y) memset(x,y,sizeof(x))
#define INF 1000000000
#define MOD 1000000007
#define pb(X) push_back(X) 
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define FOR(i,n) for (int i=0; i<(n); i++)
#define foreach(it, c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)
#define sz(v) ((int) v.size())
#define mp(a, b) make_pair(a, b)
 
using namespace std;
 
typedef long long int lli;
typedef pair<int,int> pii;


const int maxn = 1000100;
int dp[maxn];
int dig[20];
int size;

lli rev(lli i)
{
	size = 0;
	while(i)
	{
		dig[size++] = i%10;
		i/=10;
	}

	lli ret = 0;
	for(int i=0; i<size; i++) ret = ret*10+dig[i];
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);

	for(int tt = 1; tt<=t; tt++)
	{
		lli n;
		cin>>n;

		for(int i=0; i<maxn; i++) dp[i] = INF;
		dp[n] = 1;
		for(int i=n-1; i>0; i--) dp[i] = min(dp[i+1], dp[rev(i)])+1;
		printf("Case #%d: %d\n", tt, dp[1]);
	}

    return 0;
}