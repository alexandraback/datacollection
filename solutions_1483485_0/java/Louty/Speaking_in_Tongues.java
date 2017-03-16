/*
ID: yourID
LANG: JAVA
TASK: Speaking_in_Tongues
*/
import java.io.*;
import java.math.*;
import java.util.*;
/*public class Speaking_in_Tongues {

}
 */
public class Speaking_in_Tongues implements Runnable {
	// based on Petr's template
	boolean localDebug = false;
	char[] mapping;
	private void solve() throws IOException {
		String in = this.nextLine();
		char[] out = in.toCharArray();
		for ( int i = 0; i < out.length; i ++ )
			if ( out[i] != ' ' )
				out[i] = mapping[ out[i] - 'a' ];
		writer.println( out );
	}

	public static void main(String[] args) {
		new Speaking_in_Tongues().run();
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
						"A-small-attempt0.out")));
				reader = new BufferedReader(new FileReader(
						"A-small-attempt0.in"));
			}
			tokenizer = null;
			initialize();
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

	char[] avail;
	private void initialize() {
		// TODO Auto-generated method stub
		mapping = new char[26];
		avail = new char[26];
		init( "ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand" );
		init( "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities" );
		init( "de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up" );
		mapping[ 'q' - 'a' ] = 'z';
		mapping[ 'z' - 'a' ] = 'q';
	}

	private void init(String in, String out ) {
		// TODO Auto-generated method stub
		for ( int i = 0; i < in.length(); i ++ )
			if ( in.charAt(i) != ' ' ){
				mapping[ in.charAt(i) - 'a' ] = out.charAt(i);
				avail[ out.charAt(i) - 'a' ] = 1;
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