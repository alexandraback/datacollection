#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

#define LEFT 24
#define RIGHT 26

typedef pair < long long, int > pp;

pp S[1 << LEFT];
long long niz[504];
int N, T;

inline void output( long long x ) {
  for ( int i = 0; i < 50; ++i )
    if ( (x >> i) & 1 )
      printf("%I64d ", niz[i]);
  printf("\n");
}

int main(void) {
  scanf("%d", &T);
  
  for ( int t = 1; t <= T; ++t ) {
    scanf("%d", &N);
    
    for ( int i = 0; i < N; ++i )
      scanf("%I64d", niz + i);
    
    int n = min( N, LEFT );
    for ( int mask = 0; mask < (1 << n); ++mask ) {
      long long sum = 0;
      for ( int i = 0; i < n; ++i )
        if ( mask & (1 << i) )
          sum += niz[i];
      S[mask].first = sum;
      S[mask].second = mask;
    }
    
    fprintf( stderr, "sortiram\n" );
    sort( S, S + (1 << n) );
    fprintf( stderr, "sort gotov\n" );

    
    printf("Case #%d:\n", t);

    bool found = false;
    for ( int i = 1; i < (1 << n); ++i )
      if ( S[i].first == S[i-1].first ) {
        output( S[i].second );
        output( S[i-1].second );
        found = true;
        break;
      }
      
    if ( found ) continue;
    
    if ( n == 20 ) {
      printf("Impossible\n");
      continue;
    }
    
    
    fprintf( stderr, "trazim desno\n" );
    for ( int mask = 1; mask < (1 << RIGHT); ++mask ) {
      if ( (mask & 1048575) == 0 ) fprintf( stderr, "." );
      long long sum = 0;
      for ( int i = 0; i < n; ++i )
        if ( mask & (1 << i) )
          sum += niz[i + LEFT];
          
      pp *a = lower_bound( S, S + (1 << LEFT), pp( sum, 0x3f3f3f3f ) );
      if ( a < S + (1 << LEFT) && a->first == sum ) {
        fprintf( stderr, "nasao\n" );
        output( a->second );
        output( (long long)mask >> LEFT );
        break;
      }
    }
    
  }
  
  return 0;
}
