#include <iostream>
using namespace std;

const string dol = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	string s;
	int T;
	cin>>T; getline(cin,s);
	for(int t=1; t<=T; t++)
	{
		getline(cin,s);
		for (int i=0; i<s.size(); i++)
			s[i] = s[i]!=' ' ? dol[s[i]-'a'] : s[i];
		cout<<"Case #"<<t<<": "<<s<<endl;
	}
	return 0;
}

