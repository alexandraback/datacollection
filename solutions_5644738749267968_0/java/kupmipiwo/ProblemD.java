import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class ProblemD
{

	public static final String fileInput = "Samples/ProblemD/2.in";

	public static void main(String args[]) throws IOException
	{
		Scanner sc;

		final String fileOutput = fileInput.replace("in", "out.gen");

		FileOutputStream fos = new FileOutputStream(fileOutput);
		sc = new Scanner(new FileInputStream(fileInput));
		// sc = new Scanner(System.in);

		int T = sc.nextInt();

		for (int i = 1; i <= T; ++i)
		{
			int N = sc.nextInt();
			double[] Naomi = new double[N];
			double[] Ken = new double[N];
			TreeSet<Double> NaomiTreeSetY = new TreeSet<>();
			TreeSet<Double> NaomiTreeSetZ = new TreeSet<>();

			for (int n = 0; n < N; ++n)
			{
				double weight = sc.nextDouble();
				Naomi[n] = weight;
				NaomiTreeSetY.add(weight);
				NaomiTreeSetZ.add(weight);
			}

			for (int n = 0; n < N; ++n)
			{
				double weight = sc.nextDouble();
				Ken[n] = weight;
			}

			Arrays.sort(Naomi);
			Arrays.sort(Ken);

			int y = countDeceiptful(Naomi, Ken, NaomiTreeSetY);
			int z = countWar(Naomi, Ken, NaomiTreeSetZ);
			//
			StringBuilder sb = new StringBuilder();
			sb.append(String.format("Case #%d: %d %d\n", i, y, z));
			String output = sb.toString();
			System.out.print(output);
			fos.write(output.getBytes());
		}
		fos.close();
		sc.close();
	}

	private static int countDeceiptful(double[] naomi, double[] ken,
			TreeSet<Double> naomiTreeSet)
	{
		int index = 0;
		while (index < ken.length && naomiTreeSet.higher(ken[index]) != null)
		{
			naomiTreeSet.remove(naomiTreeSet.higher(ken[index]));
			index++;
		}
		return index;
	}

	private static int countWar(double[] naomi, double[] ken,
			TreeSet<Double> naomiTreeSet)
	{
		int index = ken.length - 1;
		while (index > 0 && naomiTreeSet.lower(ken[index]) != null)
		{
			naomiTreeSet.remove(naomiTreeSet.lower(ken[index]));
			index--;
		}
		return index;
	}
}
