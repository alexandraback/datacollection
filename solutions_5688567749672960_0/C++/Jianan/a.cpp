#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
inline int min(int x,int y)
{
	return x<y?x:y;
}
int reverse(int x)
{
	int ret=0;
	while (x>0)
	{
		ret=ret*10+x%10;
		x/=10;
	}
	return ret;
}
int main()
{
	ifstream fin("1.txt");
	ofstream fout("2.txt");
	int T,o,i,tmp,n;
	fin >> T;
	for (o=1;o<=T;o++)
	{
		fin >> n;
		vector<int> dp(n+1,n);
		dp[0]=0;
		for (i=0;i<n;i++)
		{
			dp[i+1]=min(dp[i]+1,dp[i+1]);
			int tmp=reverse(i);
			if (tmp>n || tmp <=i) continue;
			dp[tmp]=min(dp[tmp],dp[i]+1);
		}
		cout << "Case #" << o << ": " << dp[n] << endl;
		fout << "Case #" << o << ": " << dp[n] << endl;

	}
	return 0;
}