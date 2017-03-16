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
bool e[60][60],used[60];
char code[60][6];
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
    bool found=false;
    do{
      bool t[60][60]={};
      for(int i=n-1;i>=0;i--){
        t[i][i+1]=true;
        for(int j=i+2;j<=n;j++){
          for(int k=i+1;k<j;k++){
            t[i][j]|=e[s[i].second][s[k].second]&&t[i][k]&&t[k][j];
          }
        }
      }
      if(t[0][n]){
        found=true;
        break;
      }
    }while(next_permutation(s.begin(),s.end()));
    assert(found);
/*    for(int z=0;z<n;z++){
      int pos=0;
      while(pos<s.size()){
        int nr=s[pos].second;
        if(!used[nr]){
          sol.push_back(nr);
          if(ok(sol))break;
          sol.pop_back();
        }
        ++pos;
      }

    }*/
    for(int i=0;i<n;i++)sol.push_back(s[i].second);
    printf("Case #%d: ",cc);
    for(int i=0;i<n;i++)printf("%s",code[sol[i]]);
    printf("\n");
  }
}
