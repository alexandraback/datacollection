import java.util.Scanner ;
import java.io.FileReader ;
import java.io.BufferedWriter ;
import java.io.FileWriter ;
import java.io.IOException ;

class Q3
{
	public static int calc( int stone )
	{
		int ans = 0 ;
		if( stone % 2 == 0 )
		{
			ans = stone + (int)Math.pow( 2 , (stone - 4)/2 ) ;
		}
		else
		{
			ans = calc( stone - 1 ) + 1 ;
		}
		return ans ;
	}
	public static void main( String args[] )
	{
		try
		{
			Scanner s = new Scanner( new FileReader( "input.txt" ) ) ;
			BufferedWriter out = new BufferedWriter( new FileWriter("output.txt") ) ;
			
			int T = s.nextInt() ;
			for( int t = 0 ; t < T ; t++ )
			{
				String str = s.next() ;
				int N = Integer.parseInt( str );
				str = s.next() ;
				int M = Integer.parseInt( str );
				str = s.next() ;
				int K = Integer.parseInt( str );
				
				boolean gotIt = false ;
				for( int i = 4 ; i <= N*M; i++ )
				{
					int k = calc( i ) ;
					if( k >= K )
					{
						out.write( "Case #"+ (t+1) +": "+ i);
						if( t != T - 1 )
							out.write("\n") ;
						gotIt = true ;	
						out.flush();
						break ;	
					}
				}
				if( !gotIt )
				{
					out.write( "Case #"+ (t+1) +": "+ K);
					if( t != T - 1 )
						out.write("\n") ;
					out.flush();
				}
			}
			out.close() ; 
		}
		catch( IOException e )
		{
			System.out.println( e );
		}
	}
}