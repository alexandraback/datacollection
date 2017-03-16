#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int ToNum(char c)
{
	if(c==' ')
		return 26;
	return c-'a';
}
int main()
{
	int c,t,i,l;
	char *m = "yhesocvxduiglbkrztnwjpfmaq ";
	char s[110];
	cin>>t;
	cin.getline(s,100);
	for(c=0;c<t;c++)
	{
//		do
//		{
			cin.getline(s,110);
			l = strlen(s);
//		}while(s[0]=='\n' || s[0]==0);

		for(i=0;i<l;i++)
		{
			s[i] = m[ToNum(s[i])];
		}
		cout<<"Case #"<<c+1<<": "<<s<<endl;
	}
}
