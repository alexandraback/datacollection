import java.io.File;
import java.io.FileWriter;
import java.util.Locale;
import java.util.Scanner;

@SuppressWarnings( "nls" )
public class R1A
{

  public static void main( final String[] args ) throws Exception
  {
    final Scanner in = new Scanner( new File( "R1A.txt" ) );
    in.useLocale( Locale.US );
    final FileWriter out = new FileWriter( "R1A.out" );

    final int n = in.nextInt();

    for( int i = 0; i < n; i++ )
    {
      final int a = in.nextInt();
      final int b = in.nextInt();
      final double[] p = new double[a];

      for( int j = 0; j < a; j++ )
        p[j] = in.nextDouble();

      out.write( "Case #" + (i+1) + ": " + calcExpectedKeystrokes( a, b, p ) + "\n" );
    }

    in.close();
    out.close();
  }

  static double calcExpectedKeystrokes( final int a, final int b, final double[] p )
  {
    double exp = b + 2;
    double pp = 1;

    for( int bsp = a-1; bsp >= 0; bsp-- )
    {
      pp*=p[a-1-bsp];
      final double e = ( 2*bsp + b - a + 1 ) * pp + ( 2*bsp + b - a + 1 + b + 1 ) * ( 1 - pp );
      exp = Math.min( exp, e );
    }

    return exp;
  }
}
