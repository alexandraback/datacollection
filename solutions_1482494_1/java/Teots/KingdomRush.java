package round1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

import utils.Pair;

public class KingdomRush
{
	/**
	 * @param args
	 */
	public static void main(String[] args)
	{
		try
		{
			BufferedReader br = new BufferedReader(new FileReader(new File(args[0])));
			BufferedWriter bw = new BufferedWriter(new FileWriter(new File(args[0].replace(".in",
					".out"))));

			String line = br.readLine();
			int testCases = Integer.parseInt(line);
			int curTestCase = 1;

			while ((line = br.readLine()) != null)
			{
				System.err.println("Run " + curTestCase);

				int levels = Integer.parseInt(line);
				ArrayList<Pair<Integer, Integer>> starRestrictions = new ArrayList<Pair<Integer, Integer>>();
				for (int i = 0; i < levels; i++)
				{
					String[] token = br.readLine().split(" ");
					starRestrictions.add(new Pair<Integer, Integer>(Integer.parseInt(token[0]), Integer
							.parseInt(token[1])));
				}

				int stars = 0;
				int games = 0;

				while (!starRestrictions.isEmpty())
				{
					Pair<Integer, Integer> pair = findBiggest(stars, starRestrictions);

					if (pair == null)
					{
						bw.write("Case #" + curTestCase + ": Too Bad");
						bw.write("\n");
						break;
					}
					else
					{
						// System.err.println(pair.a + " " + pair.b);

						if (pair.b <= stars)
						{
							if (pair.flag)
							{
								stars++;
							}
							else
							{
								stars += 2;
							}

							starRestrictions.remove(pair);
						}
						else
						{
							stars++;
							pair.flag = true;
						}

						games++;
					}
				}

				if (starRestrictions.isEmpty())
				{
					bw.write("Case #" + curTestCase + ": " + games);
					bw.write("\n");
				}

				curTestCase++;
			}

			bw.close();
		}
		catch (IndexOutOfBoundsException e)
		{
			e.printStackTrace();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
	}

	private static Pair<Integer, Integer> findBiggest(int stars,
			ArrayList<Pair<Integer, Integer>> list)
	{
		Pair<Integer, Integer> biggest = new Pair<Integer, Integer>(Integer.MIN_VALUE,
				Integer.MIN_VALUE);
		for (Pair<Integer, Integer> curPair : list)
		{
			if (curPair.b.intValue() <= stars && curPair.b.intValue() > biggest.b.intValue())
			{
				biggest = curPair;
			}
		}

		if (biggest.a == Integer.MIN_VALUE)
		{
			for (Pair<Integer, Integer> curPair : list)
			{
				if (!curPair.flag && curPair.a.intValue() <= stars
						&& curPair.b.intValue() > biggest.b.intValue())
				{
					biggest = curPair;
				}
			}
		}

		if (biggest.a == Integer.MIN_VALUE)
		{
			return null;
		}

		return biggest;
	}
}
