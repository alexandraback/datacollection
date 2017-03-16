import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TC
{
    static int[][] lawn, start;
    static int M, N;
    
    static int rowMax( int r )
    {
        int MAX=-1;
        for( int j=0; j<N; j++ )
            MAX=Math.max(MAX, lawn[r][j]);
        return MAX;
    }
    
    static int colMax( int c )
    {
        int MAX=-1;
        for( int i=0; i<M; i++ )
            MAX=Math.max(MAX, lawn[i][c]);
        return MAX;
    }
    
    static void cutRow( int r )
    {
        int set=rowMax( r );
        for( int j=0; j<N; j++ )
        {
            start[r][j]=Math.min( start[r][j], set );
        }
    }
    
    static void cutCol( int c )
    {
        int set=colMax( c );
        for( int i=0; i<M; i++ )
        {
            start[i][c]=Math.min( start[i][c], set );
        }
    }
   
    static boolean isOk()
    {
        for( int i=0; i<M; i++ )
        {
            for( int j=0; j<N; j++ )
            {
                if( start[i][j] != lawn[i][j])
                    return false;
            }
        }
        return true;
    }
    
    static void ROWS()
    {
        for( int i=0; i<M; i++ )
            cutRow( i );
        for( int j=0; j<N; j++ )
            cutCol( j );
    }
    
    static void COLS()
    {
        for( int j=0; j<N; j++ )
            cutCol( j );
        for( int i=0; i<M; i++ )
            cutRow( i );
    }
    
    static String status()
    {
        ROWS();
        boolean res=isOk();
        if( res )
            return "YES";
        for( int[] a : start )
                Arrays.fill( a, 100 );
        COLS();
        res=isOk();
        if( res )
            return "YES";
        return "NO";
    }
    
    public static void main( String[] args ) throws IOException
    {
        BufferedReader br=new BufferedReader( new InputStreamReader( System.in ));
        BufferedWriter out=new BufferedWriter( new OutputStreamWriter( System.out ));
        int T=Integer.parseInt(br.readLine() );
        for( int t=1; t<=T; t++ )
        {
            String s=br.readLine();
            StringTokenizer tok=new StringTokenizer( s );
            M=Integer.parseInt( tok.nextToken() );
            N=Integer.parseInt( tok.nextToken() );
            start=new int[M][N];
            for( int[] a : start )
                Arrays.fill( a, 100 );
            lawn=new int[M][N];
            for( int i=0; i<M; i++ )
            {
                s=br.readLine();
                tok=new StringTokenizer( s );
                for( int j=0; j<N; j++ )
                    lawn[i][j]=Integer.parseInt( tok.nextToken() );
            }
            String res="Case #" +t+": ";
            res=res+status();
            out.write( res +"\n");
        }
        out.close();
    }
    
    
}
