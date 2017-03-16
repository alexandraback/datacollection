#include<iostream>
#include<cstdio>
using namespace std;

bool check(string a[],char c)
{
	for(int i=0;i<4;i++)
	{
		int c1=0,c2=0;
		for(int j=0;j<4;j++)
		{
			if(a[i][j]==c)
			c1++;
			if(a[i][j]=='T')
			c2++;
		}
		if(c1==4)
		return true;
		else if((c1==3)&&(c2==1))
		return true;
	}
	for(int i=0;i<4;i++)
	{
		int c1=0,c2=0;
		for(int j=0;j<4;j++)
		{
			if(a[j][i]==c)
			c1++;
			if(a[j][i]=='T')
			c2++;
		}
		if(c1==4)
		return true;
		else if((c1==3)&&(c2==1))
		return true;
	}
	int c1=0,c2=0;
	for(int i=0;i<4;i++)
	{
		if(a[i][i]==c)
		c1++;
		if(a[i][i]=='T')
		c2++;
		
		
	}
	if(c1==4)
	return true;
	else if((c1==3)&&(c2==1))
	return true;
	c1=0,c2=0;
	for(int i=0;i<4;i++)
	{
		if(a[i][4-i-1]==c)
		c1++;
		if(a[i][4-i-1]=='T')
		c2++;
		
		
	}
	if(c1==4)
	return true;
	else if((c1==3)&&(c2==1))
	return true;
	return false;
}
int main()
{
	
	int t;
	cin>>t;
	int q=0;
	while(t--)
	{
		q++;
		string a[4];
		for(int i=0;i<4;i++)
		cin>>a[i];
		bool p=check(a,'X');
		bool p1=check(a,'O');
		int r=0;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			if(a[i][j]=='.')
			r++;
		}
		if((p)&&(!p1))
		cout<<"Case #"<<q<<": X won"<<endl;
		else if((!p)&&p1)
		cout<<"Case #"<<q<<": O won"<<endl;
		else if(!p&&!p1&&r==0)
		cout<<"Case #"<<q<<": Draw"<<endl;
		else
		cout<<"Case #"<<q<<": Game has not completed"<<endl;
		
	}
	return 0;
}
