package y2016r1A;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class B {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer buffer;
	
	public static void solve() throws Exception {
		int T = ni();
		for (int t=0;t<T;t++) {
			int N = ni();
			int[]all = new int[2520];
			for (int i=0;i<(2*N-1)*N;i++) all[ni()]++;
			List<Integer>res = new ArrayList<Integer>();
			for (int i=0;i<all.length;i++) {
				if(all[i]%2!=0) res.add(i);
			}
			Collections.sort(res);
			
			out.print("Case #"+(t+1)+": ");
			for (Integer i: res) out.print(i + " ");
			out.println();
		}
		
	}

	public static void main(String[] args) throws IOException, Exception {
		in = new BufferedReader(new FileReader(new File("/tmp/b2.in")));
		out = new PrintWriter(new FileWriter(new File("/tmp/b2_out.in")));
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
