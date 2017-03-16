package CodeJam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class RevengeOfThePancakes
{

	public static void main(String[] args) throws Exception
	{
		PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
		int t = readInt();
		for (int c = 1; c <= t; c++)
		{
			String s = readLine() + "+";
			int flips = 0;
	
			for (int i = 1; i < s.length(); i++)
				if (s.charAt(i) != s.charAt(i - 1))
					flips++;

			out.printf("Case #%d: %d\n", c, flips);
		}
		out.close();
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static PrintWriter out = new PrintWriter(new BufferedWriter(
			new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	static String next() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException
	{
		return Long.parseLong(next());
	}

	static int readInt() throws IOException
	{
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException
	{
		return Double.parseDouble(next());
	}

	static char readChar() throws IOException
	{
		return next().charAt(0);
	}

	static String readLine() throws IOException
	{
		return br.readLine().trim();
	}
}
