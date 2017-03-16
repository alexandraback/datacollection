import java.util.Scanner;

public class Alarge {
	public static long flip(long x)
	{
		long flip = 0;
		
		if (x % 10 == 0)
		{
			return Integer.MAX_VALUE;
		}
		
		while (x > 0)
		{
			flip = flip * 10 + (x % 10);
			x /= 10;
		}
		
		return flip;
	}
	
	public static long lastFlipPoint(long x)
	{
		if (x % 10 == 0)
		{
			x--;
		}
		
		int digits = 1;
		long powerOfTen = 10;
		long mod = 10;
		
		while (x >= powerOfTen)
		{
			powerOfTen *= 10;
			digits++;
			
			if (digits % 2 == 1)
			{
				mod *= 10;
			}
		}
		
		if (digits == 1)
		{
			return Long.MAX_VALUE;
		}
		else
		{	
			long n = x - (x % mod) + 1;
			
			if (n == flip(n))
			{
				return lastFlipPoint(powerOfTen / 10);
			}
			else	
			{
				return x - (x % mod) + 1;
			}
		}
	}
	
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
		
		long N = 0;
		
		for (int Q = 1; Q <= T; Q++)
		{
			N = scan.nextLong();
			
			long x = 0;
			
			while (true)
			{
				long n = lastFlipPoint(N);
				
				if (n == Long.MAX_VALUE)
				{
					x += N;
					break;
				}
				else
				{
					x += N - n + 1;
					N = flip(n);
				}
			}
			
			System.out.printf("Case #%d: %d\n", Q, x);
		}
		
		scan.close();
	}
}
