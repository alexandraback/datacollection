//============================================================================
// Name        : google2012-1C1.cpp
// Author      : ezhache
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char flag[1001];
int classes[1001][1000];

bool DFS(int p)
{
	flag[p]=1;
	for(int i=0;i<1000&&classes[p][i]!=0;i++)
	{
		if(flag[classes[p][i]]==1) return true;
		if(DFS(classes[p][i])==true) return true;
	}
	return false;
}


int main() {
	int round=0;
	int N,Nm,tmp;
	bool result;
	int i,j,k;
	cin >>round;
	for (i=1;i<=round;i++)
	{
		scanf("%d",&N);
		memset(classes,0,sizeof(int)*1000*1000);
		memset(flag,0,sizeof(char)*1000);
		for(j=1;j<=N;j++)
		{
			scanf("%d",&Nm);
			for(k=0;k<Nm;k++)
			{
				scanf("%d",&tmp);
				classes[j][k]=tmp;
			}
		}
		for(j=1;j<=N;j++)
		{
				if(flag[j]==0)
				{
					memset(flag,0,sizeof(char)*1000);
					result=DFS(j);
					if(result==true)
					{
						break;
					}
				}
		}
		cout<<"Case #"<<i<<": ";
		if(result==true)
		{
			cout<<"Yes";
		}
		else
		{
			cout<<"No";
		}
		cout<<endl;
	}

	return 0;
}
