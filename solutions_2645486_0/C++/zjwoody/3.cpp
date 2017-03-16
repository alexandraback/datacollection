#include<iostream>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

int arr[15];
int dp[15][10];
int T, E, R, N;
int ans;
int solve(int a, int e)
{
	if(e<0)
		return 0;
	if(e>E)
		e = E;
	if(dp[a][e])
		return dp[a][e];

	int t = e, s = e;
	for(int i = a; i < N; ++i)
	{
	for(int j = 0; j <= s; ++j)
	{
		int tmp;
		if(j == 0 && s+R <= E)
			tmp = solve(i+1, s+R);
		else
			tmp = solve(i+1,s-j+R)+j*arr[i];         
		if(dp[i][s] < tmp)
		{
			dp[i][s] = tmp;
			t = s-j+R;
		}
	}
		s = t;
	}
	return dp[a][e];
	
}
int main()
{
	freopen("D:\\ACM\\zj\\codejam\\B-small-attempt0.in","r",stdin);
    freopen("D:\\ACM\\zj\\codejam\\2out.txt","w",stdout);
	cin>>T;
	int caseid = 1;
	while(T--)
	{
		cin>>E>>R>>N;
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i <N; ++i)
			cin>>arr[i];
		
		int ans = solve(0, E);
		cout<<"Case #"<<caseid<<": "<<ans<<endl;
		caseid++;
			
	}
	return 0;
}
