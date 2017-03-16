package round1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ManageYourEnergy
{
	public static void main(String[] args) throws FileNotFoundException
	{
		File in = new File(args[0] + ".in");
		File out = new File(args[0] + ".out");
		long start = System.currentTimeMillis();
		new ManageYourEnergy(in, out).run();
		System.out.println("Total time: " + (System.currentTimeMillis() - start) + "ms");
	}

	private final File in;
	private final File out;

	public ManageYourEnergy(File in, File out)
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
					int E = scanner.nextInt();
					int R = scanner.nextInt();
					int N = scanner.nextInt();
					int[] V = new int[N];
					for (int i = 0; i < N; i++)
					{
						V[i] = scanner.nextInt();
					}
					int lookAhead = R >= E ? 0 : (int)Math.ceil((double)E / (double)R);
					long gain = 0;
					if (lookAhead == 0)
					{
						for (int i = 0; i < N; i++)
						{
							gain += (V[i] * (long)E);
						}
					}
					else
					{
						long remaining = E;
						outer:
						for (int i = 0; i < N; i++)
						{
							for (int j = i + 1; j <= i + lookAhead && j < N; j++)
							{
								if (V[j] >= V[i])
								{
									long toSave = E - ((j - i) * (long)R);
									if (toSave < 0)
									{
										toSave = E - R;
									}
									long toSpend = remaining - toSave;
									if (toSpend < 0)
									{
										toSpend = 0;
										toSave = remaining;
									}
									gain += (V[i] * toSpend);
									remaining = toSave + R;
									continue outer;
								}
							}
							gain += (V[i] * remaining);
							remaining = R;
						}
					}
					writer.println("Case #" + caseNum + ": " + gain);
				}
			}
		}
	}
}
