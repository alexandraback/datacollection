/*
ID: jprakha1
LANG: JAVA
TASK: R1_1
 */


import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/*
public class R1_1 {

}

 */

public class R1_1 {
	private static PrintWriter printWriter;

	int[] dp;
	long l = -1;
	
	public void solve() throws FileNotFoundException {
		InputStream inputStream = getClass().getResourceAsStream("R1_1.in");

		InputHelper inputHelper = new InputHelper(inputStream);

		printWriter = new PrintWriter(new File("R1_1.out"));

		//actual solution
		int t = inputHelper.readInteger();
		
		for(int ct = 1; ct <= t; ct++)
		{
			long n = inputHelper.readLong();
			
			dp = new int[(int)n * 10 + 1];
			
			for(int i = 0; i <= n * 10; i++)
			{
				dp[i] = -1;
			}
			
			dp[0] = 0;
			dp[1] = 1;
			
			l = Math.max(n, rev(n));
			
			printWriter.println("Case #" + ct + ": " + rec(n));
			
			//System.out.println("hh");
		}

		//end here

		printWriter.close();
	}

	private int rec(long n) {
		
		int n1 = (int) n;
		if(dp[n1] != -1)
			return dp[n1];
		
		dp[n1] = 10000007;
		
		if(n % 10 == 0)
		{
			dp[n1] = rec(n - 1) + 1;
		}
		else
		{
			long rn = rev(n);
			
			if(rn == n)
			{
				dp[n1] = rec(n - 1) + 1;
				
				if(rn * 10 <= l)
				{
					dp[n1] = Math.min(rec(rn * 10) + 1, dp[n1]);
				}
			}
			else
			{
				dp[n1] = rec(n - 1) + 1;
				
				if(rn <= l)
				{
					dp[n1] = Math.min(rec(rn) + 1, dp[n1]);
				}
				if(rn * 10 <= l)
				{
					dp[n1] = Math.min(rec(rn * 10) + 1, dp[n1]);
				}
			}
		}
		
		return dp[n1];
	}

	private long rev(long n) {
		long rn = 0;
		
		while(n > 0)
		{
			rn = rn * 10 + (n % 10);
			n /= 10;
		}
		
		return rn;
	}

	public static void main(String[] args) throws FileNotFoundException {
		(new R1_1()).solve();
	}

	class InputHelper {
		StringTokenizer tokenizer = null;
		private BufferedReader bufferedReader;

		public InputHelper(InputStream inputStream) {
			InputStreamReader inputStreamReader = new InputStreamReader(
					inputStream);
			bufferedReader = new BufferedReader(inputStreamReader, 16384);
		}

		public String read() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					String line = bufferedReader.readLine();
					if (line == null) {
						return null;
					}
					tokenizer = new StringTokenizer(line);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}

			return tokenizer.nextToken();
		}

		public Integer readInteger() {
			return Integer.parseInt(read());
		}

		public Long readLong() {
			return Long.parseLong(read());
		}
	}
}
