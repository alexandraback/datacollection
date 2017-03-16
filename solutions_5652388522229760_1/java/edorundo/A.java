import java.util.*;
import java.io.*;
public class A
{
	public static boolean[] seen;
	
	public static void main(String[] args) throws Exception
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		
		Scanner in = new Scanner(new File("A-large.in"));
		PrintWriter out = new PrintWriter(new File("A-large.out"));
		
		int t = in.nextInt();
		for(int x = 0; x < t; x++)
		{
			int n = in.nextInt();
			
			if(n == 0)
			{
				out.println("Case #" + (x + 1) + ": INSOMNIA");
				continue;
			}
			
			seen = new boolean[10];
			check(n);
			
			int val = n;
			
			while(!done())
			{
				val += n;
				check(val);
			}
			
			out.println("Case #" + (x + 1) + ": " + val);
		}
		
		out.close();
	}
	
	public static void check(int val)
	{
		while(val > 0)
		{
			seen[val % 10] = true;
			val /= 10;
		}
	}
	
	public static boolean done()
	{
		for(int i = 0; i < seen.length; i++)
		{
			if(!seen[i])
			{
				return false;
			}
		}
		
		return true;
	}
}
