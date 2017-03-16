import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class A {
	static Scanner in;
	static int T;
	
	public static void main(String[] args ) throws FileNotFoundException
	{
		String input = "/Users/ryanmcnamara/juniorSpring/TopCoder/GoogleCodeJam_2013_1C/tc/A-large.in";
		String output = input + "_out";
		
		in  = new Scanner( new File( input ) );
		
		System.setOut(new PrintStream(new File( output )) );
		
		
		T = in.nextInt();
		
		for ( int i = 0; i < T; i++ )
		{
			Object o = runCase( i + 1);
			
			System.out.println("Case #" + ( i + 1 ) + ": " + o);
			
		}
	}

	private static Object runCase(int iter) 
	{
	
		String s = in.next();
		int n = in.nextInt();
	
		long total = 0;
		
		long chainsSeen = 0;
		long cons = 0;

		long lastBefore = -1;
		for ( int i = 0; i < s.length();i ++  )
		{
			if ( isCons( s.charAt(i)) )
			{
				cons++;
			}
			else 
			{
				cons = 0;
			}

			
			if ( cons >= n )
			{
				
				long before = i-(n-1);
				
				long after = s.length() - (i+1);
				
				long space = before - lastBefore;
				
				space = Math.max(0, space);
				
				
				
				total += (space) * ( after + 1 );
				
				
				
				
				chainsSeen ++;
				lastBefore = before;
			}
		}
		
		return total;
		
	}
	
	public static boolean isCons( char c )
	{
		return c != 'a' && c != 'e' && c!= 'i' && c!= 'o' && c!= 'u'; 
	}
	
	public static Object bf( int c )
	{

		String s = in.next();
		int n = in.nextInt();
	
		int total = 0;
		for ( int i = 0; i < s.length(); i++ )
		{
			for ( int j = i; j < s.length(); j++ )
			{
				int numCons = 0;
				int best = 0;
				for ( int k = i; k <= j; k++ )
				{
					if ( isCons(s.charAt(k)))
					{
						numCons++;
						if ( numCons >= n )
						{
							best = Math.max(numCons, best );
						}
						
					}
					else 
					{
						numCons = 0;
					}
				}
				if ( best > 0 )
				{
					total++;
				}
			}
				
		}
		
		return total;	
	}

}
