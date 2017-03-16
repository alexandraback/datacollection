import java.io.*;
import java.util.*;


public class ProblemA
{
	static HashSet hs;
	
	public static void main(String args[])
	{
		hs = new HashSet();
		long z = 1;
		for(int i = 0; i <= 40; i++)
		{
			hs.add(z);
			z = z * 2;
		}
		
		try
		{
			BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
			
			int cases = Integer.parseInt(br.readLine());
			
			for(int i = 0; i < cases; i++)
			{
				System.out.print("Case #" + (i+1) + ": ");
				
				String input = br.readLine();
				
				StringTokenizer st = new StringTokenizer(input, "//");
				
				long p = Long.parseLong(st.nextToken());
				long q = Long.parseLong(st.nextToken());
				process(p, q);
			}
			
			System.out.println();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
		//System.out.println(hs.toString());
	}
	
	public static void process(long p, long q)
	{
		Fraction f = lowFraction(p, q);
		p = f.a;
		q = f.b;
		
		if(!hs.contains(q))
		{
			System.out.println("impossible");
			return;
		}
		
		int answer = 1;
		
		while(true)
		{
			if(possible(p, q))
			{
				System.out.println(answer);
				return;
			}
			
			p = p * 2;
			answer++;
		}
	} 
	
	public static boolean possible(long p, long q)
	{
		long newN = (p*2)-q;
		
		if(newN >= 0)
		{
			return true;
		}
		return false;
	}
	
	public static Fraction lowFraction(long a, long b)
	{
	    long gcm = gcm(a, b);
	    return new Fraction(a/gcm, b/gcm);
	}
	
	public static long gcm(long a, long b)
	{
	    return b == 0 ? a : gcm(b, a % b);
	}
}

class Fraction
{
	long a;
	long b;
	
	public Fraction(long a, long b)
	{
		this.a = a;
		this.b = b;
	}
}
