#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#define SIZE 2005
#define MED 1005

using namespace std;
typedef pair <int,int> P;
typedef pair <P,string> PS;

string ans[SIZE][SIZE];
bool use[SIZE][SIZE];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

char dir(int x)
{
	if(x==0) return 'N';
	if(x==1) return 'E';
	if(x==2) return 'S';
	return 'W';
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		int x,y;
		scanf("%d %d",&x,&y);x+=MED;y+=MED;
		string ret="";
		if(x==0&&y==0) puts("");
		if(x>0)
		{
			for(int i=0;i<x;i++)
			{
				ret+='S';
				ret+='N';
			}
		}
		else
		{
			for(int i=0;i<abs(x);i++)
			{
				ret+='N';
				ret+='S';
			}
		}
		if(y>0)
		{
			for(int i=0;i<y;i++)
			{
				ret+='W';
				ret+='E';
			}
		}
		else
		{
			for(int i=0;i<abs(y);i++)
			{
				ret+='E';
				ret+='W';
			}
		}
		printf("%s\n",ret.c_str());
	}
	return 0;
}
