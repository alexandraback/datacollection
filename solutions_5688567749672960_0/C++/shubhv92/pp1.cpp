#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int reverse(int n)
{
	int temp = 0;
	temp = temp + n%10;
	n = n/10;
	while (n!=0)
	{
		temp = temp*10;
		temp = temp + n%10;
		n = n/10;
	}
	return temp;
}

int main()
{
	int dp[1000001];
	for (int i=0;i<1000001;i++)
	{
		dp[i] = 9999999;
	}
	dp[0] = 0;
	dp[1] = 1;
	for (int i=2;i<1000001;i++)
	{
		int j = reverse(i);
		dp[i] = min(dp[i-1]+1, dp[j]+1);
		if (i%10 == 0)
			dp[i] = dp[i-1] + 1;
		// cout << "entry " << i << " is " << dp[i] << endl;
	}

	int test, n;
	cin >> test;
	for (int k = 1;k<=test; k++)
	{
		cin >> n;
		// cout << "hello";
		cout << "Case #" << k << ": " << dp[n] << endl;
	}
	return 0;
}