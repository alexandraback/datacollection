#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;
int map[50][50];
FILE *fr,*fw;
void print(int mx,int my)
{
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			if(map[i][j]==-1)fprintf(fw,"*");
			if(map[i][j]==0)fprintf(fw,".");
			if(map[i][j]==1)fprintf(fw,"c");
		}
		fprintf(fw,"\n");
	}
}
void imp()
{
	fprintf(fw,"Impossible\n");
}
int main()
{
	fr=fopen("C-large.in","r");
	fw=fopen("out1.txt","w");
	int data;
	fscanf(fr,"%d",&data);
	for(int p=0;p<data;p++)
	{
		fprintf(fw,"Case #%d:\n",p+1);
		int mx,my,mine;
		fscanf(fr,"%d%d%d",&mx,&my,&mine);
		for(int i=0;i<mx;i++)
		{
			for(int j=0;j<my;j++)
			{
				map[i][j]=-1;
			}
		}
		if(mx*my-mine==1)
		{
			map[0][0]=1;
			print(mx,my);
			continue;
		}
		if(mx==1)
		{
			for(int i=mine;i<my-1;i++)
			{
				map[0][i]=0;
			}
			map[0][my-1]=1;
			print(mx,my);
			continue;
		}
		if(my==1)
		{
			for(int i=mine;i<mx-1;i++)
			{
				map[i][0]=0;
			}
			map[mx-1][0]=1;
			print(mx,my);
			continue;
		}
		if(mx==2)
		{
			if(mine%2==1||mx*my-mine==2)
			{
				imp();
				continue;
			}
			for(int i=0;i<my-mine/2;i++)
			{
				map[0][i]=map[1][i]=0;
			}
			map[0][0]=1;
			print(mx,my);
			continue;
		}
		if(my==2)
		{
			if(mine%2==1||mx*my-mine==2)
			{
				imp();
				continue;
			}
			for(int i=0;i<mx-mine/2;i++)
			{
				map[i][0]=map[i][1]=0;
			}
			map[0][0]=1;
			print(mx,my);
			continue;
		}
		int emp=mx*my-mine;
		if(emp==2||emp==3||emp==5||emp==7)
		{
			imp();
			continue;
		}
		int ay=max(3,(emp+(mx-1))/mx);
		for(int i=0;i<mx;i++)
		{
			if(emp>ay*2)
			{
				for(int j=0;j<ay;j++)
				{
					map[i][j]=0;
				}
				emp-=ay;
			}
			else
			{
				if(emp==ay+1)
				{
					for(int j=0;j<ay-1;j++)
					{
						map[i][j]=0;
					}
					map[i+1][0]=map[i+1][1]=0;
				}
				else
				{
					for(int j=0;j<ay;j++)
					{
						map[i][j]=0;
					}
					for(int j=ay;j<emp;j++)
					{
						map[i+1][j-ay]=0;
					}
				}
				break;
			}
		}
		map[0][0]=1;
		print(mx,my);
	}
}