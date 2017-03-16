#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int T;
int N, M, K;
int dir[4][2] = { { 0, 1}, { 1, 0}, { 0, -1}, { -1, 0}};
int out;
int ans;
int temp[25][25];
bool chk[25][25];
queue <pii> q;

inline void gen( int now, int ct){
  int i, j;

  if( now == N * M){
    
    memset( chk, 0, sizeof chk);

    for( i = 0; i < N; i++){
      if( temp[i][0] == 0 && !chk[i][0]){
	q.push( pii( i, 0));
	chk[i][0] = 1;
      }
      if( temp[i][M - 1] == 0 && !chk[i][M - 1]){
	q.push( pii( i, M - 1));
	chk[i][M - 1] = 1;
      }
    }

    for( j = 0; j < M; j++){
      if( temp[0][j] == 0 && !chk[0][j]){
	q.push( pii( 0, j));
	chk[0][j] = 1;
      }
      if( temp[N - 1][j] == 0 && !chk[N - 1][j]){
	q.push( pii( N - 1, j));
	chk[N - 1][j] = 1;
      }
    }

    out = 0;
    while( !q.empty()){
      out++;

      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      for( i = 0; i < 4; i++){
	if( 0 <= x + dir[i][0] && x + dir[i][0] < N && 0 <= y + dir[i][1] && y + dir[i][1] < M){
	  if( !chk[x + dir[i][0]][y + dir[i][1]] && temp[x + dir[i][0]][y + dir[i][1]] == 0){
	    chk[ x + dir[i][0]][y + dir[i][1]] = 1;
	    q.push( pii( x + dir[i][0], y + dir[i][1]));
	  }
	}
      }
    }

    if( N * M - out >= K)ans = min( ans, ct);
    return;
  }
  
  gen( now + 1, ct);
  temp[ now / M][ now % M] = 1;
  gen( now + 1, ct + 1);
  temp[ now / M][ now % M] = 0;
}

int main(){
  int i, j;

  freopen( "C-small-attempt0.in", "r", stdin);
  freopen( "Enclosure_s.txt", "w", stdout);

  scanf("%d", &T);
  for( int tt = 1; tt <= T; tt++){
    scanf("%d %d %d", &N, &M, &K);

    ans = 2e9;
    gen( 0, 0);
    printf("Case #%d: %d\n", tt, ans);
  }
}
