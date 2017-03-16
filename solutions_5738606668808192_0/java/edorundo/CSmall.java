import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class CSmall
{
	public static final int n = 16;
	public static final int j = 50;
	
	public static void main(String[] args) throws Exception
	{
//		PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("C-small.out"));
		
		out.println("Case #1:");
		
		int count = 0;
		for(int x = 0; x < (1 << n) && count < j; x++)
		{
			if(x % 2 == 1 && (x & (1 << (n - 1))) > 0)
			{
				ArrayList<Integer> primes = new ArrayList<Integer>();
				
				for(int y = 2; y <= 10; y++)
				{
					BigInteger num = BigInteger.ZERO;
					BigInteger pow = BigInteger.ONE;
					for(int z = 0; z < n; z++)
					{
						if((x & (1 << z)) > 0)
						{
							num = num.add(pow);
						}
						
						pow = pow.multiply(BigInteger.valueOf(y));
					}
					
					for(int a = 2; a < 100; a++)
					{
						if(num.mod(BigInteger.valueOf(a)).compareTo(BigInteger.valueOf(0)) == 0)
						{
							primes.add(a);
							break;
						}
					}
				}
				
				if(primes.size() == 9)
				{
					count++;
					
					out.print(Integer.toBinaryString(x));
					
					for(int p : primes)
					{
						out.print(" " + p);
					}
					
					out.println();
				}
			}
		}
		
		out.close();
	}
}
