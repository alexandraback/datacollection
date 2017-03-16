//UESTC_L3

#include <stdexcept>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>
#include <locale>
#include <sstream>
#include <set>
#include <list>
#include <bitset>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <functional>
#include <complex>
#include <valarray>
using namespace std;

char mat[5][5];

const int dx[]={
	-1,-1,-1,0,0,1,1,1
};
const int dy[]={
	-1,0,1,-1,1,-1,0,1
};

void init(int r,int c,int st){
	memset(mat,0,sizeof(mat));
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(st&(1<<(i*c+j)))mat[i][j]='*';
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(mat[i][j]=='*')continue;
			int sum=0;
			for(int k=0;k<8;k++){
				int fx=i+dx[k];
				int fy=j+dy[k];
				if(fx<0||fx>=r||fy<0||fy>=c)continue;
				if(mat[fx][fy]=='*'){
					sum++;
				}
			}
			mat[i][j]='0'+sum;
		}
	}
}

bool vis[5][5];
bool judge(int r,int c,int x,int y){
	if(mat[x][y]=='*')return false;
	
	memset(vis,0,sizeof(vis));
	vis[x][y]=true;
	
	queue<pair<int,int> > que;
	que.push(make_pair(x,y));
	while(!que.empty()){
		pair<int,int> u=que.front();
		que.pop();
		if(mat[u.first][u.second]!='0')continue;
		
		int fx,fy;
		for(int i=0;i<8;i++){
			fx=u.first+dx[i];
			fy=u.second+dy[i];
			if(fx<0||fx>=r||fy<0||fy>=c)continue;
			if(vis[fx][fy]||mat[fx][fy]=='*')continue;
			vis[fx][fy]=true;
			que.push(make_pair(fx,fy));
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(mat[i][j]!='*'&&!vis[i][j])return false;
		}
	}
	return true;
}

void out(int r,int c,int st,int x,int y){
	mat[x][y]='c';
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(st&(1<<(i*c+j)))printf("*");
			else if(i==x&&j==y)printf("c");
			else printf(".");
		}
		printf("\n");
	}
}

int main()
{
	freopen("C-small-attempt2.in","r",stdin);
	freopen("out.out","w",stdout);
	
	int test;
	scanf("%d",&test);
	int ct=0;
	while(test--){
		int r,c,m;
		scanf("%d%d%d",&r,&c,&m);
		int tot=r*c;
		
		printf("Case #%d:\n",++ct);
		
		bool ret=false;
		for(int i=0;i<(1<<tot)&&!ret;i++){
			int bit=0;
			for(int j=0;j<tot;j++){
				if((1<<j)&i)bit++;
			}
			if(bit!=m)continue;
			
			init(r,c,i);
			for(int x=0;x<r&&!ret;x++){
				for(int y=0;y<c;y++){
					if(judge(r,c,x,y)){
						ret=true;
						out(r,c,i,x,y);
						break;
					}
				}
			}			
		}
		if(!ret)printf("Impossible\n");
	}
	return 0;
}