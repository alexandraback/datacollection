#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

typedef pair < int, int > pp;

#define MAX 104

int high[MAX][MAX];
int low[MAX][MAX];
int best[MAX][MAX];
bool bio[MAX][MAX];
int N, M, H, T;

priority_queue < pair < int, pp > > pq;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = {  0,-1, 0, 1 };

void rek( int x, int y ) {
  best[y][x] = 0;
//  printf("odmah [%d %d]\n", x, y);
  pq.push( make_pair( 0, pp( x, y ) ) );
  bio[y][x] = true;
  
  for ( int s = 0; s < 4; ++s ) {
    int nx = x + dx[s];
    int ny = y + dy[s];
    if ( nx < 0 || ny < 0 || nx >= M || ny >= N ) continue;
    
    if ( bio[ny][nx] ) continue;
        
    if ( high[ny][nx] - low[ny][nx] < 50 ) continue;
    if ( high[ny][nx] - H < 50 ) continue;
    if ( high[ny][nx] - low[y][x] < 50 ) continue;
    if ( high[y][x] - low[ny][nx] < 50 ) continue;
        
    rek( nx, ny );
  }
}



int main(void) {
  scanf("%d", &T);
  for ( int t = 1; t <= T; ++t ) {
    scanf("%d%d%d", &H, &N, &M);
    for ( int i = 0; i < N; ++i )
      for ( int j = 0; j < M; ++j )
        scanf("%d", &high[i][j]);
    for ( int i = 0; i < N; ++i )
      for ( int j = 0; j < M; ++j )
        scanf("%d", &low[i][j]);
        
    memset( best, 0x3f, sizeof( best ) );
    memset( bio, 0, sizeof( bio ) );
        
    while ( !pq.empty() )
      pq.pop();
      
    rek( 0, 0 );

    memset( bio, 0, sizeof( bio ) );

    while ( !pq.empty() ) {
      int x = pq.top().second.first;
      int y = pq.top().second.second;

      pq.pop();
      
      if ( bio[y][x] ) continue;
      bio[y][x] = true;
      
      int h = max( low[y][x], H - best[y][x] );
      
      
      for ( int s = 0; s < 4; ++s ) {
        int nx = x + dx[s];
        int ny = y + dy[s];
        if ( nx < 0 || ny < 0 || nx >= M || ny >= N ) continue;
        
        if ( high[ny][nx] - low[ny][nx] < 50 ) continue;
        if ( high[ny][nx] - low[y][x] < 50 ) continue;
        if ( high[y][x] - low[ny][nx] < 50 ) continue;
        
        int wait = max( 0, 50 - (high[ny][nx] - h) );
        int new_time = best[y][x] + wait + (h - wait - low[y][x] >= 20 ? 10 : 100);
        
        
        if ( best[ny][nx] > new_time ) {
          //printf("sirim se iz [%d %d] u [%d %d] u trenutku %d, cekam %d do visine %d, putujem %d, ukupno do %d\n", x, y, nx, ny, best[y][x], wait, h - wait, (h - wait - low[y][x] >= 20 ? 10 : 100), new_time);
          best[ny][nx] = new_time;
          pq.push( make_pair( -best[ny][nx], pp( nx, ny ) ) );
        }
      }  
    }
    
    printf("Case #%d: %.1lf\n", t, best[N-1][M-1] * 0.1);
  }
  return 0;
}
