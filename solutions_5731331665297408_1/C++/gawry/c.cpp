#include<cassert>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

int n,m;
bool e[60][60],used[60],visible[60],seen[60],safe;
char code[60][6];
void dfs(int x){
  seen[x]=true;
  for(int i=0;i<n;i++)if(e[x][i]){
    if(used[i]){
      safe|=visible[i];
    }else if(!seen[i]){
      dfs(i);
    }
  }
}
bool ok(vi s){
  bool t[60][60]={};
  for(int i=s.size()-1;i>=0;i--){
    t[i][i+1]=true;
    for(int j=i+2;j<=s.size();j++){
      for(int k=i+1;k<j;k++){
        t[i][j]|=e[s[i]][s[k]]&&t[i][k]&&t[k][j];
      }
    }
  }
  if(!t[0][s.size()])return false;
  memset(visible,0,sizeof(visible));
  int cur=0;
  visible[s[0]]=true;
  while(cur+1<s.size()){
    int next=cur+1;
    while(next<s.size()&&!(e[s[cur]][s[next]]&&t[cur][next]&&t[next][s.size()]))++next;
    assert(next<s.size());
    cur=next;
    visible[s[cur]]=true;
  }
  memset(seen,0,sizeof(seen));
  for(int i=0;i<n;i++)if(!used[i]&&!seen[i]){
    safe=false;
    dfs(i);
    if(!safe)return false;
  }
  //for(int i=0;i<s.size();i++)cout<<s[i]<<",";cout<<endl;
  //for(int i=0;i<n;i++)printf("%d,%d\n",visible[i],used[i]);
  return true;
}
int main(){
  int c;
  scanf("%d",&c);
  for(int cc=1;cc<=c;cc++){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",code[i]);
    memset(e,0,sizeof(e));
    while(m--){
      int x,y;
      scanf("%d %d",&x,&y);
      --x;--y;
      e[x][y]=e[y][x]=true;
    }
    memset(used,0,sizeof(used));
    vector<pair<string,int> > s;
    for(int i=0;i<n;i++)s.push_back(make_pair(code[i],i));
    sort(s.begin(),s.end());
    vector<int> sol;
    for(int z=0;z<n;z++){
      int pos=0;
      bool found=false;
      while(pos<s.size()){
        int nr=s[pos].second;
        if(!used[nr]){
          used[nr]=true;
          sol.push_back(nr);
          if(ok(sol)){
            found=true;
            break;
          }
          used[nr]=false;
          sol.pop_back();
        }
        ++pos;
      }
      assert(found);
    }
    printf("Case #%d: ",cc);
    for(int i=0;i<n;i++)printf("%s",code[sol[i]]);
    printf("\n");
  }
}
