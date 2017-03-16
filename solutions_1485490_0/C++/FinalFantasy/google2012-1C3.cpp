//============================================================================
// Name        : google2012-1C3.cpp
// Author      : ezhache
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int64_t largest;
int64_t boxes[100][2];
int64_t toys[100][2];


void DFS(int n, int64_t uN, int m, int64_t uM, int64_t sum)
{
	//cout<<"n: "<<n<<" "<<uN<<" m: "<<m<<" "<<uM<<" sum: "<<sum<<endl;
	int64_t tmp;
	if(boxes[n][1]==toys[m][1])
	{
		tmp=uN<uM?uN:uM;
		sum+=tmp;
		uN-=tmp;
		uM-=tmp;
		if(uN==0)
		{
			if(boxes[n+1][0]!=0)
			DFS(n+1,boxes[n+1][0],m,uM,sum);
		}
		else
		{
			if(toys[m+1][0]!=0)
			DFS(n,uN,m+1,toys[m+1][0],sum);
		}
	}
	else
	{
		if(boxes[n+1][0]!=0)
			DFS(n+1,boxes[n+1][0],m,uM,sum);
		if(toys[m+1][0]!=0)
			DFS(n,uN,m+1,toys[m+1][0],sum);
	}

	if(boxes[n+1][0]==0||toys[m+1][0]==0)
	{
		if(sum>largest)
		{
			largest=sum;
			//cout<<sum<<endl;
		}

	}
}


int main() {
	int round=0;
	int N,M;
	int i,j;
	double tmp;
	cin >>round;
	for (i=1;i<=round;i++)
	{
		scanf("%d %d",&N,&M);
		largest=0;
		memset(boxes,0,sizeof(int64_t)*100*2);
		memset(toys,0,sizeof(int64_t)*100*2);
		for(j=0;j<N;j++)
		{
			scanf("%lf %d",&tmp,&boxes[j][1]);
			boxes[j][0]=tmp;
			//cout<<boxes[j][0]<<" ";
		}
		//cout<<endl;
		for(j=0;j<M;j++)
		{
			scanf("%lf %d",&tmp,&toys[j][1]);
			toys[j][0]=tmp;
		}
		DFS(0,boxes[0][0],0,toys[0][0],0);
		cout<<"Case #"<<i<<": "<<largest<<endl;
	}

	return 0;
}

