import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class BFF {

  private static String getKey( int curr, int bff ) {
    return String.format( "%d:%d", curr, bff );
  }

  private static int countLength( int[] bffs, int n, int start ) {
    HashMap<String, Integer> visited = new HashMap<String, Integer>();
    int last = 0;
    int curr = start;

    while ( !visited.containsKey( getKey( curr, bffs[curr] ) ) ) {
      last = curr;
      visited.put( getKey( curr, bffs[curr] ), bffs[curr] );
      curr = bffs[curr];
    }

    for ( int i = 1; i <= n; i++ ) {
      if ( bffs[i] == start && !visited.containsKey( getKey( i, bffs[i] ) ) ) {
        visited.put( getKey( i, bffs[i] ), bffs[i] );
        break;
      }
    }

    for ( int i = 1; i <= n; i++ ) {
      if ( bffs[i] == last && !visited.containsKey( getKey( i, bffs[i] ) ) ) {
        visited.put( getKey( i, bffs[i] ), bffs[i] );
        break;
      }
    }

    return visited.size();
  }

  public static void main( String[] args ) {
    Scanner in = new Scanner( System.in );
    int t = in.nextInt();

    for ( int testCase = 1; testCase <= t; testCase++ ) {
      int n = in.nextInt();

      int[] bffs = new int[1001];
      int[] kids = new int[1001];
      System.out.format( "Case #%d: ", testCase );
      for ( int i = 1; i <= n; i++ ) {
        int kid = in.nextInt();
        bffs[i] = kid;
        kids[kid] += 1;
      }

      int max = 0;
      for ( int j = 1; j <= n; j++ ) {
        int count = countLength( bffs, n, j );
        if ( count > max ) {
          max = count;
        }
      }
      System.out.format( "%d\n", max );
    }
  }

}
