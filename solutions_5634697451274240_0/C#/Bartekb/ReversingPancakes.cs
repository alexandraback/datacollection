
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
  class ReversingPancakes
  {
    static void Main( string[ ] args )
    {
      Int64 numberOfTestcases = getInt( );

      for( int i = 1; i <= numberOfTestcases; ++i )
      {
        SolveProblem( Console.ReadLine( ).Trim( ), i );
      }

    }

    public static void SolveProblem( String pattern, int caseId )
    {
      List<bool> pancakes = pattern.ToCharArray( ).Select( obj =>
      {
        if( obj == '+' )
          return true;
        if( obj == '-' )
          return false;
        else
          throw new ArgumentNullException( );
      }
      ).ToList( );
      int attempts = 0;
      while( !pancakes.All( obj => obj ) )
      {
        int numberToReverse = pancakes.IndexOf( false );

        if( numberToReverse != 0 )
        {
          ++attempts;
          Reverse( pancakes, numberToReverse );
        }

        int numberToReverse2 = pancakes.LastIndexOf( false ) + 1;

        ++attempts;
        Reverse( pancakes, numberToReverse2 );
      }
      Console.WriteLine( $"Case #{caseId}: {attempts}" );
    }

    private static void Reverse( List<bool> pancakes, int numberToReverse )
    {
      pancakes.Reverse( 0, numberToReverse );
      for( int i = 0; i < numberToReverse; ++i )
        pancakes[ i ] = !pancakes[ i ];
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
