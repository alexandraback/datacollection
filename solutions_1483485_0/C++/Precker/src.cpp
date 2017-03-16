#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n,num;
	char mp[27];
	for(int i=0;i<26;i++)
	{
		mp[i]='*';
	}
	char org[3][200]={{"our language is impossible to understand"},{"there are twenty six factorial possibilities"},{"so it is okay if you want to just give up"}};
	char glgLan[3][200]={{"ejp mysljylc kd kxveddknmc re jsicpdrysi"},{"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"},{"de kr kd eoya kw aej tysr re ujdr lkgc jv"}};
	for(int i=0;i<26;i++)
	{
		char ch=(char)('a'+i);
		for(int row=0;row<3;row++)
		{
			for(int c=0;c<strlen(org[row]);c++)
			{
				if(org[row][c]==ch)
				{
					mp[i]=glgLan[row][c];
					break;
				}
			}
		}
	}
	mp[16]='z';
	mp[25]='q';	
	
	cin>>n;
	num=1;
	string str;
	getline(cin,str);
	while(n--)
	{
		getline(cin,str);
		printf("Case #%d: ",num++);
		//treat the str;
		for(int i=0;i<str.length();i++)
		{
			//str[i];
			for(int j=0;j<26;j++)
			{
				if(mp[j]==str[i])
				{
					str[i]=(char)('a'+j);
					break;
				}
			}
		}
		cout<<str<<endl;
	}
	return 0;
}