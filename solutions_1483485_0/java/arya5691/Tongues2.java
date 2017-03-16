
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class Tongues2
{
    static char[] gMap = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};


    static String translate( String s )
    {
        String res = "";
        for( int i=0; i<s.length(); i++ )
        {
            char c = s.charAt(i);

            if( c == ' ')
                res += ' ';


            else
                res += gMap[ c - 'a' ];
            

        }

        return res;
    }

    public static void main( String[] args ) throws IOException
    {
        FileWriter fr= new FileWriter("/home/gowri/Desktop/out.txt");
        BufferedWriter out = new BufferedWriter( fr );
        BufferedReader br = new BufferedReader( new InputStreamReader( System.in ));
        int n = Integer.parseInt( br.readLine() );

        for( int i=0; i<n; i++ )
        {
            String s = br.readLine();
            String res = String.format( "Case #%d: ", i+1 );
            out.write( res );
            out.write( translate( s ) );
            out.newLine();
        }

        out.close();
    }
}

