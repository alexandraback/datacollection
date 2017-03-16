#include <tchar.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int main( int argc, char* argv[] )
{
  int T, J, P, S, K;
  int a[10][10];
  int b[10][10];
  int x,n;
  std::string buf;
  char szBuffer[100];

  ifstream input;
  ofstream output;

  // initialize
  if ( argc != 3 ) return -1;
  input.open( argv[1] );
  if ( !input ) return -1;
  output.open( argv[2] );
  input >> T;

  for ( int t=0; t < T; t++ )
  {
    input >> J;
    input >> P;
    input >> S;
    input >> K;

    for ( int j=0; j<S; j++ )
    {
      if ( j )
      {
        x = a[j-1][0] << 1;
        if ( x > (1<<(S-1)) ) x = 1;
      }
      else
      {
        x = 1;
      }
      for ( int p=0; p<P; p++ )
      {
        a[j][p] = x;
        x <<= 1;
        if ( x > (1<<(S-1)) ) x = 1;
      }
    }

    for ( int j=0; j<J; j++ )
    {
      for ( int p=0; p<P; p++ )
      {
        b[j][p] = 0;
        for ( int k=0; k<K; k++ )
        {
          b[j][p] |= a[(j+k)%S][p];
        }
      }
    }

    n=0;
    buf.clear();

    for ( int j=0; j<J; j++ )
    {
      for ( int p=0; p<P; p++ )
      {
        x = b[j][p];
        for ( int s=0; s<S; s++ )
        {
          if ( x&1 )
          {
            n++;
            sprintf( szBuffer, "%d %d %d\n", j+1,p+1,s+1 );
            buf += szBuffer;
          }
          x >>= 1;
        }
      }
    }

    output << "Case #" << t+1 << ": " << n << endl << buf;  
  }
  input.close();
  output.close();

  return 0;
}

