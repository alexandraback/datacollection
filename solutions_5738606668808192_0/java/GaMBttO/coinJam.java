import java.util.*;
public class coinJam {
	public static void main(String [] args)
	{
		new coinJam();
	}
	
	public coinJam()
	{
		Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
		
		for( int t = 1; t <= T; t++ )
		{
			System.out.println("Case #" + t + ": ");
			
			int N = scan.nextInt(); int J = scan.nextInt();
			
			for( int n = 1; n < 1<<(N-1); n+=2)
			{
				boolean prime = false;
				
				StringBuilder sB = new StringBuilder();
				
				for( int i = 2; i <= 10; i++ )
				{
					long primeTry = prime(Long.parseLong(Long.toBinaryString(n+(1<<(N-1))), i));
					
					if(primeTry == -1)
						prime = true;
					else
						sB.append( primeTry + " " );
				}
				
				if( !prime )
				{
					System.out.println(Integer.toBinaryString(n+(1<<(N-1))) + " " + sB.toString());
					J--;
				}
				
				if(J == 0) break;
			}
		}
	}
	
	public long prime(long n)
	{
		for( long i = 2; i*i <= n; i++ )
		{
			if( n%i == 0 )
				return i;
		}
		
		//System.out.println("prime " + n);
		
		return -1;
	}
}
