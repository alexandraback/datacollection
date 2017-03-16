
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Recycle
{

    static String shiftRight( String s )
    {
        String res = "" +  s.charAt( s.length() - 1 );
        res = res + s.substring( 0, s.length()-1 );

        return res;
    }

    static int solve( int a, int b )
    {
        HashSet<String> h = new HashSet();
        int res = 0;

        for( int i=a; i<=b; i++ )
        {
            String curr = Integer.toString(i);
            if( h.contains( curr ) )
                continue;

            // else compute number of shifts
            HashSet<String> temp = new HashSet();
            String s = curr;
            temp.add( curr );
            h.add( curr);

            for( int j=0; j<curr.length()-1; j++ )
            {
                s = shiftRight( s );

                // check for leading zeroes

                if( s.charAt(0) == '0')
                    continue;

                // check if valid range
                int x = Integer.parseInt( s );

                if( ( x>=a ) && (  x<=b ))
                {
                    temp.add(s);
                    h.add( s );
                }
            }

            // now count how many such pairs ( n choose 2 = n( n-1 )/2 )

            int k = temp.size();
            res += k*( k-1 )/2;

        }

        return res;

    }

    public static void main( String[] args ) throws IOException
    {
        FileWriter fr= new FileWriter("/home/gowri/Desktop/out.txt");
        BufferedWriter out = new BufferedWriter( fr );
        BufferedReader br = new BufferedReader( new InputStreamReader( System.in ));
        int t = Integer.parseInt( br.readLine() );
        StringTokenizer tok;

        for( int i=0; i<t; i++ )
        {
            String s = br.readLine();
            tok = new StringTokenizer( s );
            
            int A = Integer.parseInt( tok.nextToken() );
            int B = Integer.parseInt( tok.nextToken() );

            String res = String.format( "Case #%d: ", i+1 );
            out.write( res );
            out.write( Integer.toString(solve( A, B ) ));
            out.newLine();
        }

        out.close();


    }
}
