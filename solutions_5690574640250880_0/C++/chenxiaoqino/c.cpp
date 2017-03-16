#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int board[52][52];

//All mine in corner
int canbuild1(int m,int r,int c)
{
	if(m<3)return false;
	if(r<3)return false;
	int maxc=(m-2)*(r-2);
	//maxc+=2;
	//cout<<"cb1maxc"<<maxc<<endl;
	if(c<=maxc)return true;
return false;
}
int build1(int m,int r,int c)
{
int i,j;
for(i=1;i<=(m-2);i++)
for(j=1;j<=(r-2);j++)
{
	if(c>0)
	{board[i][j]=1;c--;}
}
	i=1;j=r-1;
	if(c>0)
	{board[i][j]=1;c--;}
	
	i=m-1;j=1;
	if(c>0)
	{board[i][j]=1;c--;}
	
	board[m][r]=2;

return false;
}

int canbuild2(int m,int r,int c)
{
	if(m>1&&r>1)return false;

	if(m<r)m=r;
	if(c==m)return false;
	return true;
}
int build2(int m,int r,int c)
{
	int i;
	if(m>1)
	{
		for(i=1;i<=c;i++)
			board[i][1]=1;
		board[m][1]=2;
	}
	else
	{
		for(i=1;i<=c;i++)
			board[1][i]=1;
		board[1][r]=2;
	}
return false;	
}


int canbuild3(int m,int r,int c)
{
	if(m<3||r<3)return false;
	int rowlen,collen,maxc;
	collen=m>r?m:r;//longer
	rowlen=m<r?m:r;//smaller
	
	maxc=rowlen*(collen-2);
	if(c==maxc-1)return false;
	//if(rowlen>2)maxc+=2;
	if(c>maxc)return false;
	else
	return true;
}
int build3(int m,int r,int c)
{
int i,j;
if(m>r)
{
	for(i=1;i<=(m-2);i++)
	for(j=1;j<=r;j++)
	{
		if(c>0)
		{
			if(c==1&&j==r-1)
			{
			board[i+1][1]=1;
			c--;
			goto outloop1;}
		board[i][j]=1;c--;}
	}
	outloop1:
	board[m][2]=2;
	/*
	i=m-1;j=1;
	if(c>0)
	{board[i][j]=1;c--;}
	if(r>2)
	{
		i=m-1;j=r;
		if(c>0)
		{board[i][j]=1;c--;}		
	}*/
}
else//m<=r
{
	for(j=1;j<=(r-2);j++)
	for(i=1;i<=m;i++)
	{
		if(c>0)
		{
			if(c==1&&i==m-1)
			{
			board[1][j+1]=1;
			c--;
			goto outloop2;}
		board[i][j]=1;c--;}
	}
	outloop2:
	board[2][r]=2;
	/*
	i=1;j=r-1;
	if(c>0)
	{board[i][j]=1;c--;}
	if(m>2)
	{
		i=m;j=r-1;
		if(c>0)
		{board[i][j]=1;c--;}		
	}*/
}

return true;
}

int canbuild4(int m,int r,int c)
{
if(c==m*r-1)return true;
if(m<3||r<3)return false;
if(c==m*r-2)return false;
if(c==m*r-3)return false;

int remspace=m*r-c;
if(remspace>=4&&(remspace%2==0))
	return true;
if(remspace>=9&&(remspace%2==1))
	return true;
return false;
}
int build4(int m,int r,int c)
{
int i,j,k;
for(i=1;i<=m;i++)
for(j=1;j<=r;j++)
	board[i][j]=1;

int remspace=m*r-c;
if(remspace==1){
board[1][1]=2;return true;}
if(remspace%2==0)
{
	k=remspace/2;
	for(i=1;i<=k;i++)
	{board[i][1]=0;board[i][2]=0;}
	board[1][1]=2;return true;
}
else//remspace-3==2x
{
	k=(remspace-3)/2;
	for(i=1;i<=k;i++)
	{board[i][1]=0;board[i][2]=0;}
	board[1][3]=0;board[2][3]=0;board[3][3]=0;
	board[1][1]=2;return true;
}
return false;
}

int canbuild5(int m,int r,int c)
{
	if(m!=2&&r!=2)return false;
	
int remspace=m*r-c;
//cout<<"bu5rem:"<<remspace<<endl;
	if(remspace==1)return true;
	if(remspace==2)return false;
	if(remspace==3)return false;
	if(remspace%2==0)return true;
	return false;
}
int build5(int m,int r,int c)
{
int i,j,k;
for(i=1;i<=m;i++)
for(j=1;j<=r;j++)
	board[i][j]=1;

int remspace=m*r-c;
if(remspace==1){
board[1][1]=2;return true;}
if(m==2)
{
	k=remspace/2;
	for(j=1;j<=k;j++)
	{board[1][j]=0;board[2][j]=0;}
	board[1][1]=2;return true;
}
else//r==2
{
	k=remspace/2;
	for(i=1;i<=k;i++)
	{board[i][1]=0;board[i][2]=0;}
	board[1][1]=2;return true;
}
return false;
}

int build(int m,int r,int c)
{
memset(board,0,sizeof(board));
if(c>=m*r)return false;

	if(canbuild1(m,r,c))
		return 1+build1(m,r,c);
	if(canbuild2(m,r,c))
		return 1+build2(m,r,c);
	if(canbuild3(m,r,c))
		return 1+build3(m,r,c);
	if(canbuild4(m,r,c))
		return 1+build4(m,r,c);
	if(canbuild5(m,r,c))
		return 1+build5(m,r,c);

return false;
}

void printboard(int m,int r)
{
int i,j;
for(i=1;i<=(m);i++)
{
	for(j=1;j<=(r);j++)
	{
		if(board[i][j]==0)cout<<'.';
		if(board[i][j]==1)cout<<'*';
		if(board[i][j]==2)cout<<'c';
	}
	cout<<endl;
}
return;
}

int main()
{
int ti,T;scanf("%d",&T);
for(ti=0;ti<T;ti++)
{
	int m,r,c,ans;
	scanf("%d %d %d",&m,&r,&c);
	printf("Case #%d:\n",ti+1);
	ans=build(m,r,c);
	if(ans>0) printboard(m,r);
	else cout<<"Impossible"<<endl;
}
return 0;
}