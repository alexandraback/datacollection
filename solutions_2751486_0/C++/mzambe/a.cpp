/*
 * =====================================================================================
 *
 *       Filename:  a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2013 07:05:44 PM
 *       Compiler:  g++
 *
 *         Author:  Manos Zambe
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int word[1000100];
int pos[1000100];
int subsum[1000100];

int min( int a, int b ){
    return ( a > b ) ? b : a;
}

int is_vowel( char a ){
  if ( ( a == 'a' ) || ( a == 'e' ) || ( a == 'i' ) || ( a == 'u' ) || ( a == 'o' ) )
      return 0;
  return 1;
}

void make_subsum( int N ){
  subsum[ 0 ]= word[ 0 ];
  for( int i = 1; i < N; i++ )
    subsum[ i ] = subsum[ i - 1 ] + word[ i ];
}

void fix_word( int N, int M ){
  int cons = 0, prev = N;
  for( int i = N - 1; i >= 0; i-- ){
    if( word[ i ] == 1 )
      cons++;
    else
      cons = 0;

    if( cons >= M ){
      pos[ i ] = i + M - 1;
      prev = i + M - 1;
    }
    else
      pos[ i ] = prev;

    //printf("%d  ", pos[ i ]);
  }
  //printf("\n");
}

long long int solve( int N, int M ){
  fix_word( N, M );
  int stval = 0, st = 0, en = 0;
  long long int res = 0;
  while( ( en < N ) && ( st < N ) ) {
    en = pos[ st ];

    if ( en < N )
      res += N - en;
    //printf("%d \n", res);
    st++;
  }

  return res;
}

int main(){
  int T, N, M;
  long long int res = 0;
  char s[1000100];
  scanf("%d", &T);
  
  for( int i = 1; i <= T; i++ ){
    scanf("%s %d", s, &M);
    N = strlen( s );
    //fprintf( stderr, "hello... %d \n", N);
    for( int j = 0; j < N; j++ )
      word[ j ] = is_vowel( s[ j ] );

    //printf("hello...\n");
    res = solve( N, M );
    printf("Case #%d: %lld\n", i, res);
  }
  return 0;
}
