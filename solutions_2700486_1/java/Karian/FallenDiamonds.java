import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class FallenDiamonds {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// open file and create a buffered reader
		FileReader input = new FileReader(args[0]);
		BufferedReader buffer = new BufferedReader(input);
		
		//read the number of testcases
		int max = Integer.parseInt(buffer.readLine().trim());
		
		// read a line and call the solving procedure for a single test case.  We expect back the result as a string
		for (int i = 1; i <= max; i++) {
			System.out.println("Case #"+i+": " + solve(buffer.readLine()));
		}

	}

	private static double solve(String input) {
		String[] split = input.split("\\s+");
		long N = Long.parseLong(split[0]);
		long X = Long.parseLong(split[1]);
		if (X < 0)
			X = -X;
		long Y = Long.parseLong(split[2]);

		long place = X + Y;
		long min = (place) * (place - 1) / 2;
		long max = (place + 1) * (place + 2) / 2;
		
		if(N <= min)
			return 0;
		if(N >= max)
			return 1;
		if(X == 0 && N < max)
			return 0;
		long drops = N - min;
		if (Y > drops)
			return 0;
		long oneSide = (max - min) / 2;
		if(drops > oneSide + Y)
			return 1;
		
		return 1.0 - Math.pow(0.5, drops) * binomSum(drops,Y);
	}
	
	public static double binomSum(long n, long m)
	{
		int max = (int) n;
		double[] b = new double[max + 1];
		b[0] = 1;
		for (int i = 1; i <= max; i++)
		{
			b[i] = 1;
			for (int j = i - 1; j > 0; j--)
			{
				b[j] += b[j-1];
			}
		}
		long total = 0;
		for (int i=0; i <= (int)m; i++)
		{
			total += b[i];
		}
		
		return total;
	}
	
}
