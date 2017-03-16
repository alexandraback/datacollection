import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;


public class A {

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		// BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		// int numCases = Integer.parseInt(r.readLine());
		
		Scanner s = new Scanner(System.in);
		int numCases = s.nextInt();
		
		int max = 1000003;
		long[] dp = new long[max];
		dp[1] = 1;
		dp[2] = 2;
		for(int i = 3; i < max; ++i)
		{
			long first = dp[i-1] + 1;
			long index = invert(i);
			long second = 0;
			if(index >= 1 && index < i)
			{
				second = dp[(int)index]+1;
			}
			if(second > 1 && second < first)
			{
				dp[i] = second;
			}else
			{
				dp[i] = first;
			}
		}
		
		
		for(int numC = 0; numC < numCases; ++numC)
		{
			
			long n = s.nextLong();
			
			
			System.out.print("Case #");
			System.out.print(numC+1);
			System.out.print(": ");
			System.out.println(dp[(int)n]);
		}

	}
	
	static long invert(long num)
	{
		char[] test = String.valueOf(num).toCharArray();
		long res = 0;
		long mult = 1;
		for(int i = 0; i < test.length; ++i)
		{
			int tmp = Integer.valueOf(String.valueOf(test[i]));
			if(i == test.length-1 && tmp == 0)
			{
				// es darf kein digit verloren gehen...
				res += 10000000000L;
			}
			res += tmp * mult;
			mult *= 10;
		}
		return res;
	}
}
