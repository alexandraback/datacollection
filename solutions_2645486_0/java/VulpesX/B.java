import java.util.*;
import java.math.*;

public class B
{
	static int[][] dp;
	static int[] v;
	static int E, R, N;

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();

		for(int ca=1;ca <= T;ca++)
		{
			E = scan.nextInt();
			R = scan.nextInt();
			N = scan.nextInt();

			dp = new int[N][E+1];
			v = new int[N];

			for(int i=0;i < N;i++)
				v[i] = scan.nextInt();

			System.out.println("Case #" + ca + ": " + f(0, E));
		}
	}

	public static int f(int k, int e)
	{
		if(k == N) return 0;
		if(dp[k][e] > 0) return dp[k][e];

		int rtn = 0;

		for(int i=0;i <= e;i++)
		{
			int subrtn = v[k] * i + f(k+1, Math.min(E, e-i+R));
			rtn = Math.max(rtn, subrtn);
		}

		return dp[k][e] = rtn;
	}
}