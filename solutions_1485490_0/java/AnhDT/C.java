import static java.util.Arrays.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import java.util.*;
import java.math.*;
import java.io.*;

public class C implements Runnable
{
	String file = "C-small-attempt0";
	
	void init() throws IOException
	{
		input = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));
	}
	
	void solve() throws IOException
	{
		n = nextInt(); 
		m = nextInt();
		numBox = new long[n];
		typeBox = new long[n];
		numToy = new long[m];
		typeToy = new long[m];
		
		for(int i = 0; i < n; i++)
		{
			numBox[i] = nextLong();
			typeBox[i] = nextLong();
		}
		
		for(int i = 0; i < m; i++)
		{
			numToy[i] = nextLong();
			typeToy[i] = nextLong();
		}
		
		long res = 0;
		for(int i = 0; i <= m; i++)
			for(int j = 0; j <= m; j++)
			{
				//print(i, j, get(i, j));
				res = max(res, get(i, j));	
			}
			
		gcj(res);
	}
	
	long[] numBox, typeBox, numToy, typeToy;
	int n, m;
	
	long get(int x, int y)
	{
		long res = 0;
		
		long[] numB = numBox.clone();
		long[] typeB = typeBox.clone();
		long[] numT = numToy.clone();
		long[] typeT = typeToy.clone();
		
		
		for(int i = 0; i < x; i++)
		{
			if(typeB[0] == typeT[i])
			{
				long take = min(numB[0], numT[i]);
				numB[0] -= take;
				numT[i] -= take;
				res += take;
			}
		}
		
		if(n == 1) return res;
		
		//if(x == 3 && y == 0) print("HEREA", res);
		//print("A", x, y);
		
		if(y != 0)
		{
			if(x > y) return 0;
			
			for(int i = max(0, x - 1); i < y; i++)
			{
				if(typeB[1] == typeT[i])
				{
					long take = min(numB[1], numT[i]);
					numB[1] -= take;
					numT[i] -= take;
					res += take;
				}
			}
		}
		else y = x;
		
		if(n == 2) return res;
		
		//if(x == 3 && y == 3 && m == 5) print("HEREB", res, numT[2]);
		
		for(int i = max(0, y - 1); i < m; i++)
			if(typeB[2] == typeT[i])
			{
				long take = min(numB[2], numT[i]);
				numB[2] -= take;
				numT[i] -= take;
				res += take;
			}
			
		//print("C");
		
		return res;
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