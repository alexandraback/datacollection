import java.io.*;
import java.util.*;
import java.text.*;

class Password
{
	public static void main (String [] args) throws IOException 
	{
		BufferedReader in = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt0.out")));
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int numCases = Integer.parseInt(st.nextToken());
		
		for (int caseIndex = 0; caseIndex < numCases; caseIndex++)
		{
			out.print("Case #" + (caseIndex+1) + ": ");
			
			st = new StringTokenizer(in.readLine());
			
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			
			double[] p = new double[A];
			
			st = new StringTokenizer(in.readLine());
			
			for (int i = 0; i < A; i++)
			{
				p[i] = Double.parseDouble(st.nextToken());
			}
			
			double[] pro = new double[A+1];
			
			pro[0] = 1;
			
			for (int i = 1; i <= A; i++)
			{
				pro[i] = pro[i-1]*p[i-1];
			}
			
			double min = Double.MAX_VALUE;
			double curValue = -1;
			
			for(int i = 0; i < A; i++) 
			{
				curValue = (B - A + 1 + 2*i) * pro[A-i] + (B*2 - A + 2 + 2*i) * (1 - pro[A-i]);
				
				if(curValue < min)
				{
					min = curValue;
				}
			}
			DecimalFormat df = new DecimalFormat("#.######");
			if (min < B+2)
			{
				out.printf("%1$.6f", min);
			}
			else
			{
				out.printf("%1$.6f", (double)B+2);
			}
			
			out.println();
		}
		
		out.close();
		
	}
}