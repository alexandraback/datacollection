#include <bits/stdc++.h>		//ry
 
int dp[1000007];
using namespace std;
 
void x() {
	
	memset(dp, 0x3f, sizeof dp);
	dp[1] = 1;
	
	for(int i = 1; i < 1000000; ++i) 
	{
		string tmp = to_string(i);
		reverse(tmp.begin(), tmp.end());
		
		int reverse = stoi(tmp);
		dp[i+1] = min(dp[i+1], dp[i] + 1);
		dp[reverse] = min(dp[reverse], dp[i] + 1);
	}
}
 
int main() 
{
	x();
	int test;
	scanf("%d", &test);
	int ans = 1;
	
	while(test--) 
	{
		int num;
		scanf("%d", &num);
		printf("Case #%d: %d\n", ans++, dp[num]);
	}
	
	return 0;
}