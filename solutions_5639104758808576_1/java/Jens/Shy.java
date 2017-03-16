import java.awt.Point;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Currency;
import java.util.HashSet;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

/**
 * @author Jens Staahl
 */

public class Shy {

	// some local config
	// static boolean test = false ;
	private boolean test = System.getProperty("ONLINE_JUDGE") == null;
	static String testDataFile = "A-large.in";
	// static String testDataFile = "testdata.txt";
	private static String ENDL = "\n";
	// Just solves the acutal kattis-problem
	ZKattio io;
		
	int cnt = 0, max = 0;
	private void solve() throws Throwable {
		io = new ZKattio(stream);

		int n = io.getInt();
		for (int i = 0; i < n; i++) {
			solveIt(i+1);
			
		}
		out.flush();
	}


	private void solveIt(int casenr) {
		int n = io.getInt();
		String word = io.getWord();
		int totPrev = 0;
		int friendsAdded = 0;
		for (int i = 0; i < word.length(); i++) {
			int cnt = word.charAt(i) -'0';
			if(cnt > 0 && totPrev < i) {
				friendsAdded += i - totPrev;
				totPrev = i;
			}
			totPrev += cnt;
		}

		print("Case #" + casenr + ": " + friendsAdded + "");
	}


	private void print(String string) {
		out.println(string);
		System.out.println(string);
	}


	public static void main(String[] args) throws Throwable {
		new Shy().solve();
	}

	public Shy() throws Throwable {
		if (test) {
			stream = new FileInputStream(testDataFile);
		}
	}

	InputStream stream = System.in;
//	PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));// outStream
	PrintWriter out = new PrintWriter(new File(this.getClass().getCanonicalName() + ".out")); //new OutputStreamWriter(System.out));// outStream

	public class ZKattio extends PrintWriter {
		public ZKattio(InputStream i) {
			super(new BufferedOutputStream(System.out));
			r = new BufferedReader(new InputStreamReader(i));
		}

		public ZKattio(InputStream i, OutputStream o) {
			super(new BufferedOutputStream(o));
			r = new BufferedReader(new InputStreamReader(i));
		}

		public boolean hasMoreTokens() {
			return peekToken() != null;
		}

		public int getInt() {
			return Integer.parseInt(nextToken());
		}

		public double getDouble() {
			return Double.parseDouble(nextToken());
		}

		public long getLong() {
			return Long.parseLong(nextToken());
		}

		public String getWord() {
			return nextToken();
		}

		private BufferedReader r;
		private String line;
		private StringTokenizer st;
		private String token;

		private String peekToken() {
			if (token == null)
				try {
					while (st == null || !st.hasMoreTokens()) {
						line = r.readLine();
						if (line == null)
							return null;
						st = new StringTokenizer(line);
					}
					token = st.nextToken();
				} catch (IOException e) {
				}
			return token;
		}

		private String nextToken() {
			String ans = peekToken();
			token = null;
			return ans;
		}
	}
	// System.out;

}