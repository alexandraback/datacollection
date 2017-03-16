
import java.io.*;
import java.util.*;

public class FairAndSquare
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("FairAndSquare-large-1.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("FairAndSquare-large-1.out", false));

		String line = in.readLine();
		int cases = Integer.parseInt(line); // # of test cases

		List<Long> fasqNums = generate();

		for (int i = 1; i <= cases; i++)
		{
			line = in.readLine();
			String[] parts = line.split(" ");
			long a = Long.parseLong(parts[0]);
			long b = Long.parseLong(parts[1]);

			out.write("Case #" + i + ": " + count(fasqNums, a, b));
			out.newLine();
		}

		in.close();
		out.close();
	}

	private static List<Long> generate()
	{
		List<Long> list = new ArrayList<Long>();
		for (int i = 1; i < 10000000; i++)
		{
			if (isPalindrome(i))
			{
				long sq = (long)i * i;
				if (isPalindrome(sq))
					list.add(sq);
			}
		}
		return list;
	}

	private static boolean isPalindrome(long n)
	{
		String s = Long.toString(n);
		for (int i = 0, j = s.length() - 1; i < j; i++, j--)
			if (s.charAt(i) != s.charAt(j)) return false;
		return true;
	}

	private static int count(List<Long> fasqNums, long a, long b)
	{
		int c = 0;
		for (long f : fasqNums)
		{
			if (f >= a && f <= b) c++;
		}
		return c;
	}

	private static void prt(String s)
	{
		System.out.println(s);
	}
}
