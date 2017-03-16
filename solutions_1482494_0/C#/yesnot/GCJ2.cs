#define TESTx

using System;
using System.Collections.Generic;
using System.IO;

public class GCJ2
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

  private static void Process ( )
  {
    int T = int.Parse ( Console.ReadLine ( ) );
    for ( int i=1; i <= T; i++ )
    {
      Console.Write ( "Case #" + i + ": " );
      Console.WriteLine ( TestCase ( ) );
    }

    return;
  }

  static int Cmp ( KeyValuePair<int, int> a, KeyValuePair<int, int> b )
  {
    if ( a.Value != b.Value )
      return b.Value - a.Value;
    else
      return b.Key - a.Key;
  }

  static string TestCase ( )
  {
    long minz=0;
    List<KeyValuePair<int,int>> reqs = new List<KeyValuePair<int, int>> ( );
    int N = int.Parse ( Console.ReadLine ( ) );
    int[] req1 = new int[N];
    int[] req2 = new int[N];
    for ( int i=0; i < N; i++ )
    {
      int[] xx = ReadLineToInts ( );
      req1[i] = xx[0];
      req2[i] = xx[1];
      reqs.Add ( new KeyValuePair<int, int> ( req1[i], req2[i] ) );
      
    }
    //sort
    reqs.Sort ( Cmp );
    int j=0;
    bool zero=false;
    foreach ( KeyValuePair<int,int> pair in reqs )
    {
      req1[j] = pair.Key;
      req2[j] = pair.Value;
      j++;
      if ( pair.Key == 0 )
        zero = true;
    }

    if ( !zero )
      return "Too Bad";

    List<int> completed = new List<int> ( );
    for ( int i=0; i < N; i++ )
      completed.Add ( 0 );

    int stars=0;

    for ( int i=0; i < N; i++ )
    {
      if ( reqs[i].Value == 0 )
      {
        completed[i] = 2;
        stars += 2;
        minz++;
        break;
      }
    }
    if ( stars == 0 )
    {
      for ( int i=0; i < N; i++ )
      {
        if ( reqs[i].Key == 0 )
        {
          completed[i] = 1;
          stars += 1;
          minz++;
          break;
        }
      }
    }
    if ( stars == 0 )
      return "Too Bad";


    while ( true )
    {
      //cek
      int ncom=0;
      for ( int i=0; i < N; i++ )
      {
        ncom += completed[i];
      }
      if ( ncom == N * 2 ) 
        break;

      long prevminz = minz;
      for ( int i=0; i < N; i++ )
      {
        if ( completed[i] == 2 ) continue;
        int req = reqs[i].Value;
        if ( stars >= req )
        {
          if ( completed[i] == 0 )
            stars += 2;
          else
            stars += 1;
          completed[i] = 2;
          minz++;
          break;
        }
      }
      if ( minz > prevminz )
        continue;

      for ( int i=0; i < N; i++ )
      {
        if ( completed[i] >= 1 ) continue;
        int req = reqs[i].Key;
        if ( stars >= req )
        {
          completed[i] = 1;
          stars += 1;
          minz++;
          break;
        }
      }

      if ( minz == prevminz )
        return "Too Bad";
    }

    return minz.ToString ( );
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