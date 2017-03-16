import java.io.*;
import java.util.*;

public class test
{

	public static void main(String[] args) throws Exception
	{
		new test().run();
	}

	PrintWriter out = null;

	void run() throws Exception
	{
		Scanner in = new Scanner(System.in);
		out = new PrintWriter(new FileWriter("gcj.txt"));

		int T = Integer.parseInt(in.nextLine());

		for (int t = 0; t < T; t++)
		{
			int N = in.nextInt();
			int[] arr = new int[N];
			int sum = 0;

			int n = N;

			for (int i = 0; i < N; i++)
			{
				arr[i] = in.nextInt();
				sum += arr[i];
			}

			double[] ans = new double[N];
			Arrays.fill(ans, -1);

			double avg = (double) sum * 2 / N;
			int subsum = 0;

			for (int i = 0; i < N; i++)
			{
				if (arr[i] >= avg)
				{
					ans[i] = 0;
					n--;
				}
				else
					subsum += arr[i];
			}

			for (int i = 0; i < N; i++)
			{
				if (ans[i] != -1)
					continue;
				else
					ans[i] = ((double) (subsum + sum) / n - arr[i]) * 100 / sum;
			}

			out.printf("Case #%d:", t + 1);
			for (int i = 0; i < N; i++)
			{
				out.printf(" %.6f", ans[i]);
			}

			out.println();
		}

		out.close();
	}

}
