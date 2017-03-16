#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int fl[101][101],ce[101][101],mnt[101][101];
int mgo[101][101][4][2];
int N,M,H;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
const int BIG = 1000000000;

int go(int x1,int y1,int x2,int y2,int h) {
  if(x2<0 || x2>=N || y2<0 || y2>=M)
    return 0;
  if(ce[x2][y2] - max(fl[x1][y1],max(fl[x2][y2],h)) < 50)
    return 0;
  if(ce[x1][y1] - fl[x2][y2] < 50)
    return 0;
  if(h - fl[x1][y1] >= 20)
    return 10;
  return 100;
}

void mngo(int x2,int y2,int d) {
  int x1=x2+dx[d],y1=y2+dy[d];
  if(x1<0 || x1>=N || y1<0 || y1>=M)
    return;
  if(ce[x2][y2] - max(fl[x1][y1],fl[x2][y2]) < 50)
    return;
  if(ce[x1][y1] - fl[x2][y2] < 50)
    return;
  mgo[x2][y2][d][0] = H - fl[x1][y1] - 20;
  if(50 + H - ce[x2][y2] >= 0)
    mgo[x2][y2][d][1] = 50 + H - ce[x2][y2];
  else
    mgo[x2][y2][d][1] = 0;
}

void compmnt(int x2,int y2) {
  for(int d=0;d<4;d++) {
    int t0=mgo[x2][y2][d][0],t1=mgo[x2][y2][d][1];
    if(t1<0)
      continue;
    int x1=x2+dx[d],y1=y2+dy[d];
    if(mnt[x1][y1]==BIG)
      continue;
      
    int tpass = max(mnt[x1][y1],t1);
    if(tpass == 0)
      mnt[x2][y2]=min(mnt[x2][y2],tpass);
    else {
      if(t1 <= t0) {
        if(mnt[x1][y1] <= t0)
            mnt[x2][y2] = min(mnt[x2][y2], 10 + tpass);
      }
      mnt[x2][y2] = min(mnt[x2][y2],100 + tpass);
    }
  }
}

int main() {
	int T;
	cin >> T;

	for(int c=1;c<=T;c++) {
    cin >> H >> N >> M;
    for(int i=0;i<N;i++) {
      for(int j=0;j<M;j++) { 
        cin >> ce[i][j];
        mnt[i][j]=BIG;
      }
    }
    for(int i=0;i<N;i++) {
      for(int j=0;j<M;j++) 
        cin >> fl[i][j];
    }
    
    mnt[0][0]=0;
    
    for(int i=0;i<N;i++) {
      for(int j=0;j<M;j++) {
        for(int d=0;d<4;d++) {
          mgo[i][j][d][0]=-1;
          mgo[i][j][d][1]=-1;
          mngo(i,j,d);
        }
      }
    }
    
    for(int t=0;t<10000;t++) {
      for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++)
          compmnt(i,j);
      }
    }
    
		cout << "Case #" << c << ": " << mnt[N-1][M-1]/10.0  << endl;
	}
	return 0;
}
