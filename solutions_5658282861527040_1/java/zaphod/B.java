import java.io.*;
import java.util.Scanner;

public class B
{
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "B-large";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));

		int noOfCases = in.nextInt();
		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			long A = in.nextLong();
			long B = in.nextLong();
			long K = in.nextLong();

			long noOfWins;

		if (K <= (A + B) / 2)
			{
				noOfWins = Math.min(K,A) * B + Math.min(K, B) * A - Math.min(K, B)*Math.min(K,A);
				System.out.println(noOfWins);
				for (long first = K; first < A; first++)
				{
					// noOfWins += (first-K)*(B-K)
					for (long second = K; second < B; second++)
					{
						long number = first & second;
						if (number < K)
						{
							// System.out.println(first + " "+ second + " " +
							// number);
							noOfWins++;
						}
					}
				}
			}

			else
			{
				noOfWins = A * B;
				System.out.println(noOfWins);
				for (long first = K; first < A; first++)
				{
					// noOfWins += (first-K)*(B-K)
					for (long second = K; second < B; second++)
					{
						long number = first & second;
						if (number >= K)
						{
							noOfWins--;
						}
					}
				}
			}

			System.out.printf("Case #%d: %d%n", caseNo, noOfWins);
			out.printf("Case #%d: %d%n", caseNo, noOfWins);
		}
		in.close();
		out.close();

	}

}
