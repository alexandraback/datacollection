package april2013;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class TaskA {
	static class InputReader {
		BufferedReader bin;
		StringTokenizer tokenizer;
		
		public InputReader(InputStream in) {
			bin = new BufferedReader(new InputStreamReader(in));
			tokenizer = null;
		}
		
		public InputReader(String fname) {
			try {
				bin = new BufferedReader(new FileReader(fname));
				tokenizer = null;
			} catch (Exception e) {
				throw new RuntimeException(e);
			}
		}
		
		public String next() {
			
			while( tokenizer == null || !tokenizer.hasMoreTokens())  {
				try {
					tokenizer = new StringTokenizer(bin.readLine());
				} catch(IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		
		public String readLine() {
			try {
				return bin.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		
		public float nextFloat() {
			return Float.parseFloat(next());
		}
		
		public void close() {
			try {
				bin.close();
				tokenizer = null;
			} catch ( IOException e) {
				throw new RuntimeException(e);
			}
		}
	}
	
	public static void main ( String[] args ) throws IOException {
		//InputReader in = new InputReader(System.in);
		InputReader in = new InputReader("A-large.in");
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-large.out")));
		//PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int numTc;
		long r, t, soln;
		
		numTc = in.nextInt();
		
		for (int i = 0; i < numTc; i++) {
			r = in.nextLong();
			t = in.nextLong();
			soln = solve(r, t);
			out.println("Case #" + (i+1) + ": " + soln);
		}
		
		in.close();
		out.close();
	}
	
	public static long solve(long r, long t) {
		double min, max, mid, expr, ans = 1;
		max = (long)Math.sqrt(t);
		min = 1;
		
		while (max >= min) {
			mid = (long)(min + (max - min) / 2);
			expr = (2 * r + 2 * mid) - 1;
			expr *= mid;
			
			if (expr < t) {
				min = mid + 1;
				ans = mid;
				continue;
			}
			if (expr > t) {
				max = mid - 1;
				continue;
			}
			ans = mid;
			break;
		}
		
		return (long)ans;
	}
}


