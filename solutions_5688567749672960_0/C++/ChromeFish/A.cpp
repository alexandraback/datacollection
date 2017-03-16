#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
ifstream in("A.in");
ofstream out("A.out");

int ans;
int dp[10000010];
int getlen(int n)
{
	int len = 0;
	while (n>0)
	{
		len++;
		n/=10;
	}
	return len;
}
int re(int n)
{
	int ans = 0;
	while (n>0)
	{
		ans =ans*10+ (n % 10);
		n /=10;
	}
	return ans;
}




int main()
{
	int T, n, headNum;
	in>>T;
	for (int i=1; i<=T; i++)
	{
		in>>n;
		for (int j=1; j<=n; j++)
		{
			dp[j] = j;
		}
		for (int j=1; j<n; j++)
		{
			dp[j+1] = min(dp[j+1], dp[j]+1);
			int x= re(j);
			dp[x] = min(dp[j]+1, dp[x]);
		}
		out<<"Case #"<<i <<": "<<dp[n]<<endl;
	}
}