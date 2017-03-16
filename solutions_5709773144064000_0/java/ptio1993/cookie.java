import java.util.*;
import java.io.*;

class Run
{
	public static void main(String[] args) throws Exception
	{
		String file = "B-small-attempt0.in";
		Scanner in = new Scanner(new File(file));
		//BufferedReader in = new BufferedReader(new FileReader(file));
		PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
		int testcase = in.nextInt();
		for (int test = 1; test <= testcase; ++test)
		{
			double C = in.nextDouble();
			double F = in.nextDouble();
			double X = in.nextDouble();
			double answer = cookie(C,F,X,2);
			out.format("Case #%d: %.7f\n", test, answer);
		}
		out.close();
		in.close();
		
	}

	public static double cookie(double C, double F, double X, double rate)
	{
		double checker = C/rate + X/(rate+F);
		double comparison = X/rate;
		if (comparison <= checker) return comparison;
		return C/rate + cookie(C,F,X,rate+F);
	}
}