import java.io.*;
import java.util.*;
import java.text.*;

class Safety
{
	public static void main (String [] args) throws IOException 
	{
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-large.out")));
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int numCases = Integer.parseInt(st.nextToken());
		
		for (int caseIndex = 0; caseIndex < numCases; caseIndex++)
		{
			out.print("Case #" + (caseIndex+1) + ": ");
			
			st = new StringTokenizer(in.readLine());
			
			int n = Integer.parseInt(st.nextToken());
			
			int[] s = new int[n];
			
			for (int i = 0; i < n; i++)
			{
				s[i] = Integer.parseInt(st.nextToken());
			}
			
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				sum += s[i];
			}
			
			boolean[] check = new boolean[n];
			
			for (int i = 0; i < n; i++)
			{
				check[i] = false;
			}
			
			boolean stop = false;
			int size = n;
			
			int curSum = sum;
			
			while (!stop)
			{
				stop = true;
				
				for (int i = 0; i < n; i++)
				{
					if (!check[i])
					{
					
						if (sum != 0 && s[i] >= (double)(sum+curSum)/size)
						{
							check[i] = true;
							curSum -= s[i];
							size--;
							stop = false;
							break;
						}
					}
				}
			}
			
			//System.out.println(Arrays.toString(s));
			//System.out.println(Arrays.toString(check));
			
			for (int i = 0; i < n; i++)
			{
				if (!check[i])
				{
					double meanScore = (double)(curSum+sum)/size;
					double temp = meanScore - s[i];
					double result = (temp/sum)*100;
					out.printf("%1$.6f", result);

				}
				else
				{
					out.printf("0.000000");
				}
				
				if (i != n-1)
				{
					out.printf(" ");
				}
			}
			
			out.println();
		}
		
		out.close();
		
	}
}