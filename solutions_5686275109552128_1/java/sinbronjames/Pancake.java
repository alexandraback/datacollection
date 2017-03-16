import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Pancake
{

	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner in = new Scanner (new File("B-large.in"));
		PrintWriter out = new PrintWriter ("pancakeoutput");
	
		int T= in.nextInt();
		for (int test = 1; test<=T; test++)
		{
			int D = in.nextInt();
			
			int best=Integer.MAX_VALUE;
			int [] P = new int [D];
			for (int i=0; i<D; i++)
			{
				P[i] = in.nextInt();
			}
			int maxIndex = 0;
			for (int i=1; i<D; i++)
			{
				if (P[i]>P[maxIndex])
					maxIndex=i;
			}
			int max = P[maxIndex];
			for (int j=1; j<=max; j++)
			{
				int total =0;
				for (int i=0; i<D; i++)
				{
					if (P[i]%j==0)
						total+=P[i]/j-1;
					else
						total+=P[i]/j;
				}
				total+=j;
				if (total<best)
					best =total;
			}
			out.println("Case #"+test+": "+best);
		}
		in.close();
		out.close();

	}

}
