
import java.io.BufferedReader;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class R1B_EqualSums {

	static boolean test = true;

	private void solve() throws Throwable {
		int t = iread();
		for (int i = 0; i < t; i++) {
			solveIt(i + 1);
		}
	}

	HashMap<Integer, String> result = null;
	String answer = "";

	private void solveIt(int casenr) throws Throwable {
		result = new HashMap<Integer, String>();
		String ans = "Impossible";

		int n = iread();
		int[] vals = new int[n];
		for (int i = 0; i < n; i++) {
			vals[i] = iread();
		}

		go(vals, 0, vals.length, new boolean[vals.length]);
		if (answer.length() > 0) {
			ans = answer;
		}
		String answerString = "Case #" + casenr + ":\n" + ans;
		out.write(answerString + "\n");
		System.out.println(answerString);
	}

	private void go(int[] vals, int i, int length, boolean[] use) {
		if (i == length) {
			StringBuilder asStr = new StringBuilder();
			int total = 0;
			for (int j = 0; j < use.length; j++) {
				if (use[j]) {
					asStr.append(vals[j] + " ");
					total += vals[j];
				}
				if (asStr.toString().length() > 0) {

					if (result.containsKey(total) && result.get(total).compareTo(asStr.toString()) != 0) {
						answer = result.get(total) + "\n" + asStr.toString();
					} else {
						result.put(total, asStr.toString());
					}
				}

			}
			return;
		}
		use[i] = true;
		go(vals, i + 1, length, use);
		use[i] = false;
		go(vals, i + 1, length, use);

	}

	public int iread() throws Exception {
		return Integer.parseInt(wread());
	}

	public double dread() throws Exception {
		return Double.parseDouble(wread());
	}

	public long lread() throws Exception {
		return Long.parseLong(wread());
	}

	public String wread() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) throws Throwable {
		new R1B_EqualSums().solve();
		out.close();
	}

	public R1B_EqualSums() throws Throwable {
		if (test) {
			in = new BufferedReader(new FileReader(new File(testDataFile)));
			out = new BufferedWriter(new FileWriter(getClass().getCanonicalName() + "-out.txt"));
		} else {
			new BufferedReader(inp);
		}
	}

	static InputStreamReader inp = new InputStreamReader(System.in);
	static BufferedReader in = new BufferedReader(inp);
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	// static BufferedWriter out;// = new BufferedWriter(new FileWriter("out.txt"));

//	static String testDataFile = "testdata.txt";
	static String testDataFile = "C-small-attempt1.in";
	
}