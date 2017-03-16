/*
ID: jprakha1
LANG: JAVA
TASK: R1C_3
 */

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

/*
public class R1C_3 {

}

 */

public class R1C_3 {
	private static PrintWriter printWriter;

	public void solve() throws FileNotFoundException {
		InputStream inputStream = getClass().getResourceAsStream("R1C_3.in");

		InputHelper inputHelper = new InputHelper(inputStream);

		printWriter = new PrintWriter(new File("R1C_3.out"));

		//actual solution

		int t = inputHelper.readInteger();

		for(int ct = 1; ct <= t; ct++)
		{
			int c = inputHelper.readInteger();
			int d = inputHelper.readInteger();
			int v = inputHelper.readInteger();

			Set<Integer> si = new HashSet<>();
			Set<Integer> se = new HashSet<>();

			for(int i = 1; i <= v; i++)
			{
				se.add(i);
			}
			for(int i = 0; i < d; i++)
			{
				int ae = inputHelper.readInteger();
				se.remove(ae);
				si.add(ae);
			}

			int ans = 0;

			while(ans <= 4)
			{
				if(poss(d, v, ans, si, se))
				{
					break;
				}

				ans++;

				if(ans > 4)
					break;
			}
			
			printWriter.println("Case #" + ct + ": " + ans);
		}

		//end here

		printWriter.close();
	}


	private boolean poss(int d, int v, int ans, Set<Integer> si, Set<Integer> se) {

		return bt(0, ans, si, se, v, d);
	}


	private boolean bt(int ea, int ans, Set<Integer> si, Set<Integer> se, int v, int d) {

		if(ea == ans)
		{
			if(poss(si, v))
			{
				return true;
			}
		}
		else
		{
			Set<Integer> cs = new HashSet<>(se);
			for (Integer sen : cs) {
				si.add(sen);
				se.remove(sen);
				if(bt(ea + 1, ans, si, se, v, d))
					return true;
				se.add(sen);
				si.remove(sen);
			}
		}
		return false;
	}


	private boolean poss(Set<Integer> si, int v) {
		
		int d = si.size();
		boolean[][] dp = new boolean[v + 1][d + 1];

		for(int i =0; i <= d; i++)
			dp[0][i] = true;
		
		Set<Integer> s = new HashSet<>();
		
		List<Integer> l = new ArrayList<>(si);
		
		for(int i = 1; i <= v; i++)
		{
			for(int j = 1; j <= d; j++)
			{
				if(i >= l.get(j - 1) && dp[i - l.get(j - 1)][j - 1])
					dp[i][j] = true;
				
				if(dp[i][j - 1])
					dp[i][j] = true;
				
				if(dp[i][j])
					s.add(i);
			}
		}
		
		if(s.size() == v)
			return true;

		return false;
	}


	public static void main(String[] args) throws FileNotFoundException {
		(new R1C_3()).solve();
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
