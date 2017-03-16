/*
ID: yourID
LANG: JAVA
TASK: Dancing_With_the_Googlers
*/
import java.io.*;
import java.math.*;
import java.util.*;
/*public class Dancing_With_the_Googlers {

}
 */
public class Dancing_With_the_Googlers implements Runnable {
	// based on Petr's template
	boolean localDebug = false;

	private void solve() throws IOException {
		int n = this.nextInt();
		int s = this.nextInt();
		int p = this.nextInt();
		int res = 0;
		for ( int i = 0; i < n; i ++ ){
			int in = this.nextInt();
			if ( in >= p * 3 - 2 ){
				res ++;
				continue;
			}
			if ( p < 2 )
				continue;
			if ( in >= p * 3 - 4 && s > 0 ){
				res ++;
				s --;
			}
		}
		writer.println( res );
	}

	public static void main(String[] args) {
		new Dancing_With_the_Googlers().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			if (localDebug) {
				reader = new BufferedReader(new InputStreamReader(System.in));
				writer = new PrintWriter(new OutputStreamWriter(System.out));
			} else {
				writer = new PrintWriter(new BufferedWriter(new FileWriter(
						"B-large.out")));
				reader = new BufferedReader(new FileReader(
						"B-large.in"));
			}
			tokenizer = null;
			int t = this.nextInt();
			for ( int i = 1; i <= t; i ++ ){
				writer.print( "Case #" + i + ": " );
				solve();
			}
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	boolean hasNext() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			String nextLine = reader.readLine();
			if (nextLine == null)
				return false;
			tokenizer = new StringTokenizer(nextLine);
		}

		return true;
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	String nextLine() throws IOException {
		return reader.readLine();
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}

		return tokenizer.nextToken();
	}

	BigInteger nextBigInteger() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}

		return new BigInteger(tokenizer.nextToken());
	}
}