#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
const int NUMBER=1010;
int mark[NUMBER],num[NUMBER];
vector<int> vv[NUMBER];
bool bfs(int x){
	queue<int> que;
	que.push(x);
	mark[x]=1;
	num[x]=0;
	int length=vv[x].size();
	while(!que.empty()){
		int point=que.front();
		que.pop();
	    for(int i=0;i<vv[point].size();++i){
	         int y=vv[point][i];
			 que.push(y);
			 num[y]++;
			 if(num[y]>1)
			 {return true;}
	    }
	}
	return false;
}
int main(){
	int numcase;
	scanf("%d",&numcase);
	for(int k=1;k<=numcase;++k){
	  memset(vv,0,sizeof(vv));
	  memset(mark,0,sizeof(mark));
	  memset(num,0,sizeof(num));
	  int n;
	  scanf("%d",&n);
	  int x,y;
	  for(int i=1;i<=n;++i){
	    scanf("%d",&x);
		while(x--){
		  scanf("%d",&y);
		  vv[i].push_back(y);
		}
	  }
	  bool flag=false;
	  for(int i=1;i<=n;++i){
		 memset(num,0,sizeof(num));
	     flag=bfs(i);
		 if(flag==true)
			 break;
	  }
	  printf("Case #%d: ",k);
	  if(flag)puts("Yes");
	  else
		  puts("No");
	}
	return 0;
}