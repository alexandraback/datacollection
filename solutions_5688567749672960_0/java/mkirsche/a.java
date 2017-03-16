import java.util.*;
public class a {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t =  1; t<=T; t++)
	{
		System.out.print("Case #"+t+": ");
		long n = input.nextLong();
		long[] dp = new long[(int)n+1];
		Arrays.fill(dp, n+1);
		dp[0] = 0;
		for(int i = 0; i<n; i++)
		{
			long cur = dp[i]+1;
			dp[i+1] = Math.min(dp[i+1], cur);
			long other = rev(i);
			if(other <= n)
				dp[(int)other] = Math.min(dp[(int)other], cur);
		}
		System.out.println(dp[(int)n]);
		
	}
}
static long rev(long x)
{
	long res = 0;
	while(x > 0)
	{
		res *= 10;
		res += x%10;
		x /= 10;
	}
	return res;
}
}
