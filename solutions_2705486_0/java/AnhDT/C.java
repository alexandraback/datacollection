import static java.util.Arrays.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import java.util.*;
import java.math.*;
import java.io.*;

public class C implements Runnable
{
	String file = "C-small-attempt1";

	void init() throws IOException
	{
		input = new BufferedReader(new FileReader(file + ".in"));
		input2 = new BufferedReader(new FileReader("dict.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));

		List<String> dicts = new ArrayList<String>();
		String str;
		int maxLen = 0;
		while((str = input2.readLine()) != null)
		{
			dicts.add(str);
			maxLen = max(maxLen, str.length());
		}
		dict = new String[dicts.size()];
		for(int i = 0; i < dicts.size(); i++) dict[i] = dicts.get(i);
		sort(dict);
	}
	String[] dict;

	void solve() throws IOException
	{
		str = next();
		for(int i = 0; i < ADD; i++) str = "_" + str;
		cs = str.toCharArray();
		len = str.length();
		dp = new int[len + ADD][len + ADD];
		for(int[] t : dp) fill(t, -1);
		gcj(get(ADD, 0));
	}
	String str;
	char[] cs;
	int len;
	int[][] dp;
	int INF = 1 << 20;
	int ADD = 20;

	int get(int i, int k)
	{
		if(i == len) return 0;
		if(dp[i][k] != -1) return dp[i][k];

		int res = INF;
		for(int j = i; j < len && j < i + 10; j++)
		{
			res = min(res, find(str.substring(i, j + 1), k, i, j + 1));
		}

		if(k < 0) return res;
		return dp[i][k] = res;
	}

	int find(String s, int last, int start, int next)
	{
		if(binarySearch(dict, s) >= 0) return get(next, last);
		char[] as = s.toCharArray();
		int res = INF;
		for(int i = 0; i < as.length; i++)
			for(char c = 'a'; c <= 'z'; c++)
			{
				if(c != as[i])
				{
					char t = as[i];
					as[i] = c;
					String tmp = new String(as);
					if(start + i - last >= 5 && binarySearch(dict, tmp) >= 0)
					{
						res = min(res, 1 + get(next, start + i));
					}
					as[i] = t;
				}
			}
		for(int j = 5; j < as.length; j++)
			for(int i = j - 5; i >= 0; i--)
				for(char c1 = 'a'; c1 <= 'z'; c1++)
					for(char c2 = 'a'; c2 <= 'z'; c2++)
					{
						if(c1 != as[i] && c2 != as[j])
						{
							char t1 = as[i];
							char t2 = as[j];
							as[i] = c1;
							as[j] = c2;
							String tmp = new String(as);
							if(start + i - last >= 5 && binarySearch(dict, tmp) >= 0)
							{
								res = min(res, 2 + get(next, start + j));
							}
							as[i] = t1;
							as[j] = t2;
						}
					}
		return res;
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
	BufferedReader input2;
	PrintWriter out;
	StringTokenizer st;
	int test;

	public static void main(String[] args) throws IOException
	{
		new Thread(null, new C(), "", 1 << 20).start();
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