/*
ID: jprakha1
LANG: JAVA
TASK: R1C_1
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
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

/*
public class R1C_1 {

}

 */

public class R1C_1 {
	private static PrintWriter printWriter;

	public void solve() throws FileNotFoundException {
		InputStream inputStream = getClass().getResourceAsStream("R1C_1.in");

		InputHelper inputHelper = new InputHelper(inputStream);

		printWriter = new PrintWriter(new File("R1C_1.out"));

		//actual solution
		int t = inputHelper.readInteger();

		for(int ct = 1; ct <= t; ct++)
		{
			int k = inputHelper.readInteger();
			int l = inputHelper.readInteger();
			int s = inputHelper.readInteger();
			
			String ab = inputHelper.read();
			String tg = inputHelper.read();
			
			bt("", ab, tg, s);
			
			
			double ans = 0.0;
			for(int i = 0; i < al.size(); i++)
			{
				ans += (mc - al.get(i));
			}
			
			printWriter.println("Case #" + ct + ": " + (double)(ans / al.size()));
			
			mc = 0;
			al = new ArrayList<>();
		}

		//end here

		printWriter.close();
	}

	int mc = 0;
	List<Integer> al = new ArrayList<Integer>();
	private void bt(String gs, String ab, String tg, int s) {
		
		if(gs.length() == s)
		{
			int ct = ct(gs, tg);
			mc = Math.max(mc, ct);
			al.add(ct);
		}
		else
		{
			for(int i = 0; i < ab.length(); i++)
			{
				bt(gs + ab.substring(i, i + 1), ab, tg, s);
			}
		}
	}

	private int ct(String gs, String tg) {
		
		int ans = 0;
		for(int i = 0; i < gs.length(); i++)
		{
			if(gs.substring(i, Math.min(i + tg.length(), gs.length())).equals(tg))
			{
				ans++;
			}
		}
		return ans;
	}

	public static void main(String[] args) throws FileNotFoundException {
		(new R1C_1()).solve();
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
