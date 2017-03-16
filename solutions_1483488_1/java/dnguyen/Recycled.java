import java.io.*;
import java.util.*;

class Recycled
{
	static boolean[] check = new boolean[2000001];

	public static void main (String [] args) throws IOException 
	{
		BufferedReader in = new BufferedReader(new FileReader("C-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C-large.out")));
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int numCases = Integer.parseInt(st.nextToken());
		
		for (int caseIndex = 0; caseIndex < numCases; caseIndex++)
		{
			out.print("Case #" + (caseIndex + 1) + ": ");
			
			st = new StringTokenizer(in.readLine());
			int min = Integer.parseInt(st.nextToken());
			int max = Integer.parseInt(st.nextToken());
			
			// Reset check
			for (int i = 0; i <= 2000000; i++)
			{
				check[i] = false;
			}
			
			int result = 0;
			for (int i = min; i <= max; i++)
			{
				result += countRecycledNumbers(i, min, max);
			}
			
			out.print(result);
			
			out.println();
		}
		
		out.close();
	}
	
	public static ArrayList<Integer> generateRecycledNumbers(int x)
	{
	
		// Count number of digits
		int y = x;
		int numDigits = 0;
		while (y > 0)
		{
			numDigits ++;
			y /= 10;
		}
		
		// Get the list of digits
		int[] listDigits = new int[numDigits];
		int index = numDigits-1;
		while (x > 0)
		{
			listDigits[index] = x%10;
			x /= 10;
			index --;
		}
		
		// Generate all possible recycled number from x
		ArrayList<Integer> result = new ArrayList<Integer>();
		
		for (int i = 0; i < numDigits; i++)
		{
			if (listDigits[i] == 0)
				continue;
			
			int num = 0;
			
			for (int j = 0; j < numDigits; j++)
			{
				num = num*10 + listDigits[(i+j)%numDigits];
			}
			
			
			if (num <= 2000000)
				result.add(num);
		}
		
		return result;
	}
	
	public static int countRecycledNumbers(int x, int min, int max)
	{
		if (check[x])
		{
			return 0;
		}
		else
		{
			ArrayList<Integer> recycledNumbers = generateRecycledNumbers(x);
			Collections.sort(recycledNumbers);
			
			int numDistinctNumbers = 0;
			
			for (int i = 0; i < recycledNumbers.size(); i++)
			{
				check[recycledNumbers.get(i)] = true;
				
				if (i > 0 && recycledNumbers.get(i) > recycledNumbers.get(i-1) && recycledNumbers.get(i) >= min && recycledNumbers.get(i) <= max)
				{
					numDistinctNumbers++;
				}
				else if (i == 0 && recycledNumbers.get(i) >= min && recycledNumbers.get(i) <= max)
				{
					numDistinctNumbers++;
				}
			}
			
			return (numDistinctNumbers*(numDistinctNumbers-1)/2);
		}
	}
}