#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef pair<iii,char> iiic;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char p[] = {'N','S','E','W'};

int T,n,C=1,x,y,r;
queue<iii> q;
map<iii,bool> enfilered;
map<iii,iiic> pai;
iii e;
ii pos;
ii end;
int res[1024];

int main(){

  scanf("%d",&T);
  while(T--){
    scanf("%d %d",&x,&y);
    end = ii(x,y);
    enfilered.clear();
    pai.clear();
    while(!q.empty()) q.pop();
    pai[iii(ii(0,0),0)]=iiic(iii(ii(0,0),0),' ');
    enfilered[iii(ii(0,0),0)] = true;
    q.push(iii(ii(0,0),0));
    while(!q.empty()){
      e = q.front(); q.pop();
      pos = e.first;
      if(pos==end) break;
      for(int i=0;i<4;i++){
        int nx = pos.first  + (e.second+1)*dx[i];
        int ny = pos.second + (e.second+1)*dy[i];
        if(!enfilered[iii(ii(nx,ny),e.second+1)]){
          ii npos = ii(nx,ny);
          iii ne = iii(npos, e.second+1);
          pai[ne] = iiic(e,p[i]);
          enfilered[ne] = true;
          q.push(ne);
        }
      }
    }

    r=0;
    printf("Case #%d: ",C++);
    iii cur = e;
    for(int i=0;i<e.second;i++){
      res[r++] = pai[cur].second;
      cur = pai[cur].first;
    }
    for(int i=r-1;i>=0;i--) printf("%c",res[i]);
    printf("\n");

  }

  return 0;
}
