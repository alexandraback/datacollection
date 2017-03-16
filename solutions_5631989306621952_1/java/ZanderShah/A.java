import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class A
{

	public static void main(String[] args) throws Exception
	{
		out = new PrintWriter(new FileWriter("out.txt"));
		int t = readInt();
		for (int r = 1; r <= t; r++)
		{
			String word = readLine();
			String win = word.charAt(0) + "";
			for (int i = 1; i < word.length(); i++)
				if (word.charAt(i) >= win.charAt(0))
					win = word.charAt(i) + win;
				else
					win += word.charAt(i);
			
			out.printf("Case #%d: %s\n", r, win);
		}
		out.close();
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static PrintWriter out;
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
