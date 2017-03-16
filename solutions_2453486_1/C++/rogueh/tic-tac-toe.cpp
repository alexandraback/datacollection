/**
Coded by:-   Rogue
**/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	bool flag, comp;
	string a[4];
	int i,j,k;
	int b[4][4];
	int cases,t;
	string str;
	cin>>cases;
	for(t=0; t<cases; t++)
	{
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		flag=false;
		comp=true;
		for(i=0; i<4; i++)
		{
			for(j=0; j<4; j++)
			{
				if(a[i][j]=='.')
				{
					comp=false;
					b[i][j]=0;
				}
				else if(a[i][j]=='T')
					b[i][j]=1;
				else if(a[i][j]=='O')
					b[i][j]=10;
				else
					b[i][j]=100;
			}
		}
		//Checking horizontally
		for(i=0; i<4; i++)
		{
			flag=false;
			for(k=0, j=0; j<4; j++)
				k+=b[i][j];
			if(k==301 || k==400 || k==31 || k==40)
			{
				flag=true;
				break;
			}
		}
		//checking vertically
		for(i=0; i<4 && !flag; i++)
		{
			for(k=0,j=0; j<4; j++)
				k+=b[j][i];
			if(k==301 || k==400 || k==31 || k==40)
			{
				flag=true;
				break;
			}
		}
		//checking diagonally
		if(!flag)
		{
			for(i=0,j=0,k=0; i<4 && !flag; i++, j++)
				k+=b[i][j];
			if(k==301 || k==400 || k==31 || k==40)
				flag=true;
		}
		if(!flag)
		{
			for(i=0,j=3,k=0; i<4 && !flag; i++,j--)
				k+=b[i][j];
			if(k==301 || k==400 || k==31 || k==40)
				flag=true;
		}
		if(flag)
		{
			if(k==31 || k==40)
				str="O won";
			else if(k==301 || k==400)
				str="X won";
			else
				str="Draw";
		}
		else
		{
			if(comp)
				str="Draw";
			else
				str="Game has not completed";
		}
		cout<<"Case #"<<t+1<<": "<<str<<endl;
	}
	return 0;
}

