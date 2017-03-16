
#include <tchar.h>
#include <fstream>
#include <iostream>

using namespace std;

int aif[1001][60];
int aii[1001];

int FillGraph( int i )
{
  int j;
  for ( int k=1; 1 ; k++ ) 
  {
    j = aif[i][k];
    if ( !j ) break;
    if ( aii[j] ) return 1;
    aii[j] = 1;
    if ( FillGraph(j) ) return 1;
  }
  return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
  ifstream input;
  ofstream output;

  int T,N,N2;
  int j2;

  bool bDiamondFound;

  // initialize
  if ( argc != 3 ) return -1;
  input.open( argv[1] );
  if ( !input ) return -1;
  output.open( argv[2] );
  input >> T;

  for ( int t=1; t <= T; t++ ) 
  {
    input >> N;
    for ( int j=1; j <= N; j++ ) 
    {
      input >> N2;
      for ( int k=1; k <= N2; k++ ) 
      {
        input >> j2;
        aif[j][k] = j2;
      }
      aif[j][N2+1] = 0;
    }

    bDiamondFound = false;

    for ( int j=1; j <= N; j++ ) 
    {
      for ( int j2=1; j2 <= N; j2++ ) 
      {
        aii[j2]=0;
      }
      if ( FillGraph(j) )
      {
        bDiamondFound = true;
        break;
      }
    }
    if ( bDiamondFound )
    {
      output << "Case #" << t << ": Yes" << endl;  
    }
    else
    {
      output << "Case #" << t << ": No" << endl;  
    }
  }
  input.close();
  output.close();

  return 0;
}

