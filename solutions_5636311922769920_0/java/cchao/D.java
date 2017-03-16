import java.io.*;
import java.util.*;
import java.math.*;
public class D {
	void solve() {
		int T = in.nextInt();
		for(int kase = 1; kase <= T; ++kase) {
			int K = in.nextInt();
			int C = in.nextInt();
			int S = in.nextInt();
			out.printf("Case #%d: ", kase);
			if(S * C < K) {
				out.println("IMPOSSIBLE");
			}
			else {
				for(int i = 0; i < K; i += C) {
					BigInteger x = BigInteger.ZERO;
					for(int j = 0; j < C && i + j < K; ++j) {
						x = x.multiply(BigInteger.valueOf(K)).add(BigInteger.valueOf(i + j));
					}
					out.print(" " + x.add(BigInteger.ONE));
				}
				out.println("");
			}
		}
	}
	class InputReader {
		StringTokenizer tok; BufferedReader buf;
		InputReader(String file) {
			try {
				buf = new BufferedReader(new FileReader(file));
			} catch(FileNotFoundException e) { e.printStackTrace(); }
		}
		InputReader() {
			buf = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while(tok == null || !tok.hasMoreElements()) {
				try {
					String s = buf.readLine();
					if(s == null) {  return null; }
					tok = new StringTokenizer(s);
				} catch(IOException e) { return null; }
			}
			return tok.nextToken();
		}
		boolean hasNext() {
			while(tok == null || !tok.hasMoreElements()) {
				try {
					String s = buf.readLine();
					if(s == null) {return false; }
					tok = new StringTokenizer(s);
				} catch(IOException e) { return false; }
			}
			return true;
		}
		int nextInt() { return Integer.parseInt(next()); }
		long nextLong() { return Long.parseLong(next()); }
		double nextDouble() { return Double.parseDouble(next()); }
		BigInteger nextBigInteger() { return (new BigInteger(next())); }
	}
	InputReader in; PrintWriter out;
	void runFile(String task) {
		try {
			in = new InputReader(task + ".in");
			out = new PrintWriter(task + ".out");
		} catch(IOException e) {
			e.printStackTrace();
		}
		solve(); out.close();
	}
	void run() {
		in = new InputReader();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}
	public static void main(String[] args) { new D().run(); }
}
