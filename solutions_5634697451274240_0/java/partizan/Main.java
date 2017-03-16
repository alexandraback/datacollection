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
		String s = readLn();
		int n = s.length();
		int k = 0;
		char last = '+';
		for (int i= 1; i<=n; i++)
		{
			if (s.charAt(n-i) != last)
			{
				k++;
				last = s.charAt(n-i);
			}
		}
		
		out.println(k);
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
				out.printf("Case #%d: ", i+1);
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

