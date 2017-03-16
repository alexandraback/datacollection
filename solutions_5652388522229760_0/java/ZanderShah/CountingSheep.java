package CodeJam;

import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class CountingSheep
{

	public static void main(String[] args) throws Exception
	{
		PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
		int t = readInt();

		for (int c = 1; c <= t; c++)
		{
			int n = readInt();
			int moves, count = 0;
			boolean[] seen = new boolean[10];

			if (n == 0)
				out.printf("Case #%d: INSOMNIA\n", c);
			else
			{
				for (moves = 1; count != 10; moves++)
				{
					int x = n * moves;
					while (x != 0)
					{
						int d = x % 10;
						x /= 10;
						if (!seen[d])
						{
							seen[d] = true;
							count++;
						}
					}
				}

				out.printf("Case #%d: %d\n", c, n * (moves - 1));
			}
		}
		
		out.close();
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StringTokenizer st;

	static String next() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException
	{
		return Long.parseLong(next());
	}

	static int readInt() throws IOException
	{
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException
	{
		return Double.parseDouble(next());
	}

	static char readChar() throws IOException
	{
		return next().charAt(0);
	}

	static String readLine() throws IOException
	{
		return br.readLine().trim();
	}
}
