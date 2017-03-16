import java.util.Scanner ;
import java.io.FileReader ;
import java.io.BufferedWriter ;
import java.io.FileWriter ;
import java.io.IOException ;

class Q1
{
	public static long gcd( long a , long b ) 
	{ 
		return b == 0 ? a : gcd( b , a%b ) ; 
	}
	public static boolean checkQ( long Q )
	{
		boolean ans = false ;
		for( long i = 0 ; i <= 40 ; i++ )
		{
			if( Q  ==  Math.pow( 2 , i ) )
			{ 
			    ans = true ;
				break ;
			}
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
				String str = s.next();
				long P = Long.parseLong( str.split("/")[0]  );
				long Q ;
				if( str.indexOf("/") == -1 )
					Q = 1 ;
				else
					Q = Long.parseLong( str.split("/")[1]   ) ;
				
				long r = gcd( P , Q ) ;
				P = P / r ;
				Q = Q / r ;
				
				if (  checkQ( Q ) )
				{
					int count = 0 ;
					double num = (double)P/(double)Q ;
					
					while( num < 1 )
					{
						num *= 2 ;
						count++ ;
					}
					if( count == 0 )
						count = 1 ;
					out.write( "Case #"+ (t+1) +": "+ count );
					if( t != T - 1 )
						out.write("\n") ;
					out.flush();
				}
				else
				{
					out.write( "Case #"+ (t+1) +": impossible ");
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