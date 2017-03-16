#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;

bool checkx(char arr[4][4])
{
int i,j,x;
	for(i=0;i<4;i++)
	{
	x=0;
		for(j=0;j<4;j++)
		{
		if(arr[i][j]=='X' || arr[i][j]=='T')
		x++;
		}
		if(x==4)
		return true;

	}

	for(i=0;i<4;i++)
	{
		x=0;
		for(j=0;j<4;j++)
		{
		if(arr[j][i]=='X' || arr[j][i]=='T')
		x++;
		}
		if(x==4)
		return true;

	}
	
	x=0;
	for(i=0;i<4;i++)
	{
	if(arr[i][i]=='X' || arr[i][i]=='T')
	x++;
	}
	if(x==4)
	return true;
	
	x=0;
	
	for(i=3;i>=0;i--)
	{
	if(arr[i][3-i]=='X' || arr[i][3-i]=='T')
	x++;
	if(x==4)
	return true;
	}
	return false;
}

bool checko(char arr[4][4])
{
int i,j,x;
	for(i=0;i<4;i++)
	{
	x=0;
		for(j=0;j<4;j++)
		{
		if(arr[i][j]=='O' || arr[i][j]=='T')
		x++;
		}
		if(x==4)
		return true;
	}

	for(i=0;i<4;i++)
	{
		x=0;
		for(j=0;j<4;j++)
		{
		if(arr[j][i]=='O' || arr[j][i]=='T')
		x++;
		}
		if(x==4)
		return true;
	}
	
	x=0;
	for(i=0;i<4;i++)
	{
	if(arr[i][i]=='O' || arr[i][i]=='T')
	x++;
	}
	if(x==4)
	return true;
	
	x=0;
	
	for(i=3;i>=0;i--)
	{
	if(arr[i][3-i]=='O' || arr[i][3-i]=='T')
	x++;
	if(x==4)
	return true;
	}
	
	return false;
}

bool gameincomplete(char arr[4][4])
{
int x=0,i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
		if(arr[i][j]=='.')
		x++;
		}
		if(x>0)
		return true;
	}		
return false;
}


int main()
{
int n,i,j,k;
scanf("%d",&n);
for(k=1;k<=n;k++)
{
	char arr[4][4];

	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	cin>>arr[i][j];
	bool chkx,chko,chkinc;
	chkx=checkx(arr);
	chko=checko(arr);
	chkinc=gameincomplete(arr);
	if(chkx==true)
	cout<<"Case #"<<k<<": X won\n";
	else if(chko==true)
	cout<<"Case #"<<k<<": O won\n";
	else if(chkinc==true)
	cout<<"Case #"<<k<<": Game has not completed\n";
	else
	cout<<"Case #"<<k<<": Draw\n";
}
return 0;
}
