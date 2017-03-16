#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
#include <string>
#include <string>
#include <set>
#include <map>

#define X first
#define Y second
#define ll long long

using namespace std;

ll dp[50][2][2][2];
ll aa, bb, kk;
int a[50], b[50], k[50];
void solve(int test)
{
	ll ans=0;
	cin>>aa>>bb>>kk;
	for (int i=40; i>0; i--)
		a[i]=aa%2, aa/=2;
	for (int i=40; i>0; i--)
		b[i]=bb%2, bb/=2;
	for (int i=40; i>0; i--)
		k[i]=kk%2, kk/=2;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0]=1;
	for (int i=0; i<40; i++)
	{
		ll w=0;
		// 0 0 0
		w=dp[i][0][0][0];
		for (int a1=0; a1<a[i+1]; a1++)
			for (int b1=0; b1<b[i+1]; b1++)
				if ( (a1&b1)<k[i+1] )
					dp[i+1][1][1][1]+=w;
				else
					if ( (a1&b1)==k[i+1] ) 
						dp[i+1][1][1][0]+=w;
	
		for (int a1=a[i+1]; a1<=a[i+1]; a1++)
			for (int b1=0; b1<b[i+1]; b1++)
				if ( (a1&b1)<k[i+1] )
					dp[i+1][0][1][1]+=w;
				else
					if ( (a1&b1)==k[i+1] ) 
						dp[i+1][0][1][0]+=w;
		for (int a1=0; a1<a[i+1]; a1++)
			for (int b1=b[i+1]; b1<=b[i+1]; b1++)
				if ( (a1&b1)<k[i+1] )
					dp[i+1][1][0][1]+=w;
				else
					if ( (a1&b1)==k[i+1] ) 
						dp[i+1][1][0][0]+=w;
		for (int a1=a[i+1]; a1<=a[i+1]; a1++)
			for (int b1=b[i+1]; b1<=b[i+1]; b1++)
				if ( (a1&b1)<k[i+1] )
					dp[i+1][0][0][1]+=w;
				else
					if ( (a1&b1)==k[i+1] ) 
						dp[i+1][0][0][0]+=w;
		//0 0 1
		w=dp[i][0][0][1];
		for (int a1=0; a1<a[i+1]; a1++)
			for (int b1=0; b1<b[i+1]; b1++) 
					dp[i+1][1][1][1]+=w;
	
		for (int a1=a[i+1]; a1<=a[i+1]; a1++)
			for (int b1=0; b1<b[i+1]; b1++) 
						dp[i+1][0][1][1]+=w;
		for (int a1=0; a1<a[i+1]; a1++)
			for (int b1=b[i+1]; b1<=b[i+1]; b1++) 
					dp[i+1][1][0][1]+=w;
		for (int a1=a[i+1]; a1<=a[i+1]; a1++)
			for (int b1=b[i+1]; b1<=b[i+1]; b1++) 
					dp[i+1][0][0][1]+=w;
		//0 1 0
		w=dp[i][0][1][0];
		for (int a1=0; a1<a[i+1]; a1++)
			for (int b1=0; b1<2; b1++)
				if ( (a1&b1)<k[i+1] )
					dp[i+1][1][1][1]+=w;
				else
					if ( (a1&b1)==k[i+1] ) 
						dp[i+1][1][1][0]+=w;
	
		for (int a1=a[i+1]; a1<=a[i+1]; a1++)
			for (int b1=0; b1<2; b1++)
				if ( (a1&b1)<k[i+1] )
					dp[i+1][0][1][1]+=w;
				else
					if ( (a1&b1)==k[i+1] ) 
						dp[i+1][0][1][0]+=w;
		// 0 1 1
		w=dp[i][0][1][1];
		for (int a1=0; a1<a[i+1]; a1++)
			for (int b1=0; b1<2; b1++)
				dp[i+1][1][1][1]+=w;
		for (int a1=a[i+1]; a1<=a[i+1]; a1++)
			for (int b1=0; b1<2; b1++)
				dp[i+1][0][1][1]+=w;
		//1 0 0
		w=dp[i][1][0][0];
		for (int a1=0; a1<2; a1++)
			for (int b1=0; b1<b[i+1]; b1++)
				if ( (a1&b1)<k[i+1] )
					dp[i+1][1][1][1]+=w;
				else
					if ( (a1&b1)==k[i+1] ) 
						dp[i+1][1][1][0]+=w;
	
		for (int a1=0; a1<2; a1++)
			for (int b1=b[i+1]; b1<=b[i+1]; b1++)
				if ( (a1&b1)<k[i+1] )
					dp[i+1][1][0][1]+=w;
				else
					if ( (a1&b1)==k[i+1] ) 
						dp[i+1][1][0][0]+=w;
		// 1 0 1
		w=dp[i][1][0][1];
		for (int a1=0; a1<2; a1++)
			for (int b1=0; b1<b[i+1]; b1++)
				dp[i+1][1][1][1]+=w;
		for (int a1=0; a1<2; a1++)
			for (int b1=b[i+1]; b1<=b[i+1]; b1++)
				dp[i+1][1][0][1]+=w;
		// 1 1 0
		w=dp[i][1][1][0];
		for (int a1=0; a1<2; a1++)
			for (int b1=0; b1<2; b1++)
				if ( (a1&b1)<k[i+1] )
					dp[i+1][1][1][1]+=w;
				else
					if ( (a1&b1)==k[i+1] )
						dp[i+1][1][1][0]+=w;
		// 1 1 1
		w=dp[i][1][1][1];
		for (int a1=0; a1<2; a1++)
			for (int b1=0; b1<2; b1++)
				dp[i+1][1][1][1]+=w;
	}
	ans=dp[40][1][1][1];
	printf("Case #%d: %I64d\n", test, ans);
}
int main()
{
	freopen("B-large.txt", "r", stdin);
	freopen("B-largeans.txt", "w", stdout);
	int test;
	cin>>test;
	for (int i=1; i<=test; i++)
		solve(i);
	return 0;
}
