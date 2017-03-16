
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
  class CountingSheeps
  {
    static void Main( string[ ] args )
    {
      Int64 numberOfTestcases = getInt( );

      for( int i = 1; i <= numberOfTestcases; ++i )
      {
        SolveProblem( Math.Abs( getInt( ) ), i );
      }

    }

    public static void SolveProblem( Int64 number, int caseId )
    {
      if( number == 0 )
        Console.WriteLine( $"Case #{caseId}: INSOMNIA" );
      else
      {
        Int64 currentNumber = number;

        List<char> digitsToSee = new List<char>( ) { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        while( digitsToSee.Any( ) )
        {
          var digits = currentNumber.ToString( ).ToCharArray( );
          digitsToSee.RemoveAll( obj => digits.Contains( obj ) );
          currentNumber += number;
        }

        Console.WriteLine( $"Case #{caseId}: {currentNumber - number}" );
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
