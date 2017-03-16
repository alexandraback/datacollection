#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<string>
#define REP(it,end) for (int it = 1; it <= (end); it++)
#define FOR(it,begin,end) for (int it = (begin); it <= (end); it++)
#define ROF(it,begin,end) for (int it = (begin); it >= (end); it--)
using namespace std;
bool ans[5][5][5];
int main()
{
	memset(ans,true,sizeof(ans));
	//1*1
	ans[1][1][1]=false;
	//1*2
	ans[1][1][2]=false;
	ans[2][1][2]=false;
	//1*3
	ans[1][1][3]=false;
	ans[2][1][3]=true;
	ans[3][1][3]=true;
	//1*4
	ans[1][1][4]=false;
	ans[2][1][4]=false;
	ans[3][1][4]=true;
	ans[4][1][4]=true;
	//2*2
	ans[1][2][2]=false;
	ans[2][2][2]=false;
	ans[3][2][2]=true;
	ans[4][2][2]=true;
	//2*3
	ans[1][2][3]=false;
	ans[2][2][3]=false;
	ans[3][2][3]=false;
	ans[4][2][3]=true;
	//2*4
	ans[1][2][4]=false;
	ans[2][2][4]=false;
	ans[3][2][4]=true;
	ans[4][2][4]=true;//special
	//3*3
	ans[1][3][3]=false;
	ans[2][3][3]=true;
	ans[3][3][3]=false;
	ans[4][3][3]=true;
	//3*4
	ans[1][3][4]=false;
	ans[2][3][4]=false;
	ans[3][3][4]=true;
	ans[4][3][4]=false;
	//4*4
	ans[1][4][4]=false;
	ans[2][4][4]=false;
	ans[3][4][4]=true;
	ans[4][4][4]=false;
	//for(int i=1;i<=4;i++,cout <<endl)for(int j=1;j<=4;j++,cout <<endl)for(int k=1;k<=4;k++)cout <<ans[i][j][k]<<" ";
	int T,x,r,c;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		scanf("%d %d %d",&x,&r,&c);
		if(r>c)swap(r,c);
		if(!ans[x][r][c])printf("Case #%d: GABRIEL\n",cas);
		else printf("Case #%d: RICHARD\n",cas);
	}
	return 0;
}
