import static java.util.Arrays.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import java.util.*;
import java.math.*;
import java.io.*;

public class A implements Runnable
{
	String file = "A-small-attempt1";

	void init() throws IOException
	{
		input = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));
	}

	void solve() throws IOException
	{
		long S = nextLong();
		int N = nextInt();
		long[] s = new long[N];
		for(int i = 0; i < N; i++) s[i] = nextLong();
		sort(s);
		int res = Integer.MAX_VALUE;
		for(int numRemoves = 0; numRemoves <= N; numRemoves++)
		{
			long cur = S;
			boolean ok = true;
			int add = 0;
			for(int j = 0; j < N - numRemoves; j++)
			{
				if(cur <= s[j])
				{
					if(cur == 1)
					{
						ok = false;
						break;
					}
					else
					{
						while(cur <= s[j])
						{
							cur += (cur - 1);
							add++;
						}
						cur += s[j];
					}
				}
				else
				{
					cur += s[j];
				}
			}
			if(ok)
			{
				res = min(res, numRemoves + add);
			}
		}
		gcj(res);
	}

	String next() throws IOException
	{
		if(st == null || !st.hasMoreTokens()) st = new StringTokenizer(input.readLine());
		return st.nextToken();
	}

	int nextInt() throws IOException
	{
		return Integer.parseInt(next());
	}

	long nextLong() throws IOException
	{
		return Long.parseLong(next());
	}

	double nextDouble() throws IOException
	{
		return Double.parseDouble(next());
	}

	void print(Object... o)
	{
		System.out.println(deepToString(o));
	}

	void gcj(Object o)
	{
		String s = String.valueOf(o);
		out.println("Case #" + test + ": " + s);
		System.out.println("Case #" + test + ": " + s);
	}

	BufferedReader input;
	PrintWriter out;
	StringTokenizer st;
	int test;

	public static void main(String[] args) throws IOException
	{
		new Thread(null, new A(), "", 1 << 20).start();
	}

	public void run()
	{
		try
		{
			init();
			int TEST = nextInt();
			for(test = 1; test <= TEST; test++)
			{
				System.out.println("Running on testcase #" + test);
				solve();
			}
			out.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
			System.exit(1);
		}
	}
}