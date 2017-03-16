#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <functional>
 
#pragma comment(linker, "/STACK:134217728")
 
using namespace std;

long long f(long long n)
{
	int res = 0;
	while(n > 0)
	{
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}
int dp[1000100];
map <long long, int> mp;

long long calc(long long n)
{
	// cout << "#"<< n << endl;
	if(n <= 20) return n;
	if(mp[n]) return mp[n];
	if(!(n % 10))
		return mp[n]  = calc(n-1) + 1;
	
	if(f(n) >= n && n > 0)
	{
		return mp[n]  = calc(n-1) + 1;
	}
	else
	{
		if(!(n % 10)) return mp[n] = calc(n-1) + 1; else {
			long long p = f(n);
			int ans = 0;
			while(f(n-ans-1) < p && ((n-ans-1)%10))
			{
				ans++;
				//n--;
				p = f(n - ans);
			}
			//cout << "$$$ " << f(n - ans) << " " << n << " " << ans << endl;
			return mp[n] = min(ans + 1 + calc(f(n - ans)), calc(n - ans - 1) + ans + 1);	
		}
	}
}

string tos(long long n)
{
	string res = "";
	while(n > 0)
	{
		res = char('0' + n % 10) + res;
		n /= 10;
	}
	return res;
}

int ff(long long n) 
{
	if(n <= 20) return n;
	if(!(n % 10)) return 1 + ff(n-1);
	int temp = 1;
	string s = tos(n);
	if(s[0] == '1' && s[s.length()-1] == '1')
	{
		bool ok = 1;
		for(int i=2; i<s.length()-1; i++)\
			if(s[i] !='0') ok = 0;

		if(ok)
			return 1 + ff(n-1);
	}
	long long ans = 0;
	long long p = 1;
	int j = 0;
	for(int i=s.length()-1; i>=s.length()/2; i--)
	{
		if(i == s.length()-1) ans += p * (s[i] - '1'); else ans += p * (s[i] - '0');
		if(j < i) ans += p * (s[j] - '0'); j++;
		p *= 10LL;
		s[i] = '0';
	}
	
    s[s.length()-1] = '1';
	long long q = 1;
	for(int i=0; i<s.length()-1; i++)
		q = q * 10LL;
	
	bool w = 1;
	for(int i=1; i<s.length()/2; i++)
		if(s[i] > '0') w = 0;
	if(s[0] > '1') w = 0;

	if(w)
		return ans + ff(q);
	else
		return ans + 1 +ff(q);
}
int main() {   
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int T=0;
	cin >> T;
	dp[0] = 0;
	for(int i=1; i<=1000000; i++) {
		dp[i] = dp[i-1] + 1;
		if(i <= 10 || !(i % 10)) dp[i] = dp[i-1] + 1;
		else
		{
			int p = f(i);
			if(p < i)
				dp[i] = min(dp[i-1] + 1, dp[f(i)] + 1);

		}
	}
	
	//for(int i=101; i<=202; i++) {
	//	cout << i << " " << dp[i] << " " << ff(i) << endl;
	//
	//if(dp[i] != ff(i))
	//		{
	//				cout << i << " " << "WA" << endl;
	//				//break;
	//		}
	////cout << i << " " << ff(100000000000000LL-100+i) << endl;
	//}
	for(int t=1; t<=T; t++) {
		long long n;
		cin >> n;
		cout << "Case #" << t << ": ";
		cout << ff(n)<< endl;
	}
    return 0;
}