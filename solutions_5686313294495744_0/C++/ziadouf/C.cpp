#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <sstream>
#include <queue>
#include <string.h>
#include <numeric>
using namespace std;

 typedef vector<int> vi; 
 typedef vector<vi> vvi; 
 typedef pair<int,int> ii; 
 typedef long long ll;
 #define sz(a) int((a).size()) 
 #define pb push_back 
 #define all(c) (c).begin(),(c).end() 
 #define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
 #define present(c,x) ((c).find(x) != (c).end()) 
 #define cpresent(c,x) (find(all(c),x) != (c).end()) 

vector < pair<string,string> > list;
int N;
int dp[(1<<16)+10];

bool isCheat (int i , int mask)
{
	unordered_set <string> first;
	unordered_set <string> second;
	for (int j=0 ; j<N ; j++)
	{
		if (mask & (1<<j))
		{
			first.insert(list[j].first);
			second.insert(list[j].second);
		}
	}
	
	if (first.count(list[i].first) && second.count(list[i].second)) return 1;
	return 0;
}

int solve (int mask)
{
	if (mask == (1 << N)-1) return 0;
	if (dp[mask] != -1) return dp[mask];
	
	int ret = 0;
	
	for (int i=0 ; i<N ; i++)
	{
		if (mask & (1<<i)) continue;
		
		bool cheated = isCheat(i,mask);
		ret = max(ret, cheated + solve(mask | (1<<i)));
	}
	
	return dp[mask] = ret;
}
int main ()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	
	int TC;
	cin >> TC;
	int CC = 1;
	while (TC--)
	{
		printf("Case #%d: ",CC++);
		list.clear();
		memset(dp,-1,sizeof dp);
		cin >> N;
		
		for (int i=0 ; i<N ; i++)
		{
			string a,b;
			cin >> a >> b;
			list.pb(make_pair(a,b));
		}
		
		cout << solve(0) << endl;
	}
	
}
