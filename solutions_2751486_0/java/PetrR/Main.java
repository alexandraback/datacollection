
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = Files.newBufferedReader(Paths.get("A-small-attempt0.in", args), Charset.defaultCharset());
		System.setOut(new PrintStream(Files.newOutputStream(Paths.get("output.out"))));

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
		long count = 0;
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
					count += mmn * (index + 1);
					count += mmn * (L - ncons - index + 1);
					count += (index + 1) * (L - ncons - index + 1);
					count += (mmn + 2) * (mmn + 1) / 2;
					count -= 2 * mmn;
					count -= 1;
					
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
			count += mmn * (index + 1);
			count += mmn * (L - ncons - index + 1);
			count += (index + 1) * (L - ncons - index + 1);
			count += (mmn + 2) * (mmn + 1) / 2;
			count -= 2 * mmn;
			count -= 1;
		}

		printMessage(dataCase, Long.toString(count));
	}

	public static void printMessage(int dataCase, String message)
	{
		System.out.println("Case #" + dataCase + ": " + message);
	}
}