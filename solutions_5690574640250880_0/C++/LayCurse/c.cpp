#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
#include<cmath>
#include<cassert>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

char in[100][100], tmp[100][100];

void rot(int X, int Y){
  int i, j;
  rep(i,X) rep(j,Y) tmp[i][j] = in[i][j];
  rep(i,X) rep(j,Y) in[j][i] = tmp[i][j];
}

int solve(int R, int C, int M){
  int i, j, k;
  int a, b, c;
  int X, Y, E;
  int arr[100];
  
  X = max(R,C);
  Y = min(R,C);
  rep(i,X) rep(j,Y) in[i][j] = '*';

  E = R*C - M;

  if(E==1){
    in[0][0] = 'c';
    if(X!=R) rot(X, Y);
    return 1;
  }

  if(Y==1){
    rep(i,E) in[i][0] = '.';
    in[0][0]='c';
    if(X!=R) rot(X, Y);
    return 1;
  }

  if(Y==2){
    if(E==2 || E%2==1) return 0;
    rep(i,E/2) in[i][0] = in[i][1] = '.';
    in[0][0] = 'c';
    if(X!=R) rot(X, Y);
    return 1;
  }

  if(E==4 || E==6){
    rep(i,E/2) rep(j,2) in[i][j] = '.';
    in[0][0] = 'c';
    if(X!=R) rot(X, Y);
    return 1;
  }

  if(E==2 || E==3 || E==5 || E==7){
    return 0;
  }

  REP(a,3,X+1){
    k = E;
    rep(j,Y){
      arr[j] = min(a, k);
      k -= arr[j];
    }
    if(k) continue;
    rep(j,Y){
      if(arr[j]==1) arr[j-1]--, arr[j]++;
    }
    if(arr[0] != arr[1]) continue;

    rep(j,Y) rep(i,arr[j]) in[i][j] = '.';
    in[0][0] = 'c';
    break;
  }
  assert(a < X+1);
  
  if(X!=R) rot(X, Y);
  return 1;
}

int isValid(int R, int C, int M){
  int i, j, k;
  int di, dj, ni, nj;

  k = 0;
  rep(i,R) rep(j,C) if(in[i][j]=='*') k++;
  if(k!=M) return 0;

  if(in[0][0] != 'c') return 0;
  rep(i,R) rep(j,C){
    if(i||j){
      if(in[i][j]!='.' && in[i][j]!='*') return 0;
    }
  }

  for(;;){
    int fg = 0;
    rep(i,R) rep(j,C) if(in[i][j]=='c'){
      k = 0;
      REP(di,-1,2) REP(dj,-1,2){
        ni = i + di;
        nj = j + dj;
        if(ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
        if(in[ni][nj]=='*') k++;
      }
      if(k==0){
        REP(di,-1,2) REP(dj,-1,2){
          ni = i + di;
          nj = j + dj;
          if(ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
          if(in[ni][nj]=='.') fg++, in[ni][nj]='c';
        }
      }
    }
    if(!fg) break;
  }
  rep(i,R) rep(j,C) if(in[i][j]=='.') return 0;
  return 1;
}

int main(){
  int T, cnt = 0, R, C, M;

  int i, j, k;

  scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&R,&C,&M);

    printf("Case #%d:\n",++cnt);

    k = solve(R, C, M);
    if(!k){
/*      string a;
      rep(i,R*C) a += '.';
      a[0]='c';
      rep(i,M) a[R*C-1-i] = '*';
      sort(a.begin()+1, a.end());
      do{
        rep(i,R) rep(j,C) in[i][j] = a[i*C+j];
        if(isValid(R,C,M)){
          exit(0);
        }
      }while(next_permutation(a.begin()+1,a.end()));*/
      puts("Impossible");
      continue;
    }

    rep(i,R){
      rep(j,C) putchar(in[i][j]);
      puts("");
    }

    assert(isValid(R, C, M));
  }

  return 0;
}
