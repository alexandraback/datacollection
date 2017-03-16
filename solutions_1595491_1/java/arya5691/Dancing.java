
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Dancing
{
    
    static int n;
    static int[] score;
    
    static int solve( int surp, int p )
    {
        int notPossible = 0;
        int cutOff = 3*p - 4;
        int surCutOff = 3*p-2;
        

        Arrays.sort( score );

        if( p == 0 )
            return n;

        if( p==1 ) // only score of zero is invalid
        {
            for( int i=0; i<n; i++ )
            {
                if( score[ i ] == 0 )
                    notPossible++;

                else
                    break;
            }
            
            return n-notPossible;
        }

        for( int i=0; i<n; i++ )
        {
            /* if( score[ i ] <= p )
            {
                notPossible++;
                continue;
            } */
            
            if( score[ i ]< cutOff )
            {
                notPossible++;
                continue;
            }

            // check if surprising
            else if(score[i] < surCutOff) // surprising possible
            {
                if( surp > 0 )
                {
                    surp--;
                    continue;
                }

                else
                {
                    notPossible++;
                }
            }

            else if( score[ i ] >= surCutOff )
            {
                break;
            }



            else
                break;

        }

        
        return n-notPossible;
        
    }

    public static void main( String[] args ) throws IOException
    {
        FileWriter fr= new FileWriter("/home/gowri/Desktop/out.txt");
        BufferedWriter out = new BufferedWriter( fr );
        BufferedReader br = new BufferedReader( new InputStreamReader( System.in ));
        int T = Integer.parseInt( br.readLine() );
        String s;
        StringTokenizer tok;

        for( int i=0; i<T; i++ )
        {
            s = br.readLine();
            tok = new StringTokenizer( s );
            
            n = Integer.parseInt( tok.nextToken() );
            score = new int[ n ];

            int surp = Integer.parseInt( tok.nextToken() );
            int p = Integer.parseInt( tok.nextToken() );

            for( int j=0; j<n; j++ )
            {
                score[ j ] = Integer.parseInt( tok.nextToken() );
            }

            String res = String.format( "Case #%d: ", i+1 );
            out.write( res );
            out.write( ( "" + solve( surp, p ) ) );
            out.newLine();
        }

        out.close();
    }

}

