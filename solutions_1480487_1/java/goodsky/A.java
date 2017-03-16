import java.util.*;
public class A {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for (int t = 1; t <= T; ++t)
		{
			int N = in.nextInt();
			int[] val = new int[N];
			int sum = 0;
			
			for (int n = 0; n < N; ++n)
			{
				val[n] = in.nextInt();
				sum += val[n];
			}
			
			double minval = (sum*2.0)/N;
			int largerval = 0;
			int largercount = 0;
			for (int n = 0; n < N; ++n)
			{
				if (val[n] >= minval-1e-6)
				{
					largerval += val[n];
					largercount++;
				}
			}
			
			// update minval
			minval = (double)(sum*2.0 - largerval)/(N - largercount);

			System.out.printf("Case #%d: ", t);
			for (int n = 0; n < N; ++n)
			{
				if (val[n] >= minval-1e-6)
					System.out.printf("0.0 ");
				else 
				{
					double needed = (minval - val[n]);
					System.out.printf("%.6f ", (needed/sum)*100.0);
				}
			}
			System.out.println();
		}
	}
}

/*
6
2 20 10
2 10 0
4 25 25 25 25
3 24 30 21
4 41 40 0 0
4 20 15 0 0 
*/
