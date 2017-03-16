import java.io.File;
import java.io.FileWriter;
import java.util.Locale;
import java.util.Scanner;

@SuppressWarnings( "nls" )
public class R1A
{
  public static void main( final String[] args ) throws Exception
  {
    final Scanner in = new Scanner( new File( "R1A.in" ) );
    in.useLocale( Locale.US );
    final FileWriter out = new FileWriter( "R1A.out" );

    boolean diamond;

    for( int t = in.nextInt(), i = 1; i <= t; i++ )
    {
      diamond = false;
      final int n = in.nextInt();
      final int[][] p = new int[n][n];

      for( int j = 0; j < n; j++ )
      {
        for( int m = in.nextInt(), k = 0; k < m; k++ )
        {
          final int u = in.nextInt() - 1;
          if(diamond) continue;

          p[j][u]++;

          if( p[j][u] > 1 )
          {
            diamond = true;
            continue;
          }

          for( int zi = 0; zi < n; zi++ )
          {
            if( diamond ) break;

            if( p[u][zi] > 0 )
            {
              p[j][zi]++;

              if( p[j][zi] > 1 )
              {
                diamond = true;
                break;
              }
            }

            if( p[zi][j] > 0 )
            {
              p[zi][u]++;

              if( p[zi][u] > 1 )
              {
                diamond = true;
                break;
              }
            }

            for( int zj = 0; zj < n; zj++ )
            {
              if( diamond ) break;

              if( p[zi][j] > 0 && p[u][zj] > 0 )
              {
                p[zi][zj]++;

                if( p[zi][zj] > 1 )
                {
                  diamond = true;
                  break;
                }
              }
            }
          }
        }
      }

      out.write( "Case #" + i + ": " + ( diamond ? "Yes" : "No" ) + "\n" );
    }

    in.close();
    out.close();
  }
}
