import java.io.*;
import java.util.*;

public class test2
{

	public static void main(String[] args) throws Exception
	{
		new test2().run();
	}

	PrintWriter out = null;

	boolean isOK(int n, int p, boolean s)
	{
		int a = n / 3;
		if (n % 3 != 0)
			a++;

		if (a >= p)
			return true;

		if (s)
		{
			return 3 * p - 4 <= n;
		}

		return false;
	}

	void run() throws Exception
	{
		Scanner in = new Scanner(System.in);
		out = new PrintWriter(new FileWriter("codejam.txt"));

		int T = in.nextInt();
		for (int i = 0; i < T; i++)
		{
			int N = in.nextInt();
			int S = in.nextInt();
			int p = in.nextInt();

			int[] scores = new int[N];
			for (int j = 0; j < N; j++)
				scores[j] = in.nextInt();

			Arrays.sort(scores);
			int total = 0;
			for (int j = N - 1; j >= 0; j--)
			{
				if (isOK(scores[j], p, false))
					total++;
				else
				{
					if (S > 0 && p >= 2)
					{
						if (isOK(scores[j], p, true))
						{
							total++;
							S--;
						}
						else
							break;
					}
					else
						break;
				}
			}

			out.printf("Case #%d: %d\n", i + 1, total);
		}
		out.close();
	}
}
