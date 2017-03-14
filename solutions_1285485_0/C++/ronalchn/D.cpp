#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;
// GCD yanked from http://www.devx.com/tips/Tip/33554
int GCD(int x,int y) {
  int t;
  while (y!=0) {
    t=y;
    y=x%y;
    x=t;
  }
  if (x==0) return 1;
  return x;
}

int checkpos(set<pair<int,int> > &block/*, set<pair<int,int> > &b2*/, int dx, int dy, int D2) {
  if (dx*dx+dy*dy>D2) return 0;
  int gcd = GCD(abs(dx),abs(dy));
  int dxp=dx/gcd;
  int dyp=dy/gcd;
  if (block.find(pair<int,int>(dxp,dyp))==block.end()) {
    block.insert(pair<int,int>(dxp,dyp));
    //b2.insert(pair<int,int>(dx,dy));
    return 1;
  }
  else return 0;
}

void solve(int t) {
  int H, W, D;

  cin >> H >> W >> D;
  int x, y;
  for (int h=0;h<H;h++) {
    string str;
    cin >> str;
    for (int w=0;w<W;w++) {
      if (str[w]=='X') {x=w;y=h;}
    }
  }
  x=x*2-1;
  y=y*2-1;
  D*=2;
  H=2*(H-2);
  W=2*(W-2);

  int D2=D*D;
  int ans=0;
  set<pair<int,int> > block;
  //set<pair<int,int> > b2, b3;
  // now enumerate...
  int num = (D/min(H,W))+2;
  for (int i=-num;i<=num;i++) {
      int in=i>0?i:(-num-i);
    for (int j=-num;j<=num;j++) {
      int jn=j>0?j:(-num-j);
      int shiftx = in*W; // num of reflections
      int shifty = jn*H;
      int reflectx=(i%2==0)?0:W-2*x; // shift caused by odd reflections
      int reflecty=(j%2==0)?0:H-2*y;
      // check each corner
      ans+=checkpos(block/*,b3*/,-x+shiftx,-y+shifty,D2/4);

      // and check yourself
      ans+=checkpos(block/*,b2*/,shiftx+reflectx,shifty+reflecty,D2);
    }
  }
  /*for (int i=-num;i<=num;i++) {
    for (int j=-num;j<=num;j++) {
      int shiftx = i*W;
      int shifty = j*H;
      if (shiftx<=0) shiftx=(-num-i)*W;
      if (shifty<=0) shifty=(-num-j)*H;
      // check each corner
      //ans+=checkpos(block,b3,-x+shiftx,-y+shifty,D2/4);
    }
  }*/


  ans--; // remove yourself once (as it is not a reflection)
  printf("Case #%d: %d\n",t,ans);
/*if (t<=3) {
  for (int j=-num*H;j<=H*num;j++) {
    for (int i=-num*W;i<=W*num;i++) {
      if (i==0 && j==0) cout << "0";
      else if (b2.find(pair<int,int>(i,j))!=b2.end()) cout << "x";
      else if (i%2==0 && j%2==0 && b3.find(pair<int,int>(i/2,j/2))!=b3.end()) cout << "+";
      else cout << ".";
    }
    cout << endl;
  }
}*/
}

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    solve(t);
  }
  return 0;
}
