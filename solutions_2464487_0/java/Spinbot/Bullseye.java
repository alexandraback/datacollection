package round1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Bullseye
{
	public static void main(String[] args) throws FileNotFoundException
	{
		File in = new File(args[0] + ".in");
		File out = new File(args[0] + ".out");
		long start = System.currentTimeMillis();
		new Bullseye(in, out).run();
		System.out.println("Total time: " + (System.currentTimeMillis() - start) + "ms");
	}

	private final File in;
	private final File out;

	public Bullseye(File in, File out)
	{
		this.in = in;
		this.out = out;
	}

	public void run() throws FileNotFoundException
	{
		try (Scanner scanner = new Scanner(in))
		{
			try (PrintWriter writer = new PrintWriter(out))
			{
				final int numCases = scanner.nextInt();
				for (int caseNum = 1; caseNum <= numCases; caseNum++)
				{
					System.out.println("Starting Case #" + caseNum);
					int bullseyeRadius = scanner.nextInt();
					int millisOfPaint = scanner.nextInt();
					int count = 0;
					for (int i = bullseyeRadius, j = i + 1; millisOfPaint > 0; i += 2, j += 2)
					{
						millisOfPaint -= (j*j - i*i);
						if (millisOfPaint >= 0)
						{
							count++;
						}
					}
					writer.println("Case #" + caseNum + ": " + count);
				}
			}
		}
	}

}
