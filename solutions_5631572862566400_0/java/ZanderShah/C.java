import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class C
{
	static boolean check(ArrayList<Integer> circle, int l)
	{
		for (int i = 0; i < l; i++)
			if (bff[circle.get(i)] != circle.get((i - 1 + l) % l)
					&& bff[circle.get(i)] != circle.get((i + 1) % l))
				return false;
		return true;
	}

	static void permute(ArrayList<Integer> circle, int x, int l)
	{
		if (x == l)
		{
			if (check(circle, l))
				best = Math.max(best, x);
		}
		else
		{
			for (int i = 1; i <= n; i++)
				if (!vis[i])
				{
					vis[i] = true;
					circle.add(i);
					permute(circle, x + 1, l);
					circle.remove(circle.size() - 1);
					vis[i] = false;
				}
		}
	}

	static int[] bff;
	static boolean[] vis;
	static int n, best = 2;

	public static void main(String[] args) throws Exception
	{
		out = new PrintWriter(new FileWriter("out.txt"));
		int t = readInt();
		for (int r = 1; r <= t; r++)
		{
			best = 2;
			n = readInt();
			bff = new int[n + 1];
			for (int i = 1; i <= n; i++)
				bff[i] = readInt();

			for (int i = n; best < i; i--)
			{
				vis = new boolean[n + 1];
				permute(new ArrayList<Integer>(), 0, i);
			}

			out.printf("Case #%d: %d\n", r, best);
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
