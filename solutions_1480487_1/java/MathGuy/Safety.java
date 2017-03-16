package safety;

import java.io.BufferedReader;
import java.io.FileReader;

public class Safety 
{	
	public static double EPS = 1e-10;
	
	public static boolean test(int I, int X, int[] scores, double remaining, double toBeat)
	{
		int N = scores.length;
		double requiredVotes = 0;
		for (int j = 0; j < N; ++j)
		{
			if (j == I) continue;
			if (scores[j] > toBeat - EPS) continue;
			requiredVotes += (toBeat - scores[j])/X;
		}
		return remaining < requiredVotes - EPS;
	}	

	public static double binSearch(int i, int X, int[] scores) 
	{
		double low = 0, high = 1, guess = .5;
		for (int n = 0; n < 200; ++n) {
			guess = (high + low)/2;
			boolean works = test(i,X,scores,1-guess,scores[i] + X*guess);
			if (works)
			{
				high = guess;
			}
			else
			{
				low = guess;
			}
		}
		return guess; 
	}
	
	public static double[] solve(int[] scores) 
	{
		int N = scores.length;
		double[] ret = new double[N];
		int X = 0;
		for (int i = 0; i < N; ++i) X += scores[i];			
		for (int i = 0; i < N; ++i)
		{
			ret[i] = binSearch(i,X,scores);
		}
		return ret;
	}
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		String line = in.readLine();
		int T = Integer.parseInt(line);
		for (int i = 0; i < T; ++i) 
		{
			line = in.readLine();
			String[] toks = line.split(" ");
			int N = Integer.parseInt(toks[0]);
			int[] scores = new int[N];
			for (int j = 0; j < N; ++j) 
			{
				scores[j] = Integer.parseInt(toks[j+1]);
			}
			double[] ret = solve(scores);
			System.out.print("Case #"+(i+1)+": ");
			for (int j = 0; j < N; ++j) 
			{
				if (j > 0) System.out.print(" ");
				System.out.print(ret[j]*100.0);
			}
			System.out.println();
		}
	}
}
