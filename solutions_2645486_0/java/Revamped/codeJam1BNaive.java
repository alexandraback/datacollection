import java.util.*;
import java.math.BigInteger;

public class codeJam1BNaive
{
	static int values[];
	static int maxE;
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		
		for(int testNo = 1; testNo <= test; testNo++)
		{
			int e = sc.nextInt();
			maxE = e;
			int r = sc.nextInt();
			int n = sc.nextInt();
			
			values = new int[n];
			for(int i = 0; i < n; i++)
			{
				values[i] = sc.nextInt();
			}
			int max = (int)Math.pow(e+1, n);
			
			System.out.printf("Case #%d: %s\n", testNo, recurse(0, e, r, 0));
		}
	}
	
	public static int recurse(int position, int e, int r, int gain)
	{
		if (position >= values.length)
			return gain;
		int max = gain;
		for(int i = 0; i <= e; i++)
		{
			max = Math.max(max, recurse(position+1, Math.min((e-i)+r, maxE), r,gain + (i * values[position])));
		}
		return max;
	}
}