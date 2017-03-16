
using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
  class Fractiles
  {
    static void Main( string[ ] args )
    {
      Int64 numberOfTestcases = getInt( );

      for( int i = 1; i <= numberOfTestcases; ++i )
      {
        SolveProblem( getIntegers( ), i );
      }

    }

    public static void SolveProblem( int[ ] parameters, int caseId )
    {
      int k = parameters[ 0 ];
      int c = parameters[ 1 ];
      int s = parameters[ 2 ];

      if( Math.Ceiling( (double)k / c ) > s )
        Console.WriteLine( $"Case #{caseId}: IMPOSSIBLE" );
      else
      {
        List<int> indexes = new List<int>( );
        var students = Math.Ceiling( (double)k / c );
        int j = 0;
        BigInteger position = 0;
        List<BigInteger> positions = new List<BigInteger>( );
        while( j < k )
        {
          position += ( j ) * (BigInteger)Math.Pow( k, ( c - ( j % c ) - 1 ) );
          if( ( j + 1 ) % c == 0 || j == k - 1 )
          {
            positions.Add( position + 1 );
            position = 0;
          }
          ++j;
        }

        Console.WriteLine( $"Case #{caseId}: {String.Join( " ", positions )}" );
      }
    }

    public static int[ ] getIntegers( )
    {
      var line = Console.ReadLine( );
      var token = line.Split( );

      int[ ] numbers = new int[ token.Count( ) ];
      for( int i = 0; i < token.Count( ); ++i )
        numbers[ i ] = int.Parse( token[ i ] );
      return numbers;
    }

    public static Int64 getInt( )
    {
      var line = Console.ReadLine( );
      var token = line.Trim( );

      Int64 number = Int64.Parse( token );
      return number;
    }

  }
}
