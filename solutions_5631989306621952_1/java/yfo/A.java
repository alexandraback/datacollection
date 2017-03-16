package y2016r1A;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer buffer;
	
	public static void solve() throws Exception {
		int T = ni();
		for (int t=0;t<T;t++) {
			char[]s = ns().toCharArray();
			StringBuilder sb = new StringBuilder();
			for (int i=0;i<s.length;i++) {
				if (i==0) sb.append(s[i]);
				else {
					char first = sb.charAt(0), last = sb.charAt(sb.length()-1);
					if (s[i]>=first) sb.insert(0, s[i]);
					else sb.append(s[i]);
				}
			}			
			
			out.println("Case #"+(t+1)+": " + sb.toString());
		}
		
	}

	public static void main(String[] args) throws IOException, Exception {
		in = new BufferedReader(new FileReader(new File("/tmp/a1.in")));
		out = new PrintWriter(new FileWriter(new File("/tmp/a1_out.in")));
		solve();
		out.close();
	}

	static String next() {
		while (buffer == null || !buffer.hasMoreElements()) {
			try {
				buffer = new StringTokenizer(in.readLine());
			} catch (IOException e) {
			}
		}
		return buffer.nextToken();
	}

	static int ni() {
		return Integer.parseInt(next());
	}

	static long nl() {
		return Long.parseLong(next());
	}

	static double nd() {
		return Double.parseDouble(next());
	}

	static String ns() {
		return next();
	}

	static int[] ni(int n) {
		int[] res = new int[n];
		for (int i = 0; i < n; i++)
			res[i] = Integer.parseInt(next());
		return res;
	}

	static long[] nl(int n) {
		long[] res = new long[n];
		for (int i = 0; i < n; i++)
			res[i] = Long.parseLong(next());
		return res;
	}

	static double[] nd(int n) {
		double[] res = new double[n];
		for (int i = 0; i < n; i++)
			res[i] = Double.parseDouble(next());
		return res;
	}

	static String[] ns(int n) {
		String[] res = new String[n];
		for (int i = 0; i < n; i++)
			res[i] = next();
		return res;
	}
}
