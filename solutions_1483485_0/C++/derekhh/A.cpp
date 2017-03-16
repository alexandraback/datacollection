#include<iostream>
#include<string>
using namespace std;

int main()
{
	string ch = "yhesocvxduiglbkrztnwjpfmaq";
	int t,no=0;
	cin>>t;
	getchar();
	while(t--)
	{
		string line;
		getline(cin,line);
		int len=(int)line.size();
		for(int i=0;i<len;i++)
			if(line[i]>='a'&&line[i]<='z')
				line[i]=ch[line[i]-'a'];
		cout<<"Case #"<<++no<<": "<<line<<endl;
	}
	return 0;
}