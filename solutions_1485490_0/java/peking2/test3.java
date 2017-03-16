import java.io.*;
import java.util.*;

public class test3
{

	public static void main(String[] args) throws Exception
	{
		new test3().run();
	}

	PrintWriter out = null;

	int N;
	int M;
	long[][] dp = null;

	Pair[] boxes = null;
	Pair[] toys = null;

	long play(int x, int y)
	{
		if (x == N || y == M)
			return 0;

		// if (dp[x][y] != -1)
		// return dp[x][y];

		long total = 0;

		if (boxes[x].type == toys[y].type)
		{
			long min = Math.min(boxes[x].count, toys[y].count);
			total = min;

			if (boxes[x].count > toys[y].count)
			{
				boxes[x].count -= min;
				total += play(x, y + 1);
				boxes[x].count += min;
			}
			else if (toys[y].count > boxes[x].count)
			{
				toys[y].count -= min;
				total += play(x + 1, y);
				toys[y].count += min;
			}
			else
			{
				total += play(x + 1, y + 1);
			}
		}
		else
			total = Math.max(play(x + 1, y), play(x, y + 1));

		dp[x][y] = total;
		return total;
	}

	void run() throws Exception
	{
		Scanner in = new Scanner(System.in);
		out = new PrintWriter(new FileWriter("gcj.txt"));

		int T = in.nextInt();

		for (int t = 0; t < T; t++)
		{
			N = in.nextInt();
			M = in.nextInt();

			dp = new long[N][M];
			for (int i = 0; i < N; i++)
				Arrays.fill(dp[i], -1);

			boxes = new Pair[N];
			toys = new Pair[M];

			for (int i = 0; i < N; i++)
			{
				boxes[i] = new Pair(in.nextLong(), in.nextInt());
			}

			for (int i = 0; i < M; i++)
			{
				toys[i] = new Pair(in.nextLong(), in.nextInt());
			}

			long ans = play(0, 0);

			out.printf("Case #%d: %d\n", t + 1, ans);
		}

		out.close();
	}

}

class Pair
{
	long count;
	int type;

	public Pair(long c, int t)
	{
		count = c;
		type = t;
	}
}
