package first;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = Files.newBufferedReader(Paths.get("A-small-attempt3.in", args), Charset.defaultCharset());
		System.setOut(new PrintStream(Files.newOutputStream(Paths.get("output.out"))));

		final int CASES = Integer.parseInt(br.readLine());
		String line;

		for (int cs = 0; cs < CASES; cs++)
		{
			line = br.readLine();
			final int space = line.indexOf(' ');
			final int A = Integer.parseInt(line.substring(0, space));
			final int N = Integer.parseInt(line.substring(space + 1));

			final int[] motes = new int[N];
			line = br.readLine();
			for (int i = 0; i < N; i++)
			{
				int sp = line.indexOf(' ');
				String mote;
				if (sp > 0)
				{
					mote = line.substring(0, sp);
					line = line.substring(sp + 1);
				}
				else
					mote = line;

				motes[i] = Integer.parseInt(mote);
			}

			printStatus(cs + 1, A, motes);
			//br.readLine();
		}
	}

	private static void printStatus(int dataCase, int A, int[] motes)
	{
		Arrays.sort(motes);
//		System.out.println(Arrays.toString(motes));
//		System.out.println("A : "+A);
		int optimum = get(A, motes, 0, Integer.MAX_VALUE);
		String msg = Integer.toString(optimum);
		printMessage(dataCase, msg);
	}

	public static void printMessage(int dataCase, String message)
	{
		System.out.println("Case #" + dataCase + ": " + message);
	}

	private static int get(int A, int[] motes, int i, int max)
	{
		if (max < 0)
			return -1;

		int x;
		if (i >= motes.length)
			return 0;
		if (A > motes[i])
			return get(A + motes[i], motes, i + 1, max);
		// přidej jeden
		if (2 * A - 1 > motes[i])
			return (x = get(2 * A - 1 + motes[i], motes, i + 1, max - 1)) == -1 ? -1 : x + 1;
		// tak buď přidej nebo odeber zbylé

		int num = 0;
		int remains = motes.length - i;
		while (A <= motes[i])
		{
			num++;
			A = 2 * A - 1; // addind one note

			if (num == remains)
			{
				if (remains > max)
					return -1;
				return remains;
			}
		}

		// try what happen if we add them
		int retval = get(A + motes[i], motes, i + 1, remains - num);
		if (retval == -1)
			return remains;
		if (retval + num > max)
			return remains;
		return retval + num;
	}
}