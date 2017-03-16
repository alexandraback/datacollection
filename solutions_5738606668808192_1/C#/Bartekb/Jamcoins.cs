
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Collections;

namespace CodeJam
{
  static class Jamcoins
  {
    static void Main( string[ ] args )
    {
      int numberOfTestcases = getInt( );
      int[ ] parameters = getIntegers( );
      int jamcoinLength = parameters[ 0 ];
      int numberOfJamcoins = parameters[ 1 ];

      for( int i = 1; i <= numberOfTestcases; ++i )
      {
        SolveProblem( jamcoinLength, numberOfJamcoins, i );
      }

    }

    public static void SolveProblem( int jamcoinLength, int numberOfJamcoins, int caseId )
    {
      List<string> jamcoins = new List<string>( );
      Console.WriteLine( $"Case #{caseId}: " );

      string jamcoin = String.Empty;
      while( jamcoins.Count < numberOfJamcoins )
      {
        jamcoin = GeneratePossibleJamcoin( jamcoin, jamcoinLength );
        int[ ] divisors = new int[ 9 ];
        bool success = true;
        for( int i = 2; i <= 10; ++i )
        {
          var divisor = TestJamcoin( jamcoin, i );
          divisors[ i - 2 ] = divisor;
          if( divisor == 0 )
          {
            success = false;
            break;
          }
        }
        if( success )
        {
          jamcoins.Add( jamcoin );
          Console.WriteLine( $"{jamcoin} {String.Join( " ", divisors )}" );
        }
      }
    }

    private static int TestJamcoin( string jamcoin, int baseNumber )
    {
      BigInteger number = BinToInteger( jamcoin, baseNumber );
      return ReturnDivisor( number );
    }

    private static string GeneratePossibleJamcoin( string jamcoin, int jamcoinLength )
    {
      if( jamcoin.Length < jamcoinLength )
        jamcoin = $"1{new String( '0', jamcoinLength - 2 )}1";
      else
      {
        jamcoin = IntegerToString( BinToInteger( jamcoin, 2 ) + 2 );
        if( jamcoin.Length != jamcoinLength )
          throw new ArgumentOutOfRangeException( );
      }

      return jamcoin;
    }

    private static string IntegerToString( BigInteger integer )
    {
      var bytes = integer.ToByteArray( );
      var idx = bytes.Length - 1;

      var base2 = new StringBuilder( bytes.Length * 8 );

      var binary = Convert.ToString( bytes[ idx ], 2 );

      base2.Append( binary );

      for( idx--; idx >= 0; idx-- )
      {
        base2.Append( Convert.ToString( bytes[ idx ], 2 ).PadLeft( 8, '0' ) );
      }
      
      string a = base2.ToString( );
      a = a.TrimStart( '0' );
      return a;
    }

    private static BigInteger BinToInteger( string value, int baseNumber )
    {
      BigInteger res = 0;

      foreach( char c in value )
      {
        res *= baseNumber;
        res += c == '1' ? 1 : 0;
      }

      return res;
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

    public static int getInt( )
    {
      var line = Console.ReadLine( );
      var token = line.Trim( );

      int number = int.Parse( token );
      return number;
    }

    public static int ReturnDivisor( BigInteger num )
    {
      if( num < 2 )
        return 0;

      if( num % 2 == 0 ) return 2;
      var limit = BigInteger.Min( num.Sqrt( ), 1000000);
      for( int i = 3; i <= limit; i = i + 2 )
      {
        if( num % i == 0 )
        {
          return i;
        }
      }
      return 0;
    }

    public static BigInteger Sqrt( this BigInteger n )
    {
      if( n == 0 ) return 0;
      if( n > 0 )
      {
        int bitLength = Convert.ToInt32( Math.Ceiling( BigInteger.Log( n, 2 ) ) );
        BigInteger root = BigInteger.One << ( bitLength / 2 );

        while( !isSqrt( n, root ) )
        {
          root += n / root;
          root /= 2;
        }

        return root;
      }

      throw new ArithmeticException( "NaN" );
    }

    private static Boolean isSqrt( BigInteger n, BigInteger root )
    {
      BigInteger lowerBound = root * root;
      BigInteger upperBound = ( root + 1 ) * ( root + 1 );

      return ( n >= lowerBound && n < upperBound );
    }
  }
}
