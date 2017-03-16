import java.util.*;
import java.io.*;
public class A
{
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new File("A-small-attempt0.in"));
//		Scanner in = new Scanner(System.in);
		
		PrintWriter out = new PrintWriter(new FileWriter("A.out"));
		
		int T = in.nextInt();
		
		for(int x = 0; x < T; x++)
		{
			long r = in.nextLong();
			long t = in.nextLong();
			
			long result = 0;
			
			while(true)
			{
				long currentRing = ringArea(r);
				
				if(currentRing <= t)
				{
					result++;
					t -= currentRing;
					r += 2;
				}
				else
				{
					break;
				}
			}
			
			out.println("Case #" + (x + 1) + ": " + result);
		}
		
		out.close();
	}
	
	public static long ringArea(long r)
	{
		return (r + 1) * (r + 1) - r * r;
	}
}
