
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = Files.newBufferedReader(Paths.get("A-large.in", args), Charset.defaultCharset());
//		System.setOut(new PrintStream(Files.newOutputStream(Paths.get("output.out"))));

		final int CASES = Integer.parseInt(br.readLine());
		String line;

		for (int cs = 0; cs < CASES; cs++)
		{
			line = br.readLine();
			final int space = line.indexOf(' ');
			final String text = line.substring(0, space);
			final int N = Integer.parseInt(line.substring(space + 1));


			printStatus(cs + 1, text, N);
			//br.readLine();
		}
	}

	private static void printStatus(int dataCase, String text, int N)
	{
		char[] ch = text.toCharArray();
		int ncons = 0;
		BigInteger count = BigInteger.ZERO;
		int last = -1;
		for (int i = 0; i < text.length(); i++)
		{
			if (ch[i] != 'a' && ch[i] != 'e' && ch[i] != 'i' && ch[i] != 'o' && ch[i] != 'u')
			{
				// found cons
				ncons++;
			}
			// found end
			else
			{
				if (ncons >= N)
				{
					final int index = i - ncons - (last + 1);
					final int mmn = ncons - N;
					final int L = ch.length - (last + 1);
					count = count.add(BigInteger.valueOf(mmn * (index + 1)));
					count = count.add(BigInteger.valueOf(mmn * (L - ncons - index + 1)));
					count = count.add(BigInteger.valueOf((index + 1) * (L - ncons - index + 1)));
					count = count.add(BigInteger.valueOf((mmn + 2) * (mmn + 1) / 2));
					count = count.add(BigInteger.valueOf(-2 * mmn));
					count = count.add(BigInteger.valueOf(-1));

					last = i - (N);
				}

				ncons = 0;
			}
		}
		if (ncons >= N)
		{
			final int index = ch.length - ncons - (last + 1);
			final int mmn = ncons - N;
			final int L = ch.length - (last + 1);
			count = count.add(BigInteger.valueOf(mmn * (index + 1)));
			count = count.add(BigInteger.valueOf(mmn * (L - ncons - index + 1)));
			count = count.add(BigInteger.valueOf((index + 1) * (L - ncons - index + 1)));
			count = count.add(BigInteger.valueOf((mmn + 2) * (mmn + 1) / 2));
			count = count.add(BigInteger.valueOf(-2 * mmn));
			count = count.add(BigInteger.valueOf(-1));
		}

		printMessage(dataCase, count.toString());
	}

	public static void printMessage(int dataCase, String message)
	{
		System.out.println("Case #" + dataCase + ": " + message);
	}
}