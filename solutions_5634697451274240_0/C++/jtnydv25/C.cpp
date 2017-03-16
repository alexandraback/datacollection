#include <iostream>
using namespace std;

int ans(string s)
{
	int l = s.length();
	int n1 = 0;
	for(int i = 0;i<l;i++)
	{
		if(s[i] == '-')
			n1++;
	}
	if(n1 == 0)
		return 0;
	int ret = 0;	
	if(s[0] == '-')
	{
		s[0] = '+';
		int i = 1;
		while(s[i] == '-')
		{
			s[i] = '+';
			i++;
		}
		int rem = n1-i;
		ret+=1;
		if(rem == 0)
			return ret;
		return ret+ans(s);	
	}
	else
	{
		s[0] = '-';
		int i = 1;
		while(s[i] == '+')
		{
			s[i] = '-';
			i++;
		}
		return 1+ans(s);
	}
}

int main() {
	int t;
	cin>>t;
	for(int t1 = 1;t1<=t;t1++)
	{
		string s;
		cin>>s;
		cout<<"Case #"<<t1<<": "<<ans(s)<<endl;
	}
	return 0;
}