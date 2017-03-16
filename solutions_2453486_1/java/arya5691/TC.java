
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class TC
{
    static char[][] board;
    static int N=4;
    
    static String checkRow( int r )
    {
        char c=board[r][0];
        if( c=='T')
            c=board[r][1];
        if( c=='.')
            return null;
        
        for( int i=1; i<N; i++ )
        {
            if( ( board[r][i] == c )||( board[r][i] == 'T' ))
                continue;
            return null;
        }
        return c+"";
    }
    
    static String ROW()
    {
        for( int i=0; i<4; i++ )
        {
            String res=checkRow(i);
            if( res != null )
                return res;
        }
        return null;
    }
    
    static String COL()
    {
        for( int i=0; i<4; i++ )
        {
            String res=checkCol(i);
            if( res != null )
                return res;
        }
        return null;
    }
    
    static String checkCol( int col )
    {
        char c=board[0][col];
        if( c=='T')
            c=board[1][col];
        if( c=='.')
            return null;
        
        for( int i=1; i<N; i++ )
        {
            if( ( board[i][col] == c )||( board[i][col] == 'T' ))
                continue;
            return null;
        }
        
        return c+"";
    }
    
    static String checkD1() 
    {
        char c=board[0][0];
        if( c=='T')
            c=board[1][1];
        if( c=='.')
            return null;
        
        for( int i=1; i<N; i++ )
        {
            if( ( board[i][i] == c )||( board[i][i] == 'T' ))
                continue;
            return null;
        }
        return c+"";
    }
    
    static String checkD2() 
    {
        char c=board[0][3];
        if( c=='T')
            c=board[1][2];
        if( c=='.')
            return null;
        
        for( int i=1; i<N; i++ )
        {
            if( ( board[i][N-1-i] == c )||( board[i][N-1-i] == 'T' ))
                continue;
            return null;
        }
        return c+"";
    }
    
    static boolean isDone()
    {
        for( int i=0; i<N; i++ )
        {
            for( int j=0; j<N; j++ )
            {
                if( board[i][j] == '.')
                    return false;
            }
        }
        return true;
    }
    
    static String status()
    {
        String stat=ROW();
        if( stat != null )
        {
            String res=stat+" won";
            return res;
        }
        stat=COL();
        if( stat != null )
        {
            String res=stat+" won";
            return res;
        }
        stat=checkD1();
        if( stat != null )
        {
            String res=stat+" won";
            return res;
        }
        stat=checkD2();
        if( stat != null )
        {
            String res=stat+" won";
            return res;
        }
        if( isDone() )
            return "Draw";
        else
            return "Game has not completed" ;
    }
   
    public static void main( String[] args ) throws IOException
    {
        BufferedReader br=new BufferedReader( new InputStreamReader( System.in ));
        BufferedWriter out=new BufferedWriter( new OutputStreamWriter( System.out ));
        int T=Integer.parseInt(br.readLine() );
        for( int t=1; t<=T; t++ )
        {
            if( t!=1 )
                br.readLine();
            board=new char[4][4];
            for( int i=0; i<4; i++ )
                board[i]=br.readLine().toCharArray();
            String res="Case #" +t+": ";
            res=res+status();
            out.write( res +"\n");
        }
        out.close();
    }
    
    
}
