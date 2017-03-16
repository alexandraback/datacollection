package CodeJam;

import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

public class CoinJam
{
	static long prime(long x)
	{
		if (x == 1)
			return 1;
		for (long i = 2; i <= Math.sqrt(x); i++)
			if (x % i == 0)
				return i;
		return x;
	}

	static void generate(int x, int p)
	{
		if (r != j)
		{
			if (!done.contains(x))
				check(Integer.toBinaryString(x));
			if (p < n - 1)
			{
				generate(x + (1 << p), p + 1);
				generate(x, p + 1);
			}
		}
	}

	static void check(String x)
	{
		String ret = "";
		ArrayList<Long> divs = new ArrayList<Long>();
		for (int i = 2; i <= 10; i++)
		{
			long base = Long.parseLong(x, i);
			long div = prime(base);
			if (div == base)
				break;
			else
				divs.add(div);
		}

		if (divs.size() == 9)
		{
			r++;
			ret += (x + " ");
			for (Long d : divs)
				ret += (d + " ");
			out.println(ret.trim());
			done.add(Integer.parseInt(x, 2));
		}
	}

	static int n, j, r = 0;
	static HashSet<Integer> done = new HashSet<Integer>();

	public static void main(String[] args) throws Exception
	{
		out = new PrintWriter(new FileWriter("output.txt"));
		int t = readInt();
		out.println("Case #1:");

		n = readInt();
		j = readInt();

		generate((1 << (n - 1)) + 1, 1);
		out.close();
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static PrintWriter out;
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
