package game;

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
	public static void main(String[] args) throws IOException
	{
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = Files.newBufferedReader(Paths.get("input.in", args), Charset.defaultCharset());
		System.setOut(new PrintStream(Files.newOutputStream(Paths.get("output.out"))));

		final int CASES = Integer.parseInt(br.readLine());
		String line;

		for (int cs = 0; cs < CASES; cs++)
		{
//			line = br.readLine();

			line = br.readLine();
			final int space = line.indexOf(' ');
			final int lsp = line.lastIndexOf(' ');
			final double A = Double.parseDouble(line.substring(0, space));
			final double B = Double.parseDouble(line.substring(space + 1, lsp));
			final double K = Double.parseDouble(line.substring(lsp + 1));
			
			int count = 0;
			for(int i = 0; i < A; i++)
				for(int j = 0; j < B; j++)
					if((i & j) < K)
						count++;
			
			
			//final int space = line.indexOf(' ');
			//final int A = Integer.parseInt(line.substring(0, space));
			//final int B = Integer.parseInt(line.substring(space + 1));
			printMessage(cs + 1, Integer.toString(count));
			//br.readLine();
		}
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
