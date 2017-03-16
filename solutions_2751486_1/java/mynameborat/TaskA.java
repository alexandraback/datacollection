package round1C;

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
		int numTc, n;
		long soln;
		String name;
		
		numTc = in.nextInt();
		
		for (int i = 0; i < numTc; i++) {
			name = in.next();
			n = in.nextInt();
			soln = count(name, n);
			out.println("Case #" + (i+1) + ": " + soln);
		}
		
		in.close();
		out.close();
	}
	
	public static long count(String name, int n) {
		int cnt = 0, len = name.length();
		long ans = 0, last = 0;
		
		for (int i = 0; i < len; i++) {
			cnt = isvowel(name.charAt(i)) ? 0 : cnt + 1;
			if (cnt >= n) {
				ans += i - n + 2;
				last = i - n + 2;
			}
			else
				ans += last;
		}
		
		return ans;
	}
	
	public static boolean isvowel(char ch) {
		return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'o';
	}
}


