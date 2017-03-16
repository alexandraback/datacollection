package y2016r1C;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer buffer;
	
	public static void solve() throws Exception {
		int T = ni();
		for (int t=0;t<T;t++) {
			int B = ni();
			long M = nl();
			
			long max = (long)(Math.pow(2, B-2));
			if (M>max) {
				out.println("Case #" + (t+1) + ": IMPOSSIBLE");
			} else {
				boolean[][]res = new boolean[B][B];
				if (M==max) {
					res[0][B-1] = true; // 1 -> B
					M--;
				}

				String s = Long.toBinaryString(M);
				
				for (int i=1;i<B-1;i++) {
					for (int j=i+1;j<B;j++) {
						res[i][j] = true;
					}
				}
				
				int pos = B-2;
				for (int i=s.length()-1;i>=0;i--) {
					if (s.charAt(i) == '1') {
						res[0][pos] = true;
					}
					pos--;
				}
				
				out.println("Case #" + (t+1) + ": POSSIBLE");
				for (int i=0;i<B;i++) {
					for (int j=0;j<B;j++) {
						out.print(res[i][j] ? "1":"0");
					}
					out.println();
				}
				
			}
			
		}
	}

	public static void main(String[] args) throws IOException, Exception {
		in = new BufferedReader(new FileReader(new File("/tmp/b1.in")));
		out = new PrintWriter(new FileWriter(new File("/tmp/b1_out.in")));
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
