#include <iostream>
#include <string>

using namespace std;

int main()
{
	char c[27]="yhesocvxduiglbkrztnwjpfmaq";
	int t;
	cin>>t;
	string s;
	getline(cin,s);
	for(int test_case=0;test_case<t;test_case++)
	{
		getline(cin,s);
		cout<<"Case #"<<test_case+1<<": ";
		for(int i=0;i<s.length();i++)
		{
			if(s[i]==' ')cout<<' ';else cout<<c[s[i]-'a'];
		}
		cout<<endl;
	}
	return 0;
}
