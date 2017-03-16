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

bool check(int x){
  if(x==3 || x==5 || x==7)return true;
  return false;
}

int main(){
  int testcase;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    cin >> r >> c >> m;
    int len = r*c, rem = len-m;

    cout << "Case #" << casenum << ":\n";
    if(r==1||c==1){
      rep(i,r){
	rep(j,c){
	  if(m)cout << '*', m--;
	  else if(i==r-1 && j==c-1)cout << 'c';
	  else cout << '.';
	}
	cout << endl;
      }
    }else if(r==2||c==2){
      if(rem==2 || (rem!=1 && rem&1))cout << "Impossible" << endl;
      else{
	rep(i,r){
	  rep(j,c){
	    int pos = (r==2)?j*r+i:i*c+j;
	    if(pos<m)cout << '*';
	    else if(i==r-1 && j==c-1)cout << 'c';
	    else cout << '.';
	  }
	cout << endl;
	}
      }
    }else{
      if(rem==2 || rem==3 || rem==5 || rem==7)cout << "Impossible" << endl;
      else{
	rep(i,r)rep(j,c)grid[i][j] = '*';
	grid[0][0] = 'c';
	rem--;
	if(rem!=0){
	  grid[1][0] = grid[0][1] = grid[1][1] = '.';
	  rem-=3;
	}

	int y = 2, x = 2;
	while(2<=rem){
	  if(y==r && x==c)break;
	  if((x<y && x<c) || y==r){
	    grid[0][x] = grid[1][x] = '.';
	    x++;
	    rem-=2;
	  }else{
	    grid[y][0] = grid[y][1] = '.';
	    y++;
	    rem-=2;
	  }
	}

	//cout << y << " " << x << " " << rem << endl;
	rep(d,y+x-4){
	  if(rem==0)break;
	  rep(i,x-2){
	    if(rem==0)break;
	    int nx = i+2, ny = d-i+2;
	    //cout << ny << " " << nx << endl;
	    if(nx<2 || ny<2 || nx>=x || ny>=y)continue;
	    grid[ny][nx] = '.';
	    rem--;
	  }
	}

	rep(i,r){
	  rep(j,c)cout << grid[i][j];
	  cout << endl;
	}
      }
    }
  }
}
