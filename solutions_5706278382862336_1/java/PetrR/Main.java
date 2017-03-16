
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashSet;

public class Main
{
	private static final double LOG2 = 0.69314718055994530941;

	public static void main(String[] args) throws IOException
	{
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = Files.newBufferedReader(Paths.get("input.in", args), Charset.defaultCharset());
		System.setOut(new PrintStream(Files.newOutputStream(Paths.get("output.out"))));

		final int CASES = Integer.parseInt(br.readLine());
		String line;

		for (int cs = 0; cs < CASES; cs++)
		{
			line = br.readLine();
			final int space = line.indexOf('/');
			long P = Long.parseLong(line.substring(0, space));
			long Q = Long.parseLong(line.substring(space + 1));

			final long GCD = GCD(P, Q);

			P /= GCD;
			Q /= GCD;
			
//			System.err.println(msb(Q));

			if (P > Q || !isPowerOfTwo(Q))
				printMessage(cs + 1, "impossible");
			else
			{
				final int val = (int) (Math.log(msb(Q))/LOG2) - (int) (Math.log(msb(P))/LOG2);

				printMessage(cs + 1, Integer.toString(val));
			}
			//final int space = line.indexOf(' ');
			//final int A = Integer.parseInt(line.substring(0, space));
			//final int B = Integer.parseInt(line.substring(space + 1));
			//printStatus(cs + 1);
			//br.readLine();
		}
	}

	public static long msb(long x)
	{
		x |= (x >> 1);
		x |= (x >> 2);
		x |= (x >> 4);
		x |= (x >> 8);
		x |= (x >> 16);
		x |= (x >> 32);
		return (x & ~(x >> 1));
	}

	public static long GCD(long a, long b)
	{
		if (b == 0)
			return a;
		return GCD(b, a % b);
	}

	private static boolean isPowerOfTwo(long number)
	{
		return ((number & -number) == number);
	}

	private static void printStatus(int dataCase)
	{
		String msg = null;
		printMessage(dataCase, msg);
	}

	public static void printMessage(int dataCase, String message)
	{
		System.out.println("Case #" + dataCase + ": " + message);
	}

	public static int parseIntArray(char[] line, int[] target)
	{
		int j = 0;
		int accumulator = -1;
		for (char ch : line)
			if (ch == ' ')
			{
				if (accumulator != -1)
				{
					target[j] = accumulator;
					accumulator = -1;
					j++;
				} // we found a new digit
			}
			else
				accumulator = accumulator == -1
					? (ch - '0')
					: accumulator * 10 + (ch - '0');
		if (accumulator != -1)
			target[j++] = accumulator;
		return j;
	}

}
