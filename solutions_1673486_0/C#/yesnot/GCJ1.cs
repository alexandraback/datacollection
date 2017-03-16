#define TESTx

using System;
using System.Collections.Generic;
using System.IO;

public class GCJ1
{
  public static void Main ( )
  {
    using ( StreamWriter sw = new StreamWriter ( @"e:\z1out.txt", false ) )
    {
      Console.SetIn ( new StreamReader ( @"e:\zin.txt" ) );
#if !TEST
      Console.SetOut ( sw );
#else
      Console.SetOut ( Console.Out );
#endif
      Process ( );
    }
  }

  private static void Process( )
  {
    int T = int.Parse ( Console.ReadLine ( ) );
    for ( int i=1; i <= T; i++ )
    {
      Console.Write ( "Case #" + i + ": " );
      Console.WriteLine ( TestCase ( ) );
    }

    return;
  }

  static double TestCase()
  {
    int[] ab = ReadLineToInts ( );
    int A = ab[0];
    int B = ab[1];
    double [] p = ReadLineToDoubles ( );
    double minz = double.MaxValue;
    double ksexp;

    double pright;
    double pwrong;
    int ksright;
    int kswrong;

    //opt1
    pright = 1;
    for ( int i=0; i < A; i++ )
    {
      pright *= p[i];
    }
    pwrong = 1 - pright;
    int rem = B - A;
    ksright = rem + 1;
    kswrong = rem + B + 2;

    ksexp = pright * ksright + pwrong * kswrong;
    minz = Math.Min ( minz, ksexp );

    //opt 2
    for ( int bs=1; bs <= A; bs++ )
    {
      pright = 1;
      for ( int i=0; i < A - bs; i++ )
      {
        pright *= p[i];
      }
      pwrong = 1 - pright;
      rem = B - A + bs;
      ksright = bs + rem + 1;
      kswrong = bs + rem + B + 2;

      ksexp = pright * ksright + pwrong * kswrong;
      minz = Math.Min ( minz, ksexp );
    }

    //opt 3
    ksright = B + 2;
    kswrong = B + 2;

    ksexp = pright * ksright + pwrong * kswrong;
    minz = Math.Min ( minz, ksexp );

    return minz;
  }

  public static int[] ReadLineToInts ( )
  {
    string line = Console.ReadLine ( );
    string[] arStrings = line.Split ( new char[] { ' ' } );

    int N = arStrings.Length;
    int[] ints = new int[N];
    for ( int i=0; i < N; i++ )
      ints[i] = int.Parse ( arStrings[i] );
    return ints;
  }

  public static double[] ReadLineToDoubles ( )
  {
    string line = Console.ReadLine ( );
    string[] arStrings = line.Split ( new char[] { ' ' } );

    int N = arStrings.Length;
    double[] nums = new double[N];
    for ( int i=0; i < N; i++ )
      nums[i] = double.Parse ( arStrings[i] );
    return nums;
  }


}