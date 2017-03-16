package april2013;

import java.io.*;
import java.util.*;

public class TaskB {
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
	
	static int E, R, N;
	static long soln;
	public static void main ( String[] args ) throws IOException {
		//InputReader in = new InputReader(System.in);
		InputReader in = new InputReader("B-small-attempt0.in");
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-small.out")));
		//PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int numTc;
		int[] values;
		
		numTc = in.nextInt();
		
		for (int i = 0; i < numTc; i++) {
			E = in.nextInt();
			R = in.nextInt();
			N = in.nextInt();
			
			values = new int[N];
			for (int j = 0; j < N; j++)
				values[j] = in.nextInt();
			soln = 0;
			solve(values);
			out.println("Case #" + (i+1) + ": " + soln);
		}
		
		in.close();
		out.close();
	}
	
	public static void solve(int[] values) {
		brute(0, E, values, 0);
	}
	
	public static void brute(int curind, int energy, int[] values, long ans) {
		if (energy > E)
			return;
		if (curind == N - 1) {
			 ans += (energy * values[curind]);
			 soln = Math.max(soln, ans);
			 return;
		}
		long tmp;
		
		for (int i = energy; i >= 0; i--) {
			tmp = ans + i * values[curind];
			if (energy - i + R > E)
				break;
			brute(curind + 1, energy - i + R, values, tmp);
		}
	}
}


