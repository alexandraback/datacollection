using System;
using System.Collections.Generic;
using System.IO;

public class GCJ1
{
  static string fInp = @"e:\zin.txt";
  //static string fInp = @"e:\A-large-practice.in";
  static string fOut = @"e:\zout.txt";
  public static void Main ( )
  {
    using ( StreamWriter sw = new StreamWriter ( fOut, false ) )
    {
      Console.SetIn ( new StreamReader ( fInp ) );
      Console.SetOut ( sw );
      Process ( );
    }

    CopyToScreen ( );
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

  static string TestCase()
  {
    Dictionary<int, List<int>> prts = new Dictionary<int,List<int>>();
    Dictionary<KeyValuePair<int,int>, int> dict = new Dictionary<KeyValuePair<int, int>, int> ( );
    int N = int.Parse ( Console.ReadLine ( ) );
    int Mi = 0;
    for ( int i=0; i < N; i++ )
    {
      int[] xx = ReadLineToInts ( );
      Mi = xx[0];
      prts.Add ( i + 1, new List<int> ( ) );
      for ( int j=0; j < Mi; j++ )
      {
        int prt = xx[j + 1];
        prts[i + 1].Add ( prt );
        //dict.Add ( new KeyValuePair<int, int> ( i + 1, prt ), 1 );
      }
    }

    int[] visited = new int[N+1];
    for ( int i=1; i <= N; i++ )
    {

      int root = i;
      List<int> clds = new List<int>();
      if (prts.ContainsKey(root))
        clds = prts[root];

      for ( int j=0; j <= N; j++ )
        visited[j] = 0;
      Stack<int> stk = new Stack<int>();
      stk.Push(root);
      while ( stk.Count > 0 )
      {
        int r = stk.Pop();
        foreach ( int c in prts[r] )
        {
          stk.Push ( c );
          visited[c]++;
        }
      }
      for ( int j=0; j <= N; j++ )
        if ( visited[j] > 1 )
          return "Yes";
    }

    return "No";
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

  public static void CopyToScreen ( )
  {
    StreamWriter consoleOut = new StreamWriter ( Console.OpenStandardOutput ( ) );
    consoleOut.AutoFlush = true;
    Console.SetOut ( consoleOut );
    using ( StreamReader sr = new StreamReader ( fOut ) )
    {
      string line;
      while ( ( line = sr.ReadLine ( ) ) != null )
        Console.WriteLine ( line );
    }
  }

}