package round1B;

import java.io.*;
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
		int numTc, r, n, soln;
		int[] values;
		
		numTc = in.nextInt();
		
		for (int i = 0; i < numTc; i++) {
			r = in.nextInt();
			n = in.nextInt();
			values = new int[n];
			for (int j = 0; j < n; j++)
				values[j] = in.nextInt();
			soln = solve(r, n, values);
			out.println("Case #" + (i+1) + ": " + soln);
		}
		
		in.close();
		out.close();
	}
	
	public static int solve(int r, int n, int[] values) {
		Arrays.sort(values);
		if (r == 1 && values[0] > 0) 
			return n;
		return solve(r, 0, n, values);
	}
	
	public static int solve(int cur, int index, int n, int[] values) {
		if (index == n) {
			return 0;
		}
		
		if (cur > values[index]) {
			return solve(cur + values[index], index + 1, n, values);
		}
		else {
			int ways = 1 + solve(cur, index + 1, n, values);
			int ans = 0, tmp = cur;
			while (tmp <= values[index]) {
				tmp *= 2;
				tmp -= 1;
				ans++;
			}
			int ways2 = ans + solve(tmp + values[index], index + 1, n, values);
			return Math.min(ways, ways2);
		}
	}
}


