import java.io.*;
import java.util.*;

public class EqualSums
{
    static int [] sums;
    
    static int findSum(int [] numbers, int next)
    {
    	int sum = 0;
    	int index = 0;
    	while (next > 0)
    	{
    		if (next % 2 == 1)
    			sum += numbers[index];
    		next /=2;
    		index ++;
    	}
    	return sum;
    }
    
    static TreeSet<Integer> findSet(int [] numbers, int next)
    {
    	TreeSet<Integer> set = new TreeSet<Integer> ();
    	int index = 0;
    	while (next > 0)
    	{
    		if (next % 2 == 1)
    			set.add(numbers[index]);
    		next /=2;
    		index ++;
    	}
    	return set;
    }
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "C-small0";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				fileName + ".out")));

		// Keep track of time for efficiency
		long startTime = System.currentTimeMillis();
		// Process each of the test cases
		int noOfCases = in.nextInt();

		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			
			int N = in.nextInt();
			int [] numbers = new int[N];
		//	HashSet<Integer> set = new HashSet<Integer>();
			sums = new int[2000000];
			for (int i = 0; i < N ; i++)
			{
				numbers[i] = in.nextInt();
			}
			System.out.println("Case #" + caseNo+ ":");
			out.println("Case #" + caseNo+ ":");
			boolean possible = false;
			for (int next = 1; next < 1048576 && !possible; next++)
			{
				int sum = findSum(numbers,next);
				if (sums[sum]!= 0)
				{
					Set <Integer> setOne = findSet(numbers,sums[sum]);
					int size = setOne.size();
					int element =0;
					for (int num : setOne)
					{
						System.out.print(num);
						out.print(num);
						element ++;
						if (element < size)
						{
							System.out.print(" ");
							out.print(" ");
							
						}
					}
					System.out.println();
					out.println();
					setOne = findSet(numbers,next);
					size = setOne.size();
				    element =0;
					for (int num : setOne)
					{
						System.out.print(num);
						out.print(num);
						element ++;
						if (element < size)
						{
							System.out.print(" ");
							out.print(" ");
							
						}
					}
					System.out.println();
					out.println();
				    possible = true;
					
				}
				else
					sums[sum] = next;
				
				
			}
					
			
			
			

			if (!possible)
			{
				System.out.println("impossible");
				out.println("impossible");
			}
		}

		System.out.println("Done");
		long stopTime = System.currentTimeMillis();
		System.out.println("Time: " + (stopTime - startTime) / 1000.0);

		// Close the files
		in.close();
		out.close();
	}
}
