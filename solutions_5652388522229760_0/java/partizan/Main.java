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
		int n = readInt(), a = 0, x, c;
		if (n==0)
		{
			out.println("INSOMNIA");
			return;
		}
		
		int k = 0;
		boolean[] d= new boolean[10];
		Arrays.fill(d, false);
		
		while (k<10)
		{
			a += n;
			x = a;
			
			while (x>0)
			{
				c = x % 10;
				x /= 10;
				
				if (! d[c])
				{
					d[c] = true;
					k ++;
				}
			}
		}
		
		out.println(a);
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

