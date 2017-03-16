import static java.util.Arrays.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import java.util.*;
import java.math.*;
import java.io.*;

public class A implements Runnable
{
	String file = "A-small-attempt0";
	
	void init() throws IOException
	{
		input = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));
	}
	
	ArrayList<Integer>[] adj;
	void solve() throws IOException
	{
		int n = nextInt();
		adj = new ArrayList[n + 1];
		for(int i = 1; i <= n; i++) adj[i] = new ArrayList<Integer>();
		for(int i = 1; i <= n; i++)
		{
			int m = nextInt();
			for(int j = 0; j < m; j++)
			{
				int v = nextInt();
				adj[i].add(v);
			}
		}
		can = new boolean[n + 1][n + 1];
		for(int i = 1; i <= n; i++)
		{
			DFS(i, i);
		}
		
		boolean ok = false;
		outer: for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				if(i == j) continue;
				
				for(int k1 = 0; k1 < adj[i].size(); k1++)
					for(int k2 = k1 + 1; k2 < adj[i].size(); k2++)
					{
						int u = adj[i].get(k1);
						int v = adj[i].get(k2);
						
						if(can[u][j] && can[v][j])
						{
							//print(i, u, v, j);
							ok = true;
							break outer;
						}
					}
			}
		if(ok) gcj("Yes");
		else gcj("No");
	}
	boolean[][] can;
	
	void DFS(int s, int u)
	{
		can[s][u] = true;
		for(int v : adj[u])
		{
			if(!can[s][v]) DFS(s, v);
		}
	}
	String next() throws IOException
	{
		while(tokenizer == null || !tokenizer.hasMoreTokens()) tokenizer = new StringTokenizer(input.readLine());
		return tokenizer.nextToken();
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
	
	void gcjArray(Object[] o)
	{
		out.print("Case #" + test + ": ");
		System.out.print("Case #" + test + ": ");
		for(int i = 0; i < o.length; i++)
		{
			if(i != o.length - 1) 
			{
				out.print(String.valueOf(o[i]) + " ");
				System.out.print(String.valueOf(o[i] + " "));
			}
			else
			{
				out.println(String.valueOf(o[i]));
				System.out.println(String.valueOf(o[i]));
			}
		}
	}
	
	BufferedReader input;
	PrintWriter out;
	StringTokenizer tokenizer;
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