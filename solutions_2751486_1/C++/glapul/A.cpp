#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#define uint long long int
#define MAXN 1000007
using namespace std;
char im[MAXN];
int good[MAXN];
int dp[MAXN];
bool isVowel(char a)
{
	return (a=='a' || a=='e' || a=='i' || a=='o' || a=='u');
}
int main()
{
	// ios_base::sync_with_stdio(0);
	int test;
	cin>>test;
	for (int z = 1; z<=test; z++)
	{
		cout<<"Case #"<<z<<": ";
		
		scanf("%s", im+1);
		int n;
		cin>>n;
		uint odp = 0;
		int dl = 1;
		while(im[dl])
		{
			dl++;
		}
		dl--;
		for (int i = 1; i<=dl; i++)
		{
			if (!isVowel(im[i]))
			{
				dp[i] = dp[i-1] + 1;
			}
			else
			{
				dp[i] = 0;
			}
			if(dp[i] >= n)
			{
				good[i] = 1;
			}
			else
			{
				good[i] = 0;
			}
		}
		/* for (int i = 1; i<=dl; i++)
		{
			cout<<dp[i]<<" ";
		}
		cout<<endl;
		for (int i = 1; i<=dl; i++)
		{
			cout<<good[i]<<" ";
		}
		cout<<endl; */
		int ind = n;
		for (int i = 1; i<=dl; i++)
		{
			while( (ind < i + n - 1 || good[ind]!=1) && ind <= dl)
			{
				ind++;
			}
			odp += dl - ind + 1;
		}
		cout<<odp<<endl;
	}
	return 0;
}
