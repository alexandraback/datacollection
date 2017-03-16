
import static java.lang.Math.*;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Date;
import java.util.Scanner;


public class A 
{
	private static Scanner in;
	private static PrintWriter out; 
	
	private static long T;
	private static long R;
	
	static void readTest(int testNum) 
	{
		R = in.nextLong();
		T = in.nextLong();
	}
	
	static void solveTest(int testNum)
	{
		debug(new Date(), " : Solving ", testNum);
		
//		double lastArea  = R * R;
		
		
		double b = (2 * R) - 1;
				
		long n = 0;
		n = (long)((-b - sqrt((b * b) + 8 * (double)T))/4);
		if(n <= 0)
		{
			n = (long)((-b + sqrt((b * b) + 8 * (double)T))/4);
			
		}
		
		out.printf("Case #%d: %s%n", testNum, n);
		out.flush();
	}
	
	static void solve()
	{
		int numTests = in.nextInt();
		debug("Num tests: ", numTests);
		
		for(int i = 1; i <= numTests; i++)
		{
			readTest(i);
			solveTest(i);
		}
	}
	
	public static void main(String[] args) throws FileNotFoundException
	{
		try
		{
			in = new Scanner(new File("C:\\codejam\\round1\\a\\test.in"));
			out = new PrintWriter("C:\\codejam\\round1\\a\\test.out");
			
			solve();
		}
		finally
		{
			if(in != null)
				in.close();
			if(out != null)
			{
				out.flush();
				out.close();
			}
		}
		
		debug(new Date(), " Done Solving.");
		
	}
	
	private static void debug(Object... objects)
	{
		StringBuilder builder = new StringBuilder();
		for(Object o : objects)
		{
			builder.append(String.valueOf(o));
		}
		debug(builder.toString());
	}
	
	private static void debug(String str)
	{
		System.out.println(str);
	}
}
