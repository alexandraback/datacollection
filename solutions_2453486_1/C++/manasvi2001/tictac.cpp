#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,u;
	cin>>t;
	u=t;
	while(t--)
	{
		string s[10];
		int i;
		for(i=0;i<4;i++)
		{
			cin>>s[i];
		}
		for(i=0;i<4;i++)
		{
			s[i+4]="";
			s[i+4]+=s[0][i];
			s[i+4]+=s[1][i];
			s[i+4]+=s[2][i];
			s[i+4]+=s[3][i];
		}
		s[8]=s[9]="";
		s[8]+=s[0][0];
		s[8]+=s[1][1];
		s[8]+=s[2][2];
		s[8]+=s[3][3];
		s[9]+=s[3][0];
		s[9]+=s[2][1];
		s[9]+=s[1][2];
		s[9]+=s[0][3];
		int c=0,found,flag=1;
		for(i=0;i<10;i++)
		{
			if(s[i]=="XXXX"||s[i]=="XXXT"||s[i]=="XXTX"||s[i]=="XTXX"||s[i]=="TXXX")
			{
				cout<<"Case #"<<u-t<<": X won\n";
				flag=0;
				break;
			}
			else if(s[i]=="OOOO"||s[i]=="OOOT"||s[i]=="OOTO"||s[i]=="OTOO"||s[i]=="TOOO")
			{
				cout<<"Case #"<<u-t<<": O won\n";
				flag=0;
				break;
			}
			else
			{
				found=s[i].find(".");
				if(found!=string::npos)
					c++;
			}
		}
		if(c&&flag)
		{
			cout<<"Case #"<<u-t<<": Game has not completed\n";
		}
		else if(c==0&&flag)
		{
			cout<<"Case #"<<u-t<<": Draw\n";
		}
		getchar();
	}
}