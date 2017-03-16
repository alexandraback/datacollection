#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<iostream>
#include<set>
#include<map>
using namespace std;
int T;
int X,Y;
#define F first
#define S second
typedef pair<int,char> P;
struct st{
  int x,y,c;
  st(){}
  st(int x,int y,int c) : x(x),y(y),c(c) {}
};
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char dw[]="NSEW";
P h[2000][2000];
void bfs(){
  memset(h,-1,sizeof(h));
  queue<st> q;
  q.push( st( 1000,1000,0 ) );
  while(!q.empty()){
    st s = q.front(); q.pop();
    for(int i=0;i<4;i++){
      int nx = s.x+dx[i]*(s.c+1);
      int ny = s.y+dy[i]*(s.c+1);
      char w = dw[i];
      if(nx<0 || ny<0 || nx>=2000 || ny>=2000) continue;

      if(h[nx][ny].F==-1){
	h[nx][ny]=P(s.c+1,w);
	q.push( st(nx,ny,s.c+1) );
      }
    }
  }
  //cout << "bfs,end\n";
}
string solve(){
  //  cout << "solve,in\n";
  string res;
  int x=X,y=Y;
  while(!(x==1000 && y==1000)){

    //    cout << x << " " << y << " "<<h[x][y].F<<" " <<h[x][y].S<<"\n";
    string a=" ";
    a[0]=h[x][y].S;
    int ind;
    for(int i=0;i<4;i++){
      if(dw[i]==h[x][y].S) ind = i;
    }
    x-=dx[ind]*h[x][y].F;
    y-=dy[ind]*h[x][y].F;
    res+=a;
  }
  reverse(res.begin(),res.end());
  return res;
}
int main(){
  cin >> T;
  bfs();
  for(int loop=1;loop<=T;loop++){
    cin >> X >> Y;
    if(X==0 && Y==0)
      cout << "Case #" << loop << ": "<< ""<<endl;
    else{
      X+=1000; Y+=1000;
      cout << "Case #" << loop << ": "<< solve()<<endl;
    }
  }
}
