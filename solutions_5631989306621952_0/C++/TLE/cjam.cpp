#include <bits/stdc++.h>
using namespace std;

int main()
{
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int T;
	cin>>T;
	for (int ts=1;ts<=T;ts++)
	{
		cout<<"Case #"<<ts<<": ";
		string s;
		cin>>s;
		string t;
		t+=s[0];
		for (int i=1;i<s.size();i++)
		{
			if (t[0]<=s[i])
			{
				string tmp;
				tmp+=s[i];
				tmp+=t;
				t=tmp;
			}
			else t+=s[i];
		}
		cout<<t<<endl;


	}



	return 0;
}