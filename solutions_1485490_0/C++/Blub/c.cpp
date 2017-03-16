
#include <tchar.h>
#include <fstream>
#include <iostream>

using namespace std;

  int T,N,M;
 // int a, b,n;

long long nBoxes[100];
int tBoxes[100];
long long nToys[100];
int tToys[100];

long long  max ( long long  a, long long  b )
{
  if ( a > b ) return a;
  return b;
}

long long Packed( int a, int b, long long na, long long nb )
{
  long long n=0,n1,n2;

  if ( a >= N || b >= M ) return 0;
  if ( tBoxes[a] == tToys[b] )
  {
    if ( na < nb )
    {
      n += na;
      nb -= na;
      a++;
      na = nBoxes[a]; 
    }
    else
    {
      n += nb;
      na -= nb;
      b++;
      nb = nToys[b]; 
    }
    if ( a < N && b < M )
    {
      n += Packed( a, b, na, nb ); 
    }
  }
  else
  {
    n1 = Packed( a+1, b, nBoxes[a+1], nb );
    n2 = Packed( a, b+1, na, nToys[b+1] ); 
    n = max( n1, n2 );
  }
  return n;
}

int _tmain(int argc, _TCHAR* argv[])
{
  ifstream input;
  ofstream output;

  // initialize
  if ( argc != 3 ) return -1;
  input.open( argv[1] );
  if ( !input ) return -1;
  output.open( argv[2] );
  input >> T;

  for ( int t=1; t <= T; t++ ) 
  {
    input >> N;
    input >> M;
    for ( int i=0; i < N; i++ ) 
    {
     // input >> x;
      input >> nBoxes[i];
      input >> tBoxes[i];
    }
    for ( int i=0; i < M; i++ ) 
    {
      input >> nToys[i];
      input >> tToys[i];
    }
    output << "Case #" << t << ": " << Packed(0,0,nBoxes[0],nToys[0]) << endl;  
  }
  input.close();
  output.close();

  return 0;
}

