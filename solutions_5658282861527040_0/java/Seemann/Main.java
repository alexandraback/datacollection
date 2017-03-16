import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		try {
			inputStream = new FileInputStream("a.in");
			outputStream = new FileOutputStream("a.out");
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			out.format("Case #%d: ", i + 1);
			Solver solver = new Solver();
			solver.solve(in, out);
		}
		out.close();
	}
}

class Solver {
	int start(int a, int p) {
		if (p < 0)
			return a;
		return a & (~((1 << (p + 1)) - 1));
	}
	long find1(int p, int a, int k) {
		long ans = 0;
		long m = 1;
		for (p--; p >= 0; p--) {
			if ((a & (1 << p)) == 0) { 
				m *= 2;
			} else {
				int sa = start(a, p);
				int sk = start(k, p - 1);
				System.err.format("%d %d\n", sa, sk);
				if (sa < sk)
					ans += 3 * m * (1 << p);
				else if (sa == sk) {
					ans += 3 * m * find(p, k & ((1 << p) - 1));
				}
				//System.err.println(find(1, 1));
				System.err.println(ans);
			}
		}
		return ans;
	}
	long find(int p, int k) {
		long ans = 0;
		long m = 1;
		while (p >= 0) {
			while (p >= 0 && ((1 << p) & k) == 0) {
				m *= 3;
				p--;
			}
			if (p < 0)
				break;
			ans += m * (((long)1) << (2 * p));
			p--;
		}
		return ans;
	}
	int end(int a, int p) {
		return (a | ((1 << p) - 1));
	}
	public void solve(InputReader in, PrintWriter out) {
		//System.err.println(find1(2, 3, 1));
		int a = in.nextInt();
		int b = in.nextInt();
		int k = in.nextInt();
		long ans = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if ((i & j) < k)
					ans++;
			}
		}
		/*
		long m = 1;
		for (int p = 30; p >= 0; p--) {
			if ((k & (1 << p)) == 0) {
				
			} else {
				int s = start(k, p);
				int sa = start(a, p - 1);
				int sb = start(b, p - 1);
				long cur = 1;
				if (sa == s) { 
					cur *= end(a, p);
					
				} else if (sa > s) {
					cur *= (1 << p);
				}
			}
		}
		for (int p = 30; p >= 0; p--) {
			
			if (((a & (1 << p)) == 0) && ((b & (1 << p)) == 0)) {
				
			} else if (((a & (1 << p)) == 0) || ((b & (1 << p)) == 0)) {
				int w = a;
				if ((b & (1 << p)) == 0)
					w = b;
				ans += m * find1(p, w & ((1 << p) - 1), k & ((1 << p) - 1));
				m *= 2;
			} else {
				int sa = start(a, p);
				int sb = start(b, p);
				int s = sa & sb;
				int sk = start(k, p - 1);
				if (s < sk){
					ans += m *(((long)1) << (2*p));
				} else if (s > sk) { 
					ans += 0;
				} else {
					ans += m * find(p, k & ((1 << p) - 1));
				}
			}
		}*/
		out.println(ans);
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
