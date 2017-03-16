#include<unistd.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#define BSIZE 1<<15
using namespace std;
int r,c,narkes;
bool yes=false;
bool valid(int i,int j)
{
  if((i>-1)&&(j>-1)&&(i<r)&&(j<c)) return true;
  else return false;
}

bool check(int com[])
{
  pair<int,int> e,a;
  queue<pair<int,int> > Q;
  e.first=-1;
  int square[r][c];
  bool visited[r][c];
  for(int i=0;i<r;i++) for(int j=0;j<c;j++) visited[i][j]=false;
  int numbers=0;int zeros=r*c;
  int x,y,m=0;
  for(int i=0;i<r;i++) for(int j=0;j<c;j++)
      if(m==narkes) {square[i][j]=0;}
      else if(com[m]==(j+i*c)) {zeros--;square[i][j]=-1;m++;}
      else square[i][j]=0;
  for(int d=0;d<narkes;d++)
  {
    x=com[d]/c;y=com[d]%c;
    for(int k=-1;k<=+1;k++) for(int l=-1;l<=+1;l++)
    if(valid(x+k,y+l)) 
      if(square[x+k][y+l]==0) {square[x+k][y+l]=1;numbers++;zeros--;}
    
  }

  //if(yes){for(int i=0;i<r;i++) {for(int j=0;j<c;j++){cout<<square[i][j]; }cout<<endl;}
  //exit(1);}
  for(int i=0;i<r;i++) for(int j=0;j<c;j++){if(square[i][j]==0) {e.first=i;e.second=j;break;} }
  if(e.first<0) return false;
  zeros--;
  visited[e.first][e.second]=true;
  a=e;
  Q.push(e);
  while(!Q.empty())
  {
    e = Q.front();
    Q.pop();
    for(int k=-1;k<=1;k++) for(int l=-1;l<=1;l++)
    {
      
      x=e.first+k;y=e.second+l;
      if(valid(x,y)) if(!visited[x][y])
      {
	visited[x][y]=true;
	if(square[x][y]==0) 
	{
	  zeros--;
	  e.first=x;e.second=y;Q.push(e);
	}
	else if(square[x][y]>0)
	{
	  numbers--;
	}
      }
    }
  }
  if((numbers==0)&&(zeros==0))
  {
    for(int i=0;i<r;i++){for(int j=0;j<c;j++)
      if(square[i][j]==-1)
	cout<<"*";
      else if((i==a.first)&&(j==a.second))
	cout<<"c";
      else cout<<".";cout<<endl;}
      return true;
    
  }
  return false;
}

//combinations
void s(int n, int k) 
{
  int com[k];
  for (int i = 0; i < k; i++) com[i] = i;
  while (com[k - 1] < n) 
  {
    if(check(com)) return ;
    int t = k - 1;
    while (t != 0 && com[t] == n - k + t) t--;
    com[t]++;
    for (int i = t + 1; i < k; i++) com[i] = com[i - 1] + 1;
  }
  cout<<"Impossible"<<endl;
}

void solver()
{
  cin>>r>>c>>narkes;
  if(narkes==r*c-1) 
  {
    int cnt=1;
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++)
      if(cnt==r*c) cout<<"c"; else {cnt++;cout<<"*";} cout<<endl;}
  }
  else if(narkes==0) 
  {
    int cnt=1;
    for(int i=0;i<r;i++)
    {
      for(int j=0;j<c;j++)
	if(cnt==r*c)
	  {  cout<<"c";}
	else 
	  {cnt++;cout<<".";}
     cout<<endl;
    }
  }
    else s(r*c,narkes);
}

int main()
{
  int testcases;
  cin>>testcases;
  for(int i=0;i<testcases;i++)
  {
//    if(i==1) yes=true;
    printf("Case #%d:\n",i+1);
    solver();
  }
  return 0;
}
