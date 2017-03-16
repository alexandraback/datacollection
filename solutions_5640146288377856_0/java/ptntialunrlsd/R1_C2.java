/*
ID: jprakha1
LANG: JAVA
TASK: R1_C2
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
public class R1_C2 {

}

 */

public class R1_C2 {
	private static PrintWriter printWriter;

	public void solve() throws FileNotFoundException {
		InputStream inputStream = getClass().getResourceAsStream("R1_C2.in");

		InputHelper inputHelper = new InputHelper(inputStream);

		printWriter = new PrintWriter(new File("R1_C2.out"));

		//actual solution
		
		int t = inputHelper.readInteger();
		
		for(int ct = 1; ct <= t; ct++)
		{
			int r = inputHelper.readInteger();
			int c = inputHelper.readInteger();
			int w = inputHelper.readInteger();
			
			if(c % w == 0)
			{
				printWriter.println("Case #" + ct + ": " + (int)((c / w) + (w - 1)));
			}
			else
			{
				printWriter.println("Case #" + ct + ": " + (int)((c / w) + w));
			}
		}

		//end here

		printWriter.close();
	}

	public static void main(String[] args) throws FileNotFoundException {
		(new R1_C2()).solve();
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
