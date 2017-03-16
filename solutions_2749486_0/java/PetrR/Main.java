
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
		BufferedReader br = Files.newBufferedReader(Paths.get("B-small-attempt0.in", args), Charset.defaultCharset());
		System.setOut(new PrintStream(Files.newOutputStream(Paths.get("output.out"))));

		final int CASES = Integer.parseInt(br.readLine());
		String line;

		for (int cs = 0; cs < CASES; cs++)
		{
			line = br.readLine();
			final int space = line.indexOf(' ');
			final int X = Integer.parseInt(line.substring(0, space));
			final int Y = Integer.parseInt(line.substring(space + 1));

			printStatus(cs + 1, X, Y);
			//br.readLine();
		}
	}

	private static void printStatus(int dataCase, int x, int y)
	{
		StringBuilder sb = new StringBuilder();

		if (x < 0)
		{
			x = -x;
			for (int i = 0; i < x; i++)
				sb.append("EW");
		}
		else
			for (int i = 0; i < x; i++)
				sb.append("WE");
		if (y < 0)
		{
			y = -y;
			for (int i = 0; i < y; i++)
				sb.append("NS");
		}
		else
			for (int i = 0; i < y; i++)
				sb.append("SN");
			
		printMessage(dataCase, sb.toString());
	}

	public static void printMessage(int dataCase, String message)
	{
		System.out.println("Case #" + dataCase + ": " + message);
	}
}