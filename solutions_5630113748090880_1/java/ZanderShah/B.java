import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class B
{
	public static void main(String[] args) throws Exception
	{
		out = new PrintWriter(new FileWriter("out.txt"));
		int t = readInt();
		for (int r = 1; r <= t; r++)
		{
			int n = readInt();
			int[] heights = new int[2501];
			for (int i = 0; i < 2 * n - 1; i++)
				for (int j = 0; j < n; j++)
					heights[readInt()]++;
			
			ArrayList<Integer> missing = new ArrayList<Integer>();
			for (int i = 1; i <= 2500; i++)
				if (heights[i] % 2 != 0)
					missing.add(i);
			Collections.sort(missing);
			
			String ans = "";
			for (int num : missing)
				ans += num + " ";
			ans = ans.trim();
			out.printf("Case #%d: %s\n", r, ans);
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
