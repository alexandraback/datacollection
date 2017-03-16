package gcj2012.round1b;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;

public class ProblemA
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("in.txt"));
		PrintStream out = new PrintStream("out.txt");
//		out = System.out;
		
		int T = Integer.parseInt(in.readLine());
		
		for (int t = 0; t < T; t++)
		{
			String[] tok = in.readLine().split(" ");
			int N = Integer.parseInt(tok[0]);
			int[] j = new int[N];
			double[] m = new double[N];
			double X = 0;
			for (int i = 0; i < j.length; i++)
			{
				j[i] = Integer.parseInt(tok[i+1]);
				X += j[i];
			}
			for (int i = 0; i < N; i++)
			{
				double lo = 0;
				double hi = 1;
				while(hi - lo > 1e-9)
				{
					double mid = (lo+hi)/2;
					if (test(i, N, j, X, mid))
					{
						hi = mid;
					}
					else lo = mid;
				}
				m[i] = lo;
			}
			out.printf("Case #%d:", t+1);
			for (int i = 0; i < N; i++)
			{
				out.printf(" %.6f", 100*m[i]);
			}
			out.println();
		}
		out.close();
	}
	
	static boolean test(int c, int N, int[] j, double X, double p)
	{
		double rr = 1 - p;
		double score = j[c] + X*p;
		for (int i = 0; i < N; i++)
		{
			if (i==c) continue;
			if (j[i] < score)
			{
				rr -= (score - j[i])/X;
			}
		}
		return rr <= 0;
	}
}
