//#pragma comment(linker, "/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
using namespace std;
#define ll long long
#define inf 1000000007
#define esp 0.000001
int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}
double max(double x,double y){return x>y?x:y;}
double min(double x,double y){return x<y?x:y;}
int abs(int x) {return x<0?-x:x;}
const int N=100005;
const int M=400005;
char mp[10][10];
bool judge(char ch)
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			if(mp[i][j]!=ch&&mp[i][j]!='T') break;
		if(j==4) return 1;
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			if(mp[j][i]!=ch&&mp[j][i]!='T') break;
		if(j==4) return 1;
	}
	for(i=0;i<4;i++)
		if(mp[i][i]!=ch&&mp[i][i]!='T') break;			
	if(i==4) return 1;
	for(i=0;i<4;i++)
		if(mp[i][3-i]!=ch&&mp[i][3-i]!='T') break;			
	if(i==4) return 1;
	return 0;
}
bool judge1()
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(mp[i][j]=='.') return 0;
	return 1;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.out","w",stdout);
    int i,j,k=1,tt;
	int n,m,t;
	scanf("%d",&tt);
	while(tt--)
	{
		for(i=0;i<4;i++)
			scanf("%s",mp[i]);
		printf("Case #%d: ",k++);
		if(judge('X')) printf("X won\n");
		else if(judge('O')) printf("O won\n");
		else if(judge1()) printf("Draw\n");
		else printf("Game has not completed\n");
	}
    return 0;
}