import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class PartElf
{
	long p, q, divisor;

	public static void main(String[] args) throws Exception
	{
		PartElf solver = new PartElf();

		int numberOfTests = Console.nextInt();
		for (int i = 1; i <= numberOfTests; i++)
		{
			solver.readData();
			solver.solve(i);
		}
	}

	private void readData() throws Exception
	{
		p = Console.nextLong();
		q = Console.nextLong();

		long divisor = gcd(p, q);
		p /= divisor;
		q /= divisor;
	}

	long gcd(long a, long b)
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	long myPow(int power)
	{
		long ans = 1L;
		for (int i = 1; i <= power; i++)
		{
			ans *= 2L;
		}

		return ans;
	}

	private void solve(int testIndex) throws Exception
	{
		if (p > q)
		{
			Console.println(String.format("Case #%d: impossible", testIndex));
			return;
		}

		int powq = 0;
		long qq = q;
		while ((qq % 2) == 0)
		{
			qq /= 2L;
			powq++;
		}

		if (qq > 1)
		{
			Console.println(String.format("Case #%d: impossible", testIndex));
			return;
		}

		for (int ans = 1; ans <= 40; ans++)
		{
			if ((myPow(ans) * p) >= q)
			{
				Console.println(String.format("Case #%d: %d", testIndex, ans));
				return;
			}
		}

		Console.println(String.format("Case #%d: impossible", testIndex));
		return;

	}

	public PartElf() throws Exception
	{
		FileInputStream in = new FileInputStream("A-large.in");
		OutputStream out = new FileOutputStream("A-large.out");
		Console c = new Console(in, out);
	}

	static class Console
	{
		private static final String SEPARATOR = "// \n";

		static BufferedReader in;

		static StringTokenizer tokenizer;

		static PrintWriter out;

		public Console() throws Exception
		{
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		}

		public Console(InputStream inS, OutputStream outS) throws Exception
		{
			in = new BufferedReader(new InputStreamReader(inS));
			out = new PrintWriter(outS);
		}

		public static void println(String string)
		{
			out.write(string + "\r\n");
			out.flush();
		}

		public static String next() throws Exception
		{
			while ((tokenizer == null) || !tokenizer.hasMoreTokens())
			{
				tokenizer = new StringTokenizer(in.readLine(), SEPARATOR);
			}

			return tokenizer.nextToken();
		}

		public static Integer nextInt() throws Exception
		{
			return Integer.parseInt(next());
		}

		public static Long nextLong() throws Exception
		{
			return Long.parseLong(next());
		}
	}

}
