import java.util.*;
import java.io.*;
public class C 
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new File("B-small-attempt1.in"));
		
		PrintWriter out = new PrintWriter(new FileWriter("B.out"));
		
		int t = in.nextInt();
		
		for(int x = 0; x < t; x++)
		{
			int n = in.nextInt();
			
			int X = in.nextInt();
			int Y = in.nextInt();
			
			int layer = (X + Y) / 2;
			
			double result = 0;
			
			int a;
			for(a = 0; a < layer; a++)
			{
				if(n > (4 * a + 1))
				{
					n -= 4 * a + 1;
				}
				else
				{
					break;
				}
			}
			
			if(a == layer)
			{
				if(n >= 4 * layer + 1)
				{
					result = 1;
				}
				else if(X == 0)
				{
					result = 0;
				}
				else
				{
					for(int b = Y + 1; b <= n; b++)
					{
						result += bernoulli(n, b);
					}
				}
			}
			
			out.println("Case #" + (x + 1) + ": " + result);
		}
		
		out.close();
	}
	
	public static double bernoulli(int n, int k)
	{
		return choose(n, k) * Math.pow(0.5, n);
	}
	
	public static long choose(int n, int k)
	{
		return factorial(n) / factorial(k) / factorial(n - k);
	}
	
	public static long factorial(int n)
	{
		long result = 1;
		for(int i = 2; i <= n; i++)
		{
			result *= (long)i;
		}
		
		return result;
	}
}
