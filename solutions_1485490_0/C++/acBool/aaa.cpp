//#include <iostream>
//#include <string.h>
//#include <string>
//#include <algorithm>
//#include <cstdio>
//#include <stdlib.h>
//using namespace std;
//const int N=1010;
//int num[N],father[N],visted[N][N],rootleft,rootright;
//void init(){
//	for(int i=1;i<N;++i)
//		father[i]=i;
//}
//int find(int x){
//	if(x!=father[x]){
//	  father[x]=find(father[x]);
//	}
//	return father[x];
//}
//bool unionset(int x,int y){
//	int rootx=find(x);
//	int rooty=find(y);
//	if(rootx!=rooty){
//	  father[rooty]=rootx;
//	  return false;
//	}
//	else{
//		rootleft=rootx;
//		rootright=rooty;
//		return true;
//	}
//}
//bool panduan(int x,int y){
//    bool flag=unionset(x,y);
//	if(flag)
//		return true;
//	else{
//	  return false;
//	}
//}
//int main(){
//	freopen("1.txt","r",stdin);
//	freopen("2.txt","w",stdout);
//	int numcase;
//	scanf("%d",&numcase);
//	for(int k=1;k<=numcase;++k){
//	  int n;
//	  scanf("%d",&n);
//	  init();
//	  rootleft=rootright=0;
//	  memset(visted,0,sizeof(visted));
//	  for(int i=1;i<N;++i)
//		  visted[i][i]=1;
//	  int x,y;
//	  bool flag=false,newflag=false;
//	  for(int i=1;i<=n;++i){
//	    scanf("%d",&x);
//		while(x--){
//		  scanf("%d",&y);
//		  visted[i][y]=1;
//		  flag=panduan(i,y);
//		  if(flag){
//			if(rootright==y)
//				continue;
//		    newflag=true;
//		  }
//		}
//	  }
//	  printf("Case #%d: ",k);
//	  if(newflag)puts("Yes");
//	  else
//		  puts("No");
//	}
//	return 0;
//}


//#include <iostream>
//#include <cstdio>
//#include <string.h>
//#include <vector>
//#include <queue>
//using namespace std;
//const int N=1010;
//int visted[N],num[N];
//vector<int> vv[N];
//bool bfs(int x){
//	queue<int> qq;
//	qq.push(x);
//	visted[x]=1;
//	num[x]=0;
//	int len=vv[x].size();
//	while(!qq.empty()){
//		int point=qq.front();
//		qq.pop();
//	    for(int i=0;i<vv[point].size();++i){
//	         int y=vv[point][i];
//			 qq.push(y);
//			 num[y]++;
//			 if(num[y]>1)
//			 {return true;}
//	    }
//	}
//	return false;
//}
//int main(){
//	//freopen("5.in","r",stdin);
//	//freopen("2.txt","w",stdout);
//	int numcase;
//	scanf("%d",&numcase);
//	for(int k=1;k<=numcase;++k){
//	  memset(vv,0,sizeof(vv));
//	  memset(visted,0,sizeof(visted));
//	  memset(num,0,sizeof(num));
//	  int n;
//	  scanf("%d",&n);
//	  int x,y;
//	  for(int i=1;i<=n;++i){
//	    scanf("%d",&x);
//		while(x--){
//		  scanf("%d",&y);
//		  vv[i].push_back(y);
//		}
//	  }
//	  bool flag=false;
//	  for(int i=1;i<=n;++i){
//		 memset(num,0,sizeof(num));
//	     flag=bfs(i);
//		 if(flag==true)
//			 break;
//	  }
//	  printf("Case #%d: ",k);
//	  if(flag)puts("Yes");
//	  else
//		  puts("No");
//	}
//	return 0;
//}


#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

const int MAX = 110;
struct node{
	__int64 id, len;
}numA[MAX], numB[MAX];
__int64 sum[MAX][MAX], dp[MAX][MAX], ans[MAX][MAX], up[MAX][MAX];
int min(int x,int y){
	if(x<y)
		return x;
	return y;
}
int max(int x,int y){
	if(x>y)
		return x;
	return y;
}
int main()
{
	freopen("6.in", "r", stdin);
	freopen("2.txt", "w", stdout);
	int N, M, numcase;
	scanf("%d", &numcase);
	for(int kk = 1;kk <= numcase; ++ kk)
	{
		memset(dp, 0, sizeof(dp));
		memset(up, 0, sizeof(up));
		memset(ans, 0, sizeof(ans));
		memset(sum,0,sizeof(sum));
		int i,j,k;
		for(i=0;i<MAX;++i){
			for(j=0;j<MAX;++j){
		  sum[i][j]=0;
		  ans[i][j]=0;
		  up[i][j]=0;
		  dp[i][j]=0;
			}
		}
		scanf("%d%d", &N, &M);
		for(i = 1;i <= N; ++ i)
			scanf("%lld%lld", &numA[i].len, &numA[i].id);
		for(i = 1;i <= M; ++ i)
			scanf("%lld%lld", &numB[i].len, &numB[i].id);
		for(i = 1;i <= N; ++ i){
			for(j = 1;j <= M; ++ j){
				sum[numA[i].id][j] = sum[numA[i].id][j - 1];
				if(numA[i].id == numB[j].id){
					sum[numA[i].id][j] += numB[j].len;
				}
			}
		}
		for(i = 1;i <= N; ++ i){
			for(j = 1;j <= M; ++ j){
				dp[i][j] = dp[i - 1][j];
				ans[i][j] = ans[i - 1][j];
				up[i][j] = up[i - 1][j];
				for(k = 1;k <= j; ++ k){
					__int64 dd = 0, temp = sum[numA[i].id][j] - sum[numA[i].id][k - 1];
					if(ans[i - 1][k - 1] == numA[i].id)
						temp += up[i - 1][k - 1];
					if(temp > numA[i].len)
						dd = temp - numA[i].len;
					temp = dp[i - 1][k - 1] + min(temp, numA[i].len);
					if(temp > dp[i][j]){
						dp[i][j] = temp;
						ans[i][j] = numA[i].id;
						up[i][j] = dd;
					}
				}
			}
		}
		printf("Case #%d: %I64d\n", kk, dp[N][M]);
	}
}