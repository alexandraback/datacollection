#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <string.h>
 
#define repx(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repx(i,0,n)
#define pb push_back
#define full(v)  v.begin(),v.end()
#define np next_permutation
#define VI vector<int>
#define VS vector<string>
#define VC vector<char>
#define VD vector<double>
#define VF vector<float>
#define SI set<int>
#define SC set<char>
#define SS set<string>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MIC map<int,char>
#define MCI map<char,int>
#define LL long long
using namespace std;
	
LL reverse(LL n)
{
	LL ret  = 0;
	while(n)
	{
		ret = ret * 10 + (n%10);
		n/=10;
	}
	return ret;
}
 
int main()
{

	int dp[1000007]={0};
	dp[1]=1;
	for(LL i =1;i<=1000001;i++)
	{
		int a , b;
		a = reverse(i);
		b = i+1;
		if(dp[a] == 0)
			dp[a] = dp[i]+1;
		else
			dp[a] = min(dp[a],dp[i]+1);
		if(dp[b]==0)
			dp[b] = dp[i]+1;
		else
			dp[b] = min(dp[b],dp[i]+1);
	}

	int test;
	cin>>test;
	repx(tc,1,test+1)
	{
		LL n;
		cin>>n;
		cout<<"Case #"<<tc<<": "<<dp[n]<<"\n";
	}
	return 0;
}
