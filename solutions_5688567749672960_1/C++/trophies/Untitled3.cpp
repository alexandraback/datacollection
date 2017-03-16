#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair <int, int> 
int pow10[16]; 
int dp [1000005]; 
PII rev (int num)
{
	if (num/10==0)
	{
		return PII(num, 1); 	
	}	
	PII x=rev(num/10); 
	return PII(x.first+pow10[x.second]*(num%10), x.second+1); 
}
int realrev (int num)
{
	return rev(num).first; 
}
int solve (int a)
{
	if (a<=1000000) return dp[a]; 
	if (a%10==0) return 1+solve(a-1); 
	int min10; 
	for (int g=0; g<=15; g++)
	{
		if (pow10[g]<=a)
		{
			min10=g; 
		}
	}
	int minans=a-pow10[min10]; 
	int t=0;
	vector <int> store;
	int storet=a; 
	while (a)
	{
		store.push_back(a%10);a/=10; 
	}	
	a=storet;
	reverse(store.begin(), store.end()); 
	int counter=0; 
	for (int g=store.size()-1; g>=store.size()/2; g--)
	{
		t+=(pow10[counter]*store[g]); 
		counter++; 
	}
	counter=0; 
	for (int g=0; g<store.size()/2; g++)
	{
		t+=(pow10[counter]*store[g]); 
		counter++; 	
	}
	return min(t, minans)+solve(pow10[min10]); 
}
main()
{
	freopen("in.txt", "r", stdin); 
	freopen("out.txt", "w", stdout); 
	pow10[0]=1;
	for (int g=1; g<=15;g++)pow10[g]=10*pow10[g-1]; 
	for (int g=1; g<=1000000; g++)dp[g]=1e9; 
	for (int g=1; g<=1000000; g++)
	{
		if (g%10==0)
		{
			dp[g]=1+dp[g-1]; continue;
		}
		int t=realrev(g); 
		dp[g]=1+min(dp[t], dp[g-1]); 
	}
	int T; cin >> T;
	for (int g=0; g<T; g++)
	{int x; cin >> x; 
		cout << "Case #" << g+1<< ": " << solve(x) << '\n'; 
	}
	return 0; 
}
