import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class B
{
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "B-small0";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));

		int noOfCases = in.nextInt();
		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			int E = in.nextInt();
			int R = in.nextInt();
			int N = in.nextInt();
			int [] values = new int[N];
	        int absMax = 0;
			for (int i = 0; i < N; i++)
			{
				values[i] = in.nextInt();
				absMax += E*values[i];
			}
			int [] gains = new int [absMax+1];
			gains[0]= E;
			int maxGain = 0;
			int lastestMax = 0;
			//System.out.println(absMax);
			for (int i = 0; i < N; i++)
			{ 
				for (int next = 0; next <= lastestMax; next++)
				{
					for (int energy = 0; energy <= gains[next]; energy++)
					{
						int  posEnergy= energy*values[i];
						int left = gains[next] - energy;
						if (left > gains[next + posEnergy])
							gains[next + posEnergy] = left;
						if (next + posEnergy > maxGain)
							maxGain= next + posEnergy;
					}
			
				}
				lastestMax = maxGain;
				for (int next = 0; next <= lastestMax; next++)
					gains[next] = Math.min(E, gains[next]+ R);
				
//				   for (int intVal : gains)
//					    System.out.print(intVal + " "); 
//					   System.out.println();

				
			}

			System.out.println("Case #" + caseNo + ": " + maxGain);
			out.println("Case #" + caseNo + ": " + maxGain);
		}
		in.close();
		out.close();

	}

}
