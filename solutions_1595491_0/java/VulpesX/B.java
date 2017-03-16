import java.util.*;

public class B
{
	static int[] a;
	static int[][] dp;
	static int n, s, p;

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();
		for(int ca=1;ca <= T;ca++)
		{
			n = scan.nextInt();
			s = scan.nextInt();
			p = scan.nextInt();
			a = new int[n];
			for(int i=0;i < n;i++)
				a[i] = scan.nextInt();

			dp = new int[n][s+1];
			for(int i=0;i < n;i++)
				Arrays.fill(dp[i], -1);

			System.out.println("Case #" + ca + ": " + f(0, s));
		}
		
	}


	public static int f(int K, int S)
	{
		if(K == n) return S == 0 ? 0 : -999999;
		if(dp[K][S] != -1) return dp[K][S];

		int rtn = 0;

		boolean[] b = new boolean[4]; //nobeat nosup, nobeat sup, beat nosup, beat sup

		for(int i=0;i <= 10;i++)
		for(int j=0;j <= i;j++)
		{
			if(i+j > a[K]) continue;
			int k = a[K] - (i+j);
			if(k > j) continue;

			if(i-k > 2) continue;

			//System.out.println(i + " " + j + " " + k + " " + a[K]);

			if(i >= p && i-k == 2) b[3] = true;
			if(i >= p && i-k < 2) b[2] = true;
			if(i < p && i-k == 2) b[1] = true;
			if(i < p && i-k < 2) b[0] = true;
		}


		if(S == 0 && !b[0] && !b[2]) return -999999;
		if(S > 0 && b[1]) rtn = Math.max(rtn, f(K+1, S-1));
		if(S > 0 && b[3]) rtn = Math.max(rtn, f(K+1, S-1)+1);
		if(b[0]) rtn = Math.max(rtn, f(K+1, S));
		if(b[2]) rtn = Math.max(rtn, f(K+1, S)+1);

		//System.out.println(K + " " + S + " " + rtn);
		return dp[K][S] = rtn;
		

	}
}