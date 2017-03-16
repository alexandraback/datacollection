import java.util.*;
import java.io.*;
public class D
{
	public static void main(String[] args) throws Exception
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		
		Scanner in = new Scanner(new File("D-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("D-small.out"));
		
		int t = in.nextInt();
		for(int x = 0; x < t; x++)
		{
			int k = in.nextInt();
			int c = in.nextInt();
			int s = in.nextInt();
			
			out.print("Case #" + (x + 1) + ":");
			
			if(s < (k + c - 1) / c)
			{
				out.println(" IMPOSSIBLE");
			}
			else
			{
				for(int y = 0; y < k; y += c)
				{
					long current = 0;
					long pow = 1;
					for(int z = 0; z < c && y + z < k; z++)
					{
						current += (y + z) * pow;
						pow *= k;
					}
					
					out.print(" " + (current + 1));
				}
				
				out.println();
			}
		}
		
		out.close();
	}
}
