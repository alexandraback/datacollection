#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<functional>
#include<cstring>

using namespace std;

long long dp[1000001];

long long reverse(long long n)
{
	long long ret = 0;
	while(1)
	{
		if(n % 10 == 0)
			n /= 10;
		else break;
	}

	while(n != 0)
	{
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

long long solve(long long n)
{
	long long &ret = dp[n];
	if(ret != -1) return ret;

	if(n % 10 != 0 && reverse(n) < n) 
	{
		ret = solve(reverse(n)) + 1;
		ret = min(ret, solve(n-1) + 1);
	}
	else ret = solve(n-1) + 1;
	return ret;

}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int T;
	in >> T;
	memset(dp, -1, sizeof(dp));
	for(int i = 1; i < 10; ++i) dp[i] = i;	

	for(int kase = 1; kase <= T; ++kase)
	{
		long long N;
		in >> N;
		
		int ans = solve(N);	
		
		out << "Case #" << kase << ": " << ans << endl;

	}

	in.close();
	out.close();
	return 0;
}
