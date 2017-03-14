#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

int H,W,D;
char mapa[50][50];
char doble[100][100];
char vis[550][550];
int  did[500][500];

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int d2(int x,int y){ return x*x+y*y;}

bool check(int x,int y,int tx,int ty){
  if(tx==x && ty==y) return false;
  if(vis[x][y]!='X') return false;
  
  int dx=tx-x;
  int dy=ty-y;
  if(dy==0) dx=dx/abs(dx);
  if(dx==0) dy=dy/abs(dy);
  
  int g=1;
  if(dx!=0 && dy!=0){
    g=gcd(dx,dy);
    g=abs(g);
    dx/=g;
    dy/=g;
  }
  
  x+=dx;
  y+=dy;
  while(x!=tx || y!=ty){
    if(vis[x][y]=='X') return false;
    x+=dx;
    y+=dy;
  }
  return true;
}

void draw(int x,int y){
  did[x][y]=1;
  int i,j;
  for(i=0;i<2*(H-2);i++) for(j=0;j<2*(W-2);j++) vis[x+i][y+j]=doble[i][j];
  
  if(y-2*(W-2)>=0 && !did[x][y-2*(W-2)]) draw(x,y-2*(W-2));
  if(y+2*(W-2)<500 && !did[x][y+2*(W-2)]) draw(x,y+2*(W-2));
  if(x-2*(H-2)>=0 && !did[x-2*(H-2)][y]) draw(x-2*(H-2),y);
  if(x+2*(H-2)<500 && !did[x+2*(H-2)][y]) draw(x+2*(H-2),y);
}

void solve(){
  memset(did,0,sizeof did);
  memset(vis,'O',sizeof vis);
  H=in(); W=in(); D=in();
  int i,j,mx,my;
  
  for(i=0;i<H;i++) for(j=0;j<W;j++) cin>>mapa[i][j];
  
  for(i=0;i<H;i++) for(j=0;j<W;j++) if(mapa[i][j]=='X') {mx=i; my=j;}
  
  for(i=1;i<H-1;i++) for(j=1;j<W-1;j++) doble[i-1][j-1]=mapa[i][j];
  for(i=1;i<H-1;i++) for(j=1;j<W-1;j++) doble[i-1][W-2+j-1]=mapa[i][W-1-j];
  
  for(i=1;i<H-1;i++) for(j=1;j<W-1;j++) doble[H-2+i-1][j-1]=mapa[H-1-i][j];
  for(i=1;i<H-1;i++) for(j=1;j<W-1;j++) doble[H-2+i-1][W-2+j-1]=mapa[H-1-i][W-1-j];
  
  draw(250,250);
  
  mx--;
  my--;
  mx+=250;
  my+=250;
  int res=0;
  for(i=mx-D-1;i<mx+D+1;i++)
    for(j=my-D-1;j<my+D+1;j++){
      if(d2(abs(i-mx),abs(j-my))<=D*D){
        if(check(i,j,mx,my)) res++; 
      }
    }
    
  printf("%d\n",res);
  
  //~for(i=0;i<500;i++) { for(j=0;j<500;j++) cout << vis[i][j]; cout <<endl;}
  
}

int main(){
  freopen("tin","r",stdin);
  freopen("ton","w",stdout);
  int T=in();
  for(int caso=1;caso<=T;caso++){
    printf("Case #%d: ",caso);
    solve();
  }
  
}
