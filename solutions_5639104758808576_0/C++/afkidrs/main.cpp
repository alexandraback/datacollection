#include <iostream>
#include <string>

using namespace std;
int t,n;
string s;


int main()
{
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		int current=0;
		int count=0;
		cin>>n;
		cin>>s;
		for(int j=0;j<s.length();++j)
		{
			if(current>=j)
			{
				current+=s[j]-'0';
			}
			else if(s[j]!='0')
			{
				count+=j-current;
				current=j;
				current+=s[j]-'0';
			}
		}
		cout<<"Case #"<<i<<": "<<count<<endl;
	}


	return 0;
}