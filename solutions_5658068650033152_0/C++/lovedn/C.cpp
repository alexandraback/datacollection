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

int mat[30][30];
bool vis[30][30];

const int dx[]={
	-1,1,0,0
};
const int dy[]={
	0,0,-1,1
};

int n,m;
int bfs(int x,int y){
	bool j=true;
	queue<pair<int,int> > que;
	que.push(make_pair(x,y));
	vis[x][y]=true;
	if(x==0||x==n-1||y==0||y==m-1)j=false;
	int s=1;
	while(!que.empty()){
		pair<int,int> u=que.front();
		que.pop();
		pair<int,int> v;
		for(int k=0;k<4;k++){
			v.first=u.first+dx[k];
			v.second=u.second+dy[k];
			if(v.first<0||v.first>=n||v.second<0||v.second>=m)continue;
			if(mat[v.first][v.second]==1||vis[v.first][v.second])continue;
			vis[v.first][v.second]=true;
			if(v.first==0||v.first==n-1||v.second==0||v.second==m-1)j=false;
			que.push(v);
			s++;
		}
	}
	if(j)return s;
	return 0;
}

int ans[25][25][25];
int main(){
	freopen("C-small-attempt2.in","r",stdin);
	freopen("C1.out","w",stdout);
	int k;
	int test;
	scanf("%d",&test);
	
	for(int i=1;i<=20;i++){
		for(int j=1;j<=20;j++){
			for(int k=1;k<=20;k++){
				ans[i][j][k]=(1<<30);
			}
		}
	}
	
	int ct=0;
	while(test--){
		scanf("%d%d%d",&n,&m,&k);
		
		int tot=(n*m);
		int ret=tot;
		for(int i=k;i<=n*m;i++){
			ret=min(ret,ans[n][m][i]);
		}
		if(ret!=(1<<30)){
			printf("Case #%d: %d\n",++ct,ret);
			continue;
		}
		
		for(int i=33;i<(1<<tot);i++){
			//cout<<i<<endl;
			memset(mat,0,sizeof(mat));
			memset(vis,0,sizeof(vis));
			
			int sum=0;
			for(int j=0;j<tot;j++){
				if((1<<j)&i){
					sum++;
					mat[j/m][j%m]=1;
				}
			}
			int chess=sum;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(!mat[i][j]&&!vis[i][j]){
						sum+=bfs(i,j);
					}
				}
			}
			if(sum>=k){
				ret=min(ret,chess);
			}
		}
		printf("Case #%d: %d\n",++ct,ret);
	}
	
	return 0;
}