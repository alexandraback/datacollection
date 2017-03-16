package round1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Consonants
{
	public static final String DATA_SET = "A-small-attempt0";

	public static final String RESOURCE_DIR = "C:/Dev/Test/resources/";
	public static final String BASE_FILE_NAME = RESOURCE_DIR + Consonants.class.getPackage().getName() + "/" + Consonants.class.getSimpleName() + "/" + DATA_SET;
	public static final String INPUT_FILE_NAME = BASE_FILE_NAME + ".in";
	public static final String OUTPUT_FILE_NAME = BASE_FILE_NAME + ".out";

	public void solve(Scanner in, PrintWriter out)
	{
		String name = in.next();
		int n = in.nextInt();
		int len = name.length();
		Pattern p = Pattern.compile("[^aeiou]{" + n + "}");
		Matcher m = p.matcher(name);
		Set<Range> subs = new HashSet<>();
		int start = 0;
		while (m.find(start))
		{
			start = m.start();
			int end = m.end();
			for (int i = 0; i <= start; i++)
			{
				for (int j = end; j <= len; j++)
				{
					subs.add(new Range(i,j));
				}
			}
			start++;
		}
		out.println(subs.size());
	}

	private static class Range
	{
		private final int start;
		private final int end;

		private Range(int start, int end)
		{
			this.start = start;
			this.end = end;
		}

		@Override
		public boolean equals(Object o)
		{
			if (this == o)
			{
				return true;
			}
			if (o == null || getClass() != o.getClass())
			{
				return false;
			}

			Range range = (Range)o;

			if (end != range.end)
			{
				return false;
			}
			if (start != range.start)
			{
				return false;
			}

			return true;
		}

		@Override
		public int hashCode()
		{
			int result = start;
			result = 31 * result + end;
			return result;
		}
	}

	public static void main(String[] args) throws FileNotFoundException
	{
		File inFile = new File(INPUT_FILE_NAME);
		File outFile = new File(OUTPUT_FILE_NAME);
		Consonants instance = new Consonants();
		Scanner in = new Scanner(inFile);
		PrintWriter out = new PrintWriter(outFile);
		long start = System.currentTimeMillis();
		final int numCases = in.nextInt();
		for (int caseNum = 1; caseNum <= numCases; caseNum++)
		{
			System.out.println("Starting Case #" + caseNum);
			out.print("Case #" + caseNum + ": ");
			instance.solve(in, out);
		}
		System.out.println("Total time: " + (System.currentTimeMillis() - start) + "ms");
		out.close();
		in.close();
	}
}
