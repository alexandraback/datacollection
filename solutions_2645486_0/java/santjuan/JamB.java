import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class JamB 
{
	
	static int[] vs;
	static Integer[][] dp;
	static int E;
	static int R;
	static int dp(int e, int actual)
	{
		if(dp[e][actual] != null)
			return dp[e][actual];
		if(actual == vs.length)
			return dp[e][actual] = 0;
		int p = dp(Math.min(e + R, E), actual + 1);
		for(int spend = 0; spend <= e; spend++)
			p = Math.max(p, dp(Math.min(e + R - spend, E), actual + 1) + vs[actual] * spend);
		return dp[e][actual] = p;
	}

	public static void main(String[] args) throws FileNotFoundException
	{
		System.setOut(new PrintStream("b-small.out"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int caso = 1; caso <= T; caso++)
		{
			E = sc.nextInt();
			R = sc.nextInt();
			int n = sc.nextInt();
			vs = new int[n];
			for(int i = 0; i < n; i++)
				vs[i] = sc.nextInt();
			dp = new Integer[E + 10][vs.length + 10];
			System.out.println("Case #" + caso + ": " + dp(E, 0));
		}
		sc.close();
	}
}
