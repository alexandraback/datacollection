import java.io.*;
import java.util.*;

public class CodeJamC
{

	private static int noOfDigits(int number)
	{
		int noOfDigits = 0;
		while (number > 0)
		{
			number /= 10;
			noOfDigits++;
		}
		return noOfDigits;
	}

	private static int pow(int exponent)
	{
		int power = 1;
		for (int mulitply = 1; mulitply <= exponent; mulitply++)
			power *= 10;
		return power;
	}

	private static int countPairs(int A, int B)
	{

		int noOfDigits = noOfDigits(A);
		int noOfPairs = 0;
		int places = pow(noOfDigits);
		for (int next = A; next < B; next++)
		{
			HashSet<Integer> used = new HashSet<Integer>();
			// System.out.println("Next "+ next);
			for (int back = 10; back < places; back *= 10)
			{
				int recycled = shift(next, back, places / back);
				// System.out.println("Back: " + back + "RC " + recycled);
				if (recycled > next && recycled <= B)
				{
					// System.out.println(next +", " + recycled);
					if (!used.contains(recycled))
					{
						used.add(recycled);
						noOfPairs++;
					}
				}
			}
		}

		return noOfPairs;
	}

	private static int shift(int number, int back, int front)
	{
		return (number % back) * front + number / back;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "C-large";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				fileName + ".out")));

		// Keep track of time for efficiency
		long startTime = System.currentTimeMillis();
		// Process each of the test cases
		int noOfCases = in.nextInt();

		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			int A = in.nextInt();
			int B = in.nextInt();

			int noOfPairs = countPairs(A, B);

			System.out.println("Case #" + caseNo + ": " + noOfPairs);
			out.println("Case #" + caseNo + ": " + noOfPairs);
		}

		System.out.println("Done");
		long stopTime = System.currentTimeMillis();
		System.out.println("Time: " + (stopTime - startTime) / 1000.0);

		// Close the files
		in.close();
		out.close();
	}
}
