import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
	TreeSet<String> vis;
	Random rng;
	boolean gen(int n) {
		int digits[] = new int[n];
		int witness[] = new int[12];
		digits[0] = digits[n - 1] = 1;
		for(int i = 2; i < n - 1; ++i) {
			digits[i] = rng.nextInt(2);
		}
		String s = "";
		for(int i = 0; i < n; ++i)
			s = s + digits[i];

		if(vis.contains(s))
			return false;
		vis.add(s);

		for(int base = 2; base <= 10; ++base) {
			BigInteger num = BigInteger.ZERO;
			for(int i = 0; i < n; ++i) {
				num = num.multiply(BigInteger.valueOf(base)).add(BigInteger.valueOf(digits[i]));
			}
			for(int i = 2; i < 5566; ++i) {
				if(num.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO)) {
					witness[base] = i;
					break;
				}
			}
			if(witness[base] == 0)
				return false;
		}
		out.print(s);
		for(int base = 2; base <= 10; ++base) {
			out.print(" " + witness[base]);
		}
		out.println("");

		return true;
	}

	void solve() {
		vis = new TreeSet<String>();
		rng = new Random();
		out.println("Case #1:");
		int n = 16, j = 50;
		while(j > 0) {
			if(gen(n))
				j--;
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
	public static void main(String[] args) { new Main().run(); }
}
