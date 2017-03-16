//input file must be in.txt in this directory
//output file will be out.txt
import java.io.*;
import java.util.*;
public class A
{
	public static Scanner in;
	public static PrintStream out;
	
	public static void main(String [] args) throws Throwable
	{
		in = new Scanner(new File("in.txt"));
		int cases = in.nextInt();
		in.nextLine();
		out = new PrintStream(new File("out.txt"));
		for (int i = 1; i <= cases; i++)
		{
			out.print("Case #" + i + ": ");
			printResult();
			out.println();
		}
	}
	public static void printResult()
	{
		int a, b;
		a = in.nextInt();
		b = in.nextInt();
		double [] p = new double[a];
		for (int i = 0; i < a; i++)
		{
			p[i] = in.nextDouble();
		}
		
		double expected;
		double prod = 1.0;
		double min = Double.MAX_VALUE;
		for (int i = 0; i < a; i++)
		{
			prod *= p[i];
			expected = 2*(a-i-1) + (b-a+1) + ((1.0-prod)*(b+1));
			if (expected < min)
				min = expected;
		}
		if (b+2 < min)
			min = b+2;
		out.print(min);
		
	}
} 