#include<iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	int icase = 1;
	string s;
	while(t--)
	{
		cin>>s;
		int len = s.length();
		string res = "";
		res = s[0];
		for(int i=1;i<len;i++)
		{
			if(s[i] >= res[0])
				res = s[i]+res;
			else
				res = res + s[i];
		}

		cout<<"Case #"<<icase++<<": ";
		cout<<res<<endl;
	}

	return 0;
}