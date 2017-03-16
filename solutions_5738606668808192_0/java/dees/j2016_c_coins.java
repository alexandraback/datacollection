import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class j2016_c_coins {

  static List<BigInteger> primes;
  static void preparePrimes()
  {
    primes = new Vector<BigInteger>();
    BigInteger cprime = new BigInteger("2");

    for ( int i = 0; i < 10000; ++i )
    {
      primes.add( cprime );
      cprime = cprime.nextProbablePrime();
    }
  }

  public static BigInteger getDivider( BigInteger b )
  {
    for ( BigInteger prim : primes )
    {
      if ( BigInteger.ZERO.equals( b.remainder( prim ) ) )
        return prim;
    }
    return null;
  }

  public static void solve(int n, int j)
  {
    Set<Integer> set = new HashSet<Integer>();
    while ( set.size() < j )
    {
      // try find sth
      BigInteger b = new BigInteger( n-2, new java.util.Random() );
      int bint = b.intValue();
      if ( set.contains( bint ) )
        continue;

      String str = b.toString( 2 );
      while ( str.length() < n-2 )
        str = "0" + str;
      str = "1" + str + "1";

      boolean fail = false;
      List<BigInteger> list = new Vector<BigInteger>();
      // try if any of them are prime
      for ( int radix = 2; radix <= 10; ++radix )
      {
        BigInteger t = new BigInteger( str, radix );
        BigInteger res = getDivider(t);
        if ( res == null )
        {
          fail = true;
          break;
        }
//        list.add( t );
        list.add( res );
      }
      if ( fail )
        continue;
      set.add( bint );
      System.out.print(str);
      for ( BigInteger it : list )
        System.out.print(" " + it);
      System.out.println();
    }

  }

  public static void main(String[] args) {
    preparePrimes();
    Scanner in = new Scanner(new BufferedReader (new InputStreamReader(System.in)));
    int ncase = in.nextInt();
    for (int icase=1;icase<=ncase;++icase)
    {
      int n = in.nextInt();
      int j = in.nextInt();
      System.out.println("Case #" + icase + ":" );
      solve(n,j);
    }
  }
}
