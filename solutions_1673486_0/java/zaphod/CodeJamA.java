import java.io.*;
import java.util.*;

public class CodeJamA
{

	public static void main(String[] args) throws IOException
	{
		String fileName = "A-small0";
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

			double[] probs = new double[A];
			for (int i = 0; i < A; i++)
			{
				probs[i] = in.nextDouble();
		//		System.out.print(probs[i]+ " ");
			}
//System.out.println();
			// Option 1
			double probAllRight = 1;

			double bestKey = 10 * B;
			for (int backSpace = A - 1; backSpace >= 0; backSpace--)
			{
				probAllRight *= probs[A-backSpace-1];
				double keyOne = 2 * backSpace + B - A + 1 + (1 - probAllRight)
						* (B + 1);
				//System.out.println(backSpace + "K" + probAllRight + "O"
			//			+ keyOne);

				if (keyOne < bestKey)
					bestKey = keyOne;
			}

			// Option 2
			double keyTwo = 0;

			// Option 3
			double keyThree = 2 + B;

			double prob = Math.min(bestKey, keyThree);

			System.out.printf("Case #%d: %.6f%n", caseNo, prob);
			out.printf("Case #%d: %.6f%n", caseNo, prob);

		}

		System.out.println("Done");
		long stopTime = System.currentTimeMillis();
		System.out.println("Time: " + (stopTime - startTime) / 1000.0);

		// Close the files
		in.close();
		out.close();
	}

}
