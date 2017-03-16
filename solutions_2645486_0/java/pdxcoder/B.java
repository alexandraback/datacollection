import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Date;
import java.util.Scanner;


public class B 
{
	private static Scanner in;
	private static PrintWriter out; 
	
	private static int E;
	private static int R;
	private static int N;
	private static int[] values;
	
	static void readTest(int testNum) 
	{
		E = in.nextInt();
		R = in.nextInt();
		N = in.nextInt();
		values = new int[N];
		
		for(int i = 0; i < N; i++)
		{
			values[i] = in.nextInt();
		}
		
		
		
	}
	
	static int max(int idx, int en)
	{
		if(idx >= values.length)
		{
			return 0;
		}
		int value = 0;
		
		for(int i = 0; i <= en; i++)
		{
			int newEn = Math.min(E, (en - i + R));
			int newValue = values[idx] * i + max((idx + 1), newEn);
			value = Math.max(newValue, value);
		}
		return value;
	}
	
	static void solveTest(int testNum)
	{
		print(new Date(), " : Solving ", testNum);
		int value = max(0, E);
//		out.printf("Case #%d: %s%n", testNum, "result");
		out.printf("Case #%d: %s%n", testNum, value);
	}
	
	static void solve()
	{
		int numTests = in.nextInt();
		print("Num tests: ", numTests);
		
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
			in = new Scanner(new File("C:\\codejam\\round1\\b\\test.in"));
			out = new PrintWriter("C:\\codejam\\round1\\b\\test.out");
			
			solve();
		}
		finally
		{
			if(in != null)
				in.close();
			if(out != null)
				out.close();
		}
		
		print(new Date(), " Done Solving.");
		
	}
	
	private static void print(Object... objects)
	{
		StringBuilder builder = new StringBuilder();
		for(Object o : objects)
		{
			builder.append(String.valueOf(o));
		}
		print(builder.toString());
	}
	
	private static void print(String str)
	{
		System.out.println(str);
	}
}
