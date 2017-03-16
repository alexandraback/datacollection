import java.io.*;
import java.lang.Math;
import java.util.*;

public class Main
{	
	public BufferedReader in;
	public PrintStream out;
	
	public boolean log_enabled = true;
	
	public void test()
	{
		long k = readLong();
		int	c = readInt(), s = readInt();
		int m = (k % c == 0) ? (int)k / c : (int)k/c + 1;
		if (m>s)
		{
			out.println(" IMPOSSIBLE");
			return;
		}
		
		long x, d=0;
		for (int i=0; i<m; i++)
		{
			x = 0;
			for (int j=0; (j<c)&&(d<k); j++)
			{
				x = k * x + (d++);
			}
			out.printf(" %d", 1+x);
		}
		
		out.println();
	}
    
	public void run()
	{
		try
		{
			in = new BufferedReader(new InputStreamReader(System.in));
			out = System.out;
			
			//in = new BufferedReader(new FileReader("in.txt"));
			//out = new PrintStream(new File("out.txt"));
			
			
		}
		catch (Exception e)
		{
			return;
		}
		
		//while (true)
		{
			int t = readInt(); for (int i=0; i<t; i++)					
			{
				out.printf("Case #%d:", i+1);
				test();
			}
		}
	}
	
	public static void main(String args[])
	{
		new Main().run();
	}
	
	private StringTokenizer tokenizer = null;
	
	public int readInt() 
	{
        return Integer.parseInt(readToken());
    }
   
    public long readLong() 
	{
        return Long.parseLong(readToken());
    }
   
    public double readDouble() 
	{
        return Double.parseDouble(readToken());
    }
   
	public String readLn()
	{	
		try
		{
			String s;
			while ((s = in.readLine()).length()==0);
			return s;
		}
		catch (Exception e)
		{
			return "";
		}
	}
	
    public String readToken() 
	{
		try
		{
			while (tokenizer == null || !tokenizer.hasMoreTokens()) 
			{
				tokenizer = new StringTokenizer(in.readLine());
			}
			return tokenizer.nextToken();
		}
		catch (Exception e)
		{
			return "";
		}
    }
	
	public int[] readIntArray(int n)
	{
		int[] x = new int[n];
		readIntArray(x, n);
		return x;
	}
	
	public void readIntArray(int[] x, int n)
	{
		for (int i=0; i<n; i++)
		{
			x[i] = readInt();
		}
	}
	
	public void logWrite(String format, Object... args)
	{
		if (!log_enabled)
		{
			return;
		}
		
		out.printf(format, args);
	}
}

