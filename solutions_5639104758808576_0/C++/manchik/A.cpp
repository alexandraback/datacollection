#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int SM;
		cin>>SM;
		string s;
		cin>>s;
		int sofar=0;
		int needed=0;
		for(int i=0;i<s.length();i++)
		if(s[i]!='0')
		{
			if(sofar<i)
			{
				needed+=(i-sofar);
				sofar=i;
			}
			sofar+=(s[i]-'0');
		}
		cout<<"Case #"<<t<<": "<<needed<<endl;
	}
	return 0;
}
		
