#include <bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main() {
	// your code goes here
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		cin>>n;
		cin>>s;
		int ans = 0,num=0;
		int ppl=0;
		for(int i=0;i<s.size();++i)
		{
			if(s[i]=='0')continue;
			if(num<i)
			{
				ans += i-num;
				num = i;
			}
			num += s[i]-'0';
		}
		cout<<"Case #"<<c<<": "<<ans<<endl;
	}
	return 0;
}