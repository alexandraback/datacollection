import java.util.*;
import java.math.*;

public class coinJam {
	public static void main(String [] args)
	{
		new coinJam();
	}
	
	public ArrayList<Integer> primes;
	
	public coinJam()
	{
		primes = erathostenes();
		
		Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
		
		for( int t = 1; t <= T; t++ )
		{
			System.out.println("Case #" + t + ": ");
			
			int N = scan.nextInt(); int J = scan.nextInt();
			
			long top = (long)(1)<<(N-1);
			
			for( long n = 1; n < top; n+=2)
			{
				boolean prime = false;
				
				StringBuilder sB = new StringBuilder();
				
				for( int i = 2; i <= 10; i++ )
				{
					int primeTry = prime(new BigInteger(Long.toBinaryString(n+top), i));
					
					if(primeTry == -1)
						prime = true;
					else
						sB.append( primeTry + " " );
					
					//System.out.println("Tried one");
				}
				
				if( !prime )
				{
					System.out.println(Long.toBinaryString(n+top) + " " + sB.toString());
					J--;
				}
				
				if(J == 0)
				{
					//System.out.println("Done");
					break;
				}
			}
		}
	}
	
	public int prime(BigInteger n)
	{
		for( int i = 0; i < primes.size(); i++ )
		{
			if( n.mod(BigInteger.valueOf(primes.get(i))) == BigInteger.ZERO )
				return primes.get(i);
		}
		
		//System.out.println("prime " + n);
		
		return -1;
	}
	
	/*public boolean[] segmentedErathostenes()
	{
		Arrays.fill(segment, (byte) 0);

		long debut = numSegment * MAX_SEGMENT;
		long fin = debut + MAX_SEGMENT;
		long finSqrt = (long) Math.sqrt(fin) + 1;

		int p = -1;
		int i = 1;
		while (p < finSqrt) {
		  p = amorce[i++];
		  long j = p - (debut % p);
		  j += ((j & 1) == 0 ? p : 0);

		  long p2 = p * 2;
		  while (j < MAX_SEGMENT) {
		    segment[(int) (j >> 4)] |= (1 << ((j >> 1) & 7));
		    j += p2;
		  }
		}
	}*/
	
	public ArrayList<Integer> erathostenes()
	{
		boolean array[] = new boolean[10000];
		for (int i = 3; i < 100; i += 2) {
			  if (!array[(i / 2)]) {
			    int j = (i * i) / 2;
			    while (j < 10000) {
			      array[j] = true;
			      j += i;
			    }
			  }
		}
		
		ArrayList<Integer> primes = new ArrayList<Integer>();
		
		for( int i = 0; i < 10000; i++ )
			if(array[i]) primes.add(i);
		
		return primes;
	}
}
