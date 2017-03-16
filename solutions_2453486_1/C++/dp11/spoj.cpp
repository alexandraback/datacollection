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
char A[4][4];
void Solve()
{
	int dots=0;
	map<char,int> mymap;
	mymap['X']=mymap['O']=mymap['.']=mymap['T']=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(A[i][j]=='.')
				dots=1;
			mymap[A[i][j]]++;
			if(j==3)
			{
				if(mymap['X']+mymap['T']==4)
				{
					printf("X won\n");
					return;
				}
				if(mymap['O']+mymap['T']==4)
				{
					printf("O won\n");
					return;
				}
				mymap['X']=mymap['O']=mymap['.']=mymap['T']=0;
			}
		}
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(A[j][i]=='.')
				dots=1;
			mymap[A[j][i]]++;
			if(j==3)
			{
				if(mymap['X']+mymap['T']==4)
				{
					printf("X won\n");
					return;
				}
				if(mymap['O']+mymap['T']==4)
				{
					printf("O won\n");
					return;
				}
				mymap['X']=mymap['O']=mymap['.']=mymap['T']=0;
			}
		}
	mymap[A[0][0]]++;
	mymap[A[1][1]]++;
	mymap[A[2][2]]++;
	mymap[A[3][3]]++;
	if(mymap['X']+mymap['T']==4)
	{
		printf("X won\n");
		return;
	}
	if(mymap['O']+mymap['T']==4)
	{
		printf("O won\n");
		return;
	}
	mymap['X']=mymap['O']=mymap['.']=mymap['T']=0;
	
	mymap[A[3][0]]++;
	mymap[A[2][1]]++;
	mymap[A[1][2]]++;
	mymap[A[0][3]]++;
	if(mymap['X']+mymap['T']==4)
	{
		printf("X won\n");
		return;
	}
	if(mymap['O']+mymap['T']==4)
	{
		printf("O won\n");
		return;
	}
	
	if(dots==1)
		printf("Game has not completed\n");
	else
		printf("Draw\n");
}
int main()
{
	int test;
	scanf("%d",&test);
	for(int tes=1;tes<=test;tes++)
	{
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				scanf(" %c",&A[i][j]);
		printf("Case #%d: ",tes);
		Solve();
	}
	return 0;
}