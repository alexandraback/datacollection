import java.io.*;
import java.util.*;

class Triplet
{
	public static void main (String [] args) throws IOException 
	{
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-small-attempt0.out")));
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int numCases = Integer.parseInt(st.nextToken());
		
		for (int i = 0; i < numCases; i++)
		{
			out.print("Case #" + (i+1) + ": ");
			
			st = new StringTokenizer(in.readLine());
			
			int n = Integer.parseInt(st.nextToken());
			int numSurprisings = Integer.parseInt(st.nextToken());
			int P = Integer.parseInt(st.nextToken());
			
			int min = 0;
			int minNoSurprising = 0;
			
			if (P > 1)
			{
				min = 3*P - 4;
				minNoSurprising = 3*P - 2;
			}
			else if (P == 1)
			{
				min = 1;
				minNoSurprising = 1;
			}
			else
			{
				min = 0;
				minNoSurprising = 0;
			}
			
			int[] totalPoint = new int[n];
			
			for (int j = 0; j < n; j++)
			{
				totalPoint[j] = Integer.parseInt(st.nextToken());
			}
			
			int maxCandidateWithNoSurprisings = 0;
			int maxCandidateWithSurprisings = 0;
			
			for (int j = 0; j < n; j++)
			{
				if (totalPoint[j] >= minNoSurprising)
				{
					maxCandidateWithNoSurprisings++;
				}
				else if (totalPoint[j] >= min)
				{
					maxCandidateWithSurprisings++;
				}
			}
			
			if (maxCandidateWithSurprisings <= numSurprisings)
			{
				out.print((maxCandidateWithNoSurprisings + maxCandidateWithSurprisings));
			}
			else
			{
				out.print((maxCandidateWithNoSurprisings + numSurprisings));
			}
			
			out.println();
		}
		
		out.close();
	}
}