import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	static int[] list;
	
	static int[][] dp;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("a.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d: ", casenum);
			int me = readInt();
			int n = readInt();
			dp = new int[n+1][1000001];
			list = new int[n];
			for(int i = 0; i < n; i++)	{
				list[i] = readInt();
			}
			Arrays.sort(list);
			for(int i = 0; i <= n; i++)	{
				Arrays.fill(dp[i], 10000);
			}
			pw.println(solve(me, 0));
		}
		pw.close();
	}

	private static int solve(int me, int i) {
		if(i == list.length)	{
			return 0;
		}
		if(me > dp[i].length)	{
			return 0;
		}
		if(dp[i][me] < 10000)	{
			return dp[i][me];
		}
		if(me > list[i])	{
			return dp[i][me] = solve(me+list[i], i+1);
		}
		if(me == 1)	{
			return dp[i][me] = 1 + solve(me, i+1);
		}
		return dp[i][me] = 1 + Math.min(solve(2*me-1, i), solve(me, i+1));
	}

	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}

	public static String readLine() throws IOException	{
		st = null;
		return br.readLine();
	}


}
