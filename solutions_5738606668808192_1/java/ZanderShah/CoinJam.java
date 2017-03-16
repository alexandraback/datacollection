package CodeJam;

import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class CoinJam
{
	static BigInteger prime(BigInteger x)
	{
		BigInteger lazyLimit = new BigInteger("100");
		BigInteger six = new BigInteger("6");

		if (x.mod(new BigInteger("2")).equals(BigInteger.ZERO))
			return new BigInteger("2");
		if (x.mod(new BigInteger("3")).equals(BigInteger.ZERO))
			return new BigInteger("3");

		for (BigInteger i = new BigInteger("6"); i.multiply(i).compareTo(lazyLimit) <= 0; i = i
				.add(six))
			if (x.mod(i.subtract(BigInteger.ONE)).equals(BigInteger.ZERO))
				return i.subtract(BigInteger.ONE);
			else if (x.mod(i).equals(BigInteger.ZERO))
				return i;
			else if (x.mod(i.add(BigInteger.ONE)).equals(BigInteger.ZERO))
				return i.add(BigInteger.ONE);

		return x;
	}

	static void generate(BigInteger x, int p)
	{
		if (r != j)
			if (p == n - 2)
				check(new BigInteger(x.toString(2)));
			else
			{
				generate(x.add(new BigInteger((1l << p) + "")), p + 1);
				generate(x, p + 1);
			}
	}

	static void check(BigInteger x)
	{
		String ret = x + " ";
		int c = 0;

		for (int i = 2; i <= 10; i++)
		{
			BigInteger base = new BigInteger(x.toString(), i);
			BigInteger div = prime(base);

			if (!div.equals(base))
				c++;
			ret += div + " ";
		}

		if (c == 9)
		{
			r++;
			out.println(ret.trim());
		}
	}

	static int n, j, r = 0;

	public static void main(String[] args) throws Exception
	{
		out = new PrintWriter(new FileWriter("output.txt"));
		int t = readInt();
		out.println("Case #1:");

		n = readInt();
		j = readInt();

		generate(new BigInteger("" + (1 + (1l << (n - 1)))), 1);
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
