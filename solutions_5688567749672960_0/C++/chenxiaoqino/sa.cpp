#include <iostream>
#include <string>
using namespace std;


string reverse(string a)
{
	string ret(a);
	int l=a.length();
	for(int i=0;i<l;i++)
		ret[i]=a[l-i-1];
	return ret;
}

int reverse(int a)
{
	return atoi(reverse(to_string(a)).c_str());
}
int dp[10001000];
int calc()
{
	int n;
	cin>>n;
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+1;
		if(i%10==0)continue;
		int rev=reverse(i);
		if(rev>=i)continue;
		dp[i]=min(dp[i], dp[rev]+1);
	}
	
	return dp[n];//return search(s);
}

int main()
{
	//string a("12354");
	//cout<<calc();return 0;
	int N;cin>>N;
	for(int i=0;i<N;i++)
		cout<<"Case #"<<(i+1)<<": "<<calc()<<endl;
	return 0;
}