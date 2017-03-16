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
		InputReader in = new InputReader("A-small-attempt0.in");
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt0.out")));
		//PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int numTc, n, soln;
		String name;
		
		numTc = in.nextInt();
		
		for (int i = 0; i < numTc; i++) {
			name = in.next();
			n = in.nextInt();
			soln = solve(name, n);
			out.println("Case #" + (i+1) + ": " + soln);
		}
		
		in.close();
		out.close();
	}
	
	public static int solve(String name, int n) {
		int len = name.length(), ans = 0;
		
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j <= len; j++) {
				if(check(name.substring(i, j), n)) {
					ans++;
				}
			}
		}
		return ans;
	}
	
	public static boolean check(String name, int n) {
		int cnt = 0, len = name.length();
		for (int i = 0; i < len; i++) {
			if (isvowel(name.charAt(i))) {
				cnt = 0;
			}
			else
				cnt++;
			if (cnt == n) {
				return true;
			}
		}
		return false;
	}
	
	public static boolean isvowel(char ch) {
		return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'o';
	}
}


