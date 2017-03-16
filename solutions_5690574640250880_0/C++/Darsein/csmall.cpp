#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef pair<int,int> pii;

int r,c,m;
char grid[55][55];
int vis[55][55];

int rec(int y, int x){
  if(vis[y][x])return 0;
  vis[y][x] = true;

  int res = 1, num = 0;
  rep(i,3)rep(j,3){
    if(i==1 && j==1)continue;
    int ny = y+i-1, nx = x+j-1;
    if(ny<0 || nx<0 || ny>=r || nx>=c)continue;
    num += (grid[ny][nx] == '*');
  }

  if(num==0){
    rep(i,3)rep(j,3){
      if(i==1 && j==1)continue;
      int ny = y+i-1, nx = x+j-1;
      if(ny<0 || nx<0 || ny>=r || nx>=c)continue;
      res += rec(ny,nx);
    }
  }
  return res;
}

int main(){
  int testcase;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    bool f = false;
    cin >> r >> c >> m;
    int len = r*c, rem = len-m;

    if(len<=25){
      int comb = (1<<m)-1;
      while(comb < (1<<len)){
	rep(bit,len){
	  int i = bit/c, j = bit%c;
	  if((comb>>bit)&1)grid[i][j] = '*';
	  else grid[i][j] = '.';
	}

	rep(i,r){
	  rep(j,c){
	    if(grid[i][j]=='.'){
	      memset(vis,0,sizeof(vis));
	      if(rec(i,j) == rem){
		f = true;
		grid[i][j] = 'c';
		break;
	      }
	    }
	  }
	  if(f)break;
	}
	if(f)break;
	int x = comb & -comb, y = comb + x;
	comb = ( ( (comb & ~y) /x ) >> 1) | y;
      }
    }

    cout << "Case #" << casenum << ":\n";
    if(!f)cout << "Impossible" << endl;
    else{
      rep(i,r){
	rep(j,c)cout << grid[i][j];
	cout << endl;
      }
    }
  }
}
