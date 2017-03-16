#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<complex>
#define EPS (1e-10)
#define PI (3.141592653589793238)
#define MP make_pair
typedef long long ll;
using namespace std;

#define MAX 987654321
#define TYPE pair<int,pair<int,int> >

int h,xx,yy;
int ten[200][200];
int yuka[200][200];

int dp[200][200];
bool check[200][200];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(void){
	int casenum;
	scanf("%d",&casenum);
	for(int casecnt=1;casecnt<=casenum;casecnt++){

		int h,xx,yy;
		scanf("%d %d %d",&h,&yy,&xx);
		for(int j=0;j<yy;j++)for(int i=0;i<xx;i++)scanf("%d",&ten[i][j]);
		for(int j=0;j<yy;j++)for(int i=0;i<xx;i++)scanf("%d",&yuka[i][j]);
		for(int j=0;j<yy;j++)for(int i=0;i<xx;i++){
			dp[i][j]=MAX;
			check[i][j]=false;
		}

		priority_queue< TYPE , vector< TYPE > , greater< TYPE > > qu;
		dp[0][0]=0;
		qu.push(MP(0,MP(0,0)));
		while(qu.size()){
			int t=qu.top().first;
			int x=qu.top().second.first;
			int y=qu.top().second.second;
			qu.pop();

			if(dp[x][y]<t)continue;
			if(check[x][y])continue;
			check[x][y]=true;

			if(x==xx-1 && y==yy-1)break;

			for(int k=0;k<4;k++){
				int nx=x+dx[k];
				int ny=y+dy[k];

				if(!(0<=nx && nx<xx && 0<=ny && ny<yy))continue;
				if(check[nx][ny])continue;

				if(!(yuka[x][y]+50<=ten[nx][ny]))continue;
				if(!(yuka[nx][ny]+50<=ten[nx][ny]))continue;
				if(!(yuka[nx][ny]+50<=ten[x][y]))continue;

				int nt=max(t,h-(ten[nx][ny]-50));
				if(nt!=0){
					if(yuka[x][y]+20<=h-nt)nt+=10;
					else nt+=100;
				}

				if(nt<dp[nx][ny]){
					dp[nx][ny]=nt;
					qu.push(MP(nt,MP(nx,ny)));
				}
			}
		}
		
		printf("Case #%d: %.10f\n",casecnt,(double)dp[xx-1][yy-1]/10);
		fflush(stdout);
	}
	return 0;
}
