#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=1000*1000+10;
typedef long long ll;
int n,tsts;
ll what[MAXN],ansi;
int dp[MAXN];
string s;
bool isCon(char c)
{
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return false;
	return true;
}
int main()
{
	cin >> tsts;
	for(int tt=1;tt<=tsts;tt++)
	{
		cin >> s >> n;
		int len=s.size();
		ansi=0;
		memset(what,0,sizeof what);
		memset(dp,0,sizeof dp);
		what[len]=len;
		for(int i=len-1;i>=0;i--)
		{
			dp[i]=isCon(s[i]) ? dp[i+1]+1 : 0;
			what[i]=what[i+1];
			if(dp[i]>=n)
				what[i]=i+n-1;
		}
		for(int i=0;i<len;i++)
			ansi+=len-what[i];
		cout << "Case #" << tt << ": " << ansi << endl;
	}
	return 0;
}
