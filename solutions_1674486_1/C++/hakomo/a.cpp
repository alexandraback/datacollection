#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main(){
  int h,i,j;
  int t;
  cin>>t;
  for(h=1;h<=t;++h){
    int n;
    cin>>n;
    int a[1000][1000]={};
    vector<int> b;
    for(i=0;i<n;++i){
      int m;
      cin>>m;
      if(!m)
	b.push_back(i);
      for(j=0;j<m;++j){
	int p;
	cin>>p;
	--p;
	a[i][p]=-1;
      }
    }
    for(i=0;i<n;++i){
      queue<int> c;
      c.push(i);
      int d[1000]={};
      d[i]=-1;
      while(!c.empty()){
	int p=c.front();
	for(j=0;j<n;++j){
	  if(!a[p][j])
	    continue;
	  if(d[j])
	    break;
	  d[j]=-1;
	  c.push(j);
	}
	if(j<n)
	  break;
	c.pop();
      }
      if(!c.empty())
	break;
    }
    cout<<"Case #"<<h<<": "<<(i<n?"Yes":"No")<<endl;
  }
  return 0;
}
