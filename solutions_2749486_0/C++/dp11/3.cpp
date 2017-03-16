#include"stdio.h"
#include"vector"
#include"set"
#include"map"
#include"assert.h"
#include"algorithm"
#include"math.h"
#include"stdlib.h"
#include"string.h"
#include"string"
#include<utility>
#include<queue>
using namespace std;
typedef unsigned int ui;
typedef long long int ll;
typedef unsigned long long int ull;
#define REP(i,n) for(unsigned int i=0;i<(n);i++)
#define LOOP(i,x,n) for(int i=(x);i<(n);i++)
#define ALL(v) v.begin(),v.end()
#define FOREACH(it,v)   for(typeof((v).begin()) it=(v).begin();it != (v).end();it++)
#define i(x) scanf("%d",&x)
#define u(x) scanf("%u",&x)
#define l(x) scanf("%lld",&x)
#define ul(x) scanf("%lld",&x)
int dp[201][201],mov;
char str[201][201][601];
char temp[601],x[601];
char t[601];
pair<int,int> mypair,you;
int timepass(int s,int i,int j,int mov)
{
	strcpy(t,"");
	if(s==0)
		return 0;
	else
	{
		if(i+mov-1<201 && i-mov+4>=0)
		{
			for(int a=0;a<s;a++)
				strcat(t,"EWWE");
			return 0;
		}
		else if(i-mov+1>=0 && i+mov-4<201)
		{
			strcat(t,"WEEW");
			return 0;
		}
		else if(j+mov-1<201 && j-mov+4>=0)
		{
			strcat(t,"SNNS");
			return 0;
		}
		else if(j-mov+1>=0 && j+mov-4<201)
		{
			strcat(t,"NSSN");
			return 0;
		}
	}
	return 1;
}
void constant()
{
	strcat(t,"");
	queue<pair<int,int> > myqueue;
	for(int i=0;i<201;i++)
		for(int j=0;j<201;j++)	
		{
			dp[i][j]=1000000000;
			strcpy(str[i][j],"");
		}
	dp[100][100]=0;
	myqueue.push(make_pair(100,100));
	int i,j;
	while(!myqueue.empty())
	{	
		you= myqueue.front();
		myqueue.pop();
		i=you.first;
		j=you.second;
		for(int s=dp[i][j];s<=dp[i][j];s+=4)
		{
			mov=s+1;
			if(i+mov<201 && dp[i+mov][j]>dp[i][j]+1)
			{	
				//if(timepass((s-dp[i][j])/4,i,j,mov)==0)
				{
					dp[i+mov][j]=dp[i][j]+1;
					strcpy(temp,str[i][j]);
					strcat(temp,t);
					strcat(temp,"W");
					strcpy(str[i+mov][j],temp);
					myqueue.push(make_pair(i+mov,j));
				}
			}
			if(i-mov>=0 && dp[i-mov][j]>dp[i][j]+1)
			{
				//if(timepass((s-dp[i][j])/4,i,j,mov)==0)
				{
				dp[i-mov][j]=dp[i][j]+1;
				strcpy(temp,str[i][j]);
				strcat(temp,t);
				strcat(temp,"E");
				strcpy(str[i-mov][j],temp);
				myqueue.push(make_pair(i-mov,j));
				}
			}
			if(j+mov<201 && dp[i][j+mov]>dp[i][j]+1)
			{
				//if(timepass((s-dp[i][j])/4,i,j,mov)==0)
				{
				dp[i][j+mov]=dp[i][j]+1;
				strcpy(temp,str[i][j]);
				strcat(temp,t);
				strcat(temp,"N");
				strcpy(str[i][j+mov],temp);
				myqueue.push(make_pair(i,j+mov));
				}
			}
			if(j-mov>=0 && dp[i][j-mov]>dp[i][j]+1)
			{
				//if(timepass((s-dp[i][j])/4,i,j,mov)==0)
				{
				dp[i][j-mov]=dp[i][j]+1;
				strcpy(temp,str[i][j]);
				strcat(temp,t);
				strcat(temp,"S");
				strcpy(str[i][j-mov],temp);
				myqueue.push(make_pair(i,j-mov));
				}
			}
		}
	}
}
int main()
{
	int div;
	constant();
	int test,X,Y;
	scanf("%d",&test);
	for(int tes=1;tes<=test;tes++)
	{
		scanf("%d%d",&X,&Y);
		//if(dp[X+100][Y+100]!=1000000000)
		printf("Case #%d: %s\n",tes,str[X+100][Y+100]);
		//else 
		{	
			
		}
	}
	return 0;
}