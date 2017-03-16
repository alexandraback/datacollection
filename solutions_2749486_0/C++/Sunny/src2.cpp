#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<cstdio>
#include <ctime>


using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))
#define istr(S) istringstream sin(S)
#define MP make_pair
#define pb push_back
#define inf 1000000000

#define maxn 10000005
#define off  300

typedef long long  LL;
//typedef __int64 LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

int dy[]={+1,-1,0,0};
int dx[]={0,0,+1,-1};
string dir="NSEW";

char res[600];
int X,Y,sol;
char seen[3*off+5][3*off+5][35];

void dfs(int x,int y,int moves)
{
	if(x==X && y==Y)
	{
		res[moves-1]-'\0';

		int xx=0,yy=0,tot=0;
		for(int i=0;i<moves-1;i++)
		{
			int m=(i+1);
			if(res[i]=='N') yy+=m;
			if(res[i]=='S') yy-=m;
			if(res[i]=='E') xx+=m;
			if(res[i]=='W') xx-=m;
			tot+=m;
			printf("%c",res[i]);
		}
		puts("");
		//if(xx==X && yy==Y) printf("%s\n",res);
		//if(tot>500) puts("xxx");
		sol=1;
		return;
	}

	if(abs(x)>off || abs(y)>off || moves>25) return;
	if(seen[x+off][y+off][moves]) return;

	int i;
	seen[x+off][y+off][moves]=1;
	for(i=0;i<4;i++)
	{
		int nx=x+dx[i]*moves;
		int ny=y+dy[i]*moves;
		res[moves-1]=dir[i];
		dfs(nx,ny,moves+1);
		if(sol) return;
	}
}



int main()
{
	int i,j,k,tests,cs=0,n;

	freopen("E:\\GCJ\\B-small-attempt3.in","r",stdin);
	freopen("E:\\GCJ\\B-small-attempt3.out","w",stdout);

	
	cin>>tests;

	while(tests--)
	{
		cin>>X>>Y;
		sol=0;
		MEM(seen,0);
		
		printf("Case #%d: ",++cs);
		dfs(0,0,1);
		if(sol==0) puts("-1");
	
	}
	for(;;);


	return 0;
} 
