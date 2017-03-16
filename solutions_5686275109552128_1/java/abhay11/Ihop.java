import java.util.*;
import java.io.*;

public class Ihop
{
	public static void main(String[] args) throws IOException
	{
		Scanner in=new Scanner(System.in);
		
		int numRuns=in.nextInt();
		for (int run=1; run<=numRuns; run++)
		{
			
			int d=in.nextInt(), max=0;
			int[] stacks=new int[d];
			for (int i=0; i<d; i++)
			{
				stacks[i]=in.nextInt();
				max=Math.max(max, stacks[i]);
			}
			
			int best=max;
			for (int i=1; i<best; i++)
			{
				int steps=i;
				for (int j=0; steps<best && j<d; j++)
					steps+=(stacks[j]-1)/i;
				best=Math.min(best, steps);
			}
			System.out.print("Case #"+run+": ");
			System.out.println(best);
		}
	}
}
		