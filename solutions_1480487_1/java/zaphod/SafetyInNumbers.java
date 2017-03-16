import java.io.*;
import java.util.*;

public class SafetyInNumbers
{

	public static void main(String[] args) throws IOException
	{
		String fileName = "A-large";
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
			int X = 0;
			int[] J = new int[N];
			for (int i = 0; i < N; i++)
			{
				J[i] = in.nextInt();
				X += J[i];
			}
			int[] minVotes = new int[N];
			int totalScore = 2 * X;
			int lowCont = 0;
			int lowScores = 0;
			for (int i = 0; i < N; i++)
			{
				if (J[i]< 1.0 *totalScore/N)
				{
					lowCont++;
					lowScores += J[i];
				}
			}
				
			System.out.printf("Case #%d: ", caseNo);
			out.printf("Case #%d: ", caseNo);
			for (int i = 0; i < N; i++)
			{
				double extraScore =  1.0 * (X + lowScores) / lowCont - J[i];
//				if (totalVotes % N == 0)
//					minVotes[i] = totalVotes / N - J[i];
//				else
//					minVotes[i] = ((int) Math.ceil(1.0 * totalVotes / N)) - J[i];
				if (extraScore < 0 )
					extraScore = 0;
				double percent = 100.0 * extraScore / X;
				System.out.printf("%.6f", percent);
				out.printf("%.6f", percent);
				if (i < N - 1)
				{
					System.out.print(" ");
					out.print(" ");
				}
			}
			System.out.println();
			out.println();

		}

		System.out.println("Done");
		long stopTime = System.currentTimeMillis();
		System.out.println("Time: " + (stopTime - startTime) / 1000.0);

		// Close the files
		in.close();
		out.close();
	}

}
