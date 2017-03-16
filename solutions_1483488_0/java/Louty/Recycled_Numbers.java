/*
ID: yourID
LANG: JAVA
TASK: Recycled_Numbers
*/
import java.io.*;
import java.math.*;
import java.util.*;
/*public class Recycled_Numbers {

}
 */
public class Recycled_Numbers implements Runnable {
	// based on Petr's template
	boolean localDebug = false;

	private void solve() throws IOException {
		int a = this.nextInt();
		int b = this.nextInt();
		int mul = 1;
		while( mul * 10 <= a )
			mul *= 10;
		int res = 0;
		for ( int i = a; i < b; i ++ ){
			int m = i;
			HashSet< Integer > exist = new HashSet< Integer >();
			for ( int j = 1; j < mul; j *= 10 ){
				m = ( m % 10 ) * mul + m / 10;
				if ( m > i && m <= b && !exist.contains( m ) ){
					exist.add( m );
					res ++;
				}
			}
		}
		writer.println( res );
	}

	public static void main(String[] args) {
		new Recycled_Numbers().run();
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
						"C-small-attempt0.out")));
				reader = new BufferedReader(new FileReader(
						"C-small-attempt0.in"));
			}
			tokenizer = null;
			int t = this.nextInt();
			for (int i = 1; i <= t; i++) {
				writer.print("Case #" + i + ": ");
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