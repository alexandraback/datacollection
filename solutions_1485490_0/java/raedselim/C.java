
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {

	/**
	 * @throws FileNotFoundException
	 * @param args
	 * @throws
	 */
	public static void main(String[] args) throws FileNotFoundException
	{
		 Scanner scan = new Scanner(new File("C-small-attempt2.in"));
//		Scanner scan = new Scanner(new File("in.txt"));
		PrintWriter p = new PrintWriter(new File("out.txt"));
		
		int t = scan.nextInt();
		for (int k = 1; k <= t; k++)
		{
			int n = scan.nextInt();
			int m = scan.nextInt();
			nT = new long[n];
			nC = new long[n];

			mT = new long[m];
			mC = new long[m];

			for (int i = 0; i < n; i++)
			{
				nC[i] = scan.nextLong();
				nT[i] = scan.nextLong();
			}
			for (int i = 0; i < m; i++)
			{
				mC[i] = scan.nextLong();
				mT[i] = scan.nextLong();
			}

			dp = new long[n][m];
			for (long[] a : dp)
				Arrays.fill(a, -1);
			
			long max = getMax(0, 0);

//			System.out.println("Case #" + k + ": " + max);
			p.println("Case #" + k + ": " + max);
		}

		p.close();
		scan.close();
	}

	static long[] nT;
	static long[] nC;
	static long[] mT;
	static long[] mC;
	static long dp[][];

	private static long getMax(int i, int j)
	{
		if (i == nT.length || j == mT.length)
			return 0;

//		if (dp[i][j] != -1)
//			return dp[i][j];

		if (nT[i] == mT[j])
		{
			if (nC[i] > mC[j])
			{
				long c  = nC[i];
				nC[i] = nC[i]- mC[j] ;
				dp[i][j] = mC[j] + getMax(i , j + 1);
				nC[i] = c;
				return dp[i][j];
			} else if (nC[i] < mC[j])
			{
				long c  = mC[j];
				mC[j] = mC[j]- nC[i] ;
				dp[i][j] = nC[i] + getMax(i + 1, j );
				mC[j] = c;
				return dp[i][j];
			} else
				return dp[i][j] = mC[j] + getMax(i + 1, j + 1);

		} else
			return dp[i][j] = Math.max(getMax(i + 1, j), getMax(i, j + 1));
	}
}
