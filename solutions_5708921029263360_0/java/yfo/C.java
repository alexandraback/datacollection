package y2016r1C;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class C {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer buffer;
	
	public static class Triple {
		int a,b,c;
		public Triple(int a, int b, int c) {
			this.a = a;
			this.b = b;
			this.c = c;
		}
	}
	
	public static void solve() throws Exception {
		int T = ni();
		for (int t=0;t<T;t++) {
			int J = ni(), P = ni(), S = ni(), K = ni();
			
			int[][] used12 = new int[J][P];
			int[][] used13 = new int[J][S];
			int[][] used23 = new int[P][S];			
			
			List<Triple> res = new ArrayList<>();
			int last3 = -1;
			
			for (int j=0;j<J;j++) {
				for (int p=0;p<P;p++) {
					if (used12[j][p]>=K) continue;
					
					for (int x=0;x<Math.min(K, S);x++) {
						int next3 = (last3+1)%S;
						
						if (used12[j][p]<K && used13[j][next3]<K && used23[p][next3]<K) {
							last3 = next3;
							res.add(new Triple(j+1, p+1, next3+1));
							used12[j][p]++;
							used13[j][next3]++;
							used23[p][next3]++;
						}
						
					}
				}
			}
			
			out.println("Case #" + (t+1) + ": " + res.size());
			for (Triple tr: res) {
				out.println(tr.a + " " + tr.b + " " + tr.c);
			}
			
		}
	}

	public static void main(String[] args) throws IOException, Exception {
		in = new BufferedReader(new FileReader(new File("/tmp/c1.in")));
		out = new PrintWriter(new FileWriter(new File("/tmp/c1_out.in")));
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
